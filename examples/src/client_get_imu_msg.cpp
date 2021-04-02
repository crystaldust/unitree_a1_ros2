#include <memory>
#include <chrono>
#include <unistd.h>
#include "rclcpp/rclcpp.hpp"
#include "a1_comm/A1_comm.h"


using namespace std::chrono_literals;

class ClientNode  {
public:
    ClientNode() :     count_(5) {
        node = rclcpp::Node::make_shared("GetImuMsg");
        client = node->create_client<a1_msgs::srv::Imu>(ROS2_TOPIC_GET_IMU_MSG);
    }
    void client_node_get_imu_msg();
private:
    rclcpp::Client<a1_msgs::srv::Imu>::SharedPtr client;
    std::shared_ptr<rclcpp::Node> node;
    size_t count_;
};

void ClientNode::client_node_get_imu_msg() {
    size_t times = 0;
    auto request = std::make_shared<a1_msgs::srv::Imu::Request>();
    while (!client->wait_for_service(1s)) {
        times++;
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "service not available, waiting times(%d)...", times);
        if (count_ == times)
            return;
    }

    auto result = client->async_send_request(request);
    // Wait for the result.
    if (rclcpp::spin_until_future_complete(node, result) ==
        rclcpp::executor::FutureReturnCode::SUCCESS)
    {
        auto HighState = result.get();
        int i;
        
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "##############ROBOT IMU INFO#######################");
        for (i = 0; i < UNITREE_A1_IMU_QUATERNION; i++) {
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "imu.quaternion[%d]: %18f", i, HighState->imu.quaternion[i]);
        }

        for (i = 0; i < UNITREE_A1_IMU_ANGULAR_VELOCITY; i++) {
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "imu.gyroscope[%d]: %18f", i, HighState->imu.gyroscope[i]);
        }

        for (i = 0; i < UNITREE_A1_IMU_ACCELEROMETER; i++) {
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "imu.gyroscope[%d]: %18f", i, HighState->imu.accelerometer[i]);
        }
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "imu.temperature: %18f", HighState->imu.temperature);
    } 
    else {
        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to call service");
    }
    return;
}


int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    ClientNode client;
    //rclcpp::WallRate loop_rate(10.0);
    //while (rclcpp::ok())
    {
        client.client_node_get_imu_msg();
        //loop_rate.sleep();
    }
    rclcpp::shutdown();
    return 0;
}

