//
// Created by sun on 2021/2/24.
//

#include <memory>
#include <chrono>
#include <unistd.h>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "a1_msgs/srv/state.hpp"


using namespace std::chrono_literals;

class PubNode : public rclcpp::Node {
public:
    PubNode() : Node("pub_node"), count_(0) {
        walk_pub = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
        timer_ = this->create_wall_timer(500ms, std::bind(&PubNode::pub_callback, this));
        timer_c = this->create_wall_timer(2000ms, std::bind(&PubNode::client_node, this));
    }
    int client_node();
private:
    void pub_callback() {
        geometry_msgs::msg::Twist msg;
        msg.linear.x = 0.1;
        msg.linear.y = 0.0;
        msg.angular.z = 0.0;
        RCLCPP_INFO(this->get_logger(), "sending");
        walk_pub->publish(msg);
    }
    rclcpp::TimerBase::SharedPtr timer_c;
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr walk_pub;
    size_t count_;
};

int PubNode::client_node()
{
    std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("server_client");
    rclcpp::Client<a1_msgs::srv::State>::SharedPtr client =
    node->create_client<a1_msgs::srv::State>("get_high_state");

    auto request = std::make_shared<a1_msgs::srv::State::Request>();
    while (!client->wait_for_service(1s)) {
        if (!rclcpp::ok()) {
            RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
            return 0;
        }
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "service not available, waiting again...");
    }

    auto result = client->async_send_request(request);
    // Wait for the result.
    if (rclcpp::spin_until_future_complete(node, result) ==
        rclcpp::executor::FutureReturnCode::SUCCESS)
    {
        int i;
        std::cout << "levelFlag = "  << int(result.get()->levelflag) << std::endl;
        std::cout << "commVersion = "  << int(result.get()->commversion) << std::endl;
        std::cout << "robotID = "  << int(result.get()->robotid) << std::endl;
        std::cout << "SN = "  << int(result.get()->sn) << std::endl;
        std::cout << "bandWidth = "  << int(result.get()->bandwidth) << std::endl;

        std::cout << "mode = "  << int(result.get()->mode) << std::endl;
        std::cout << "forwardSpeed = "  << result.get()->forwardspeed << std::endl;
        std::cout << "sideSpeed = "  << result.get()->sidespeed << std::endl;
        std::cout << "rotateSpeed = "  << result.get()->rotatespeed << std::endl;

        std::cout << "bodyHeight = "  << result.get()->bodyheight << std::endl;
        std::cout << "updownSpeed = "  << result.get()->updownspeed << std::endl;
        std::cout << "forwardPosition = "  << result.get()->forwardposition << std::endl;
        std::cout << "sidePosition = "  << result.get()->sideposition << std::endl;
        std::cout << "========IMU STATE========" << std::endl;
        for (i = 0; i < 4; i++)
        {
            std::cout << "imu.quaternion["  << i <<"] = "<<result.get()->imu.quaternion[i] << std::endl;
            if (i != 3)
            {
                std::cout << "imu.gyroscope["  << i <<"] = "<<result.get()->imu.gyroscope[i] << std::endl;
                std::cout << "imu.accelerometer["  << i <<"] = "<<result.get()->imu.accelerometer[i] << std::endl;
            }
        }
        std::cout << "imu.temperature = "  << int(result.get()->imu.temperature) << std::endl;
        std::cout << "========Cartesian footPosition2Body========" << std::endl;
        for (i = 0; i < 4; i++)
        {
            std::cout  << i <<": x = " <<result.get()->footposition2body[i].x << " y = " <<result.get()->footposition2body[i].y 
                << " z = " <<result.get()->footposition2body[i].z << std::endl;
        }
        std::cout << "========Cartesian footSpeed2Body========" << std::endl;
        for (i = 0; i < 4; i++)
        {
            std::cout  << i <<": x = " <<result.get()->footspeed2body[i].x << " y = " <<result.get()->footspeed2body[i].y 
                << " z = " <<result.get()->footspeed2body[i].z << std::endl;
        }
        std::cout << "========footForce========" << std::endl;
        for (i = 0; i < 4; i++)
        {
            std::cout << "footForce[" << i << "] = " << result.get()->footforce[i] << std::endl;
            std::cout << "footForce[" << i << "] = " << result.get()->footforceest[i] << std::endl;
        }
    } 
    else {
        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to call service");
    }
    
    return 0;
}


int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<PubNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}

