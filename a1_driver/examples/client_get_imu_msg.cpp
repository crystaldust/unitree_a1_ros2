#include <memory>
#include <chrono>
#include <unistd.h>
#include "rclcpp/rclcpp.hpp"
#include "comm/comm_ros.h"

using namespace std::chrono_literals;

class ClientNode : public rclcpp::Node {
public:
    ClientNode() : Node("GetImuMsg"), wait_count(5) {
        client = this->create_client<a1_msgs::srv::Imu>(ROS2_TOPIC_GET_IMU_MSG);
        timer_c = this->create_wall_timer(500ms, std::bind(&ClientNode::client_node_get_imu_msg, this));
    }
private:
    void client_node_get_imu_msg();
    rclcpp::TimerBase::SharedPtr timer_c;
    rclcpp::Client<a1_msgs::srv::Imu>::SharedPtr client;
    size_t wait_times;
};

void ClientNode::client_node_get_imu_msg() {
    int times = 0;
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
        auto imu = result.get();
        int i;
        
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "##############ROBOT IMU INFO#######################");
        for (i = 0; i < UNITREE_A1_IMU_QUATERNION; i++) {
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "imu.quaternion[%d]: %12f", i, HighState->imu.quaternion[i]);
        }

        for (i = 0; i < UNITREE_A1_IMU_ANGULAR_VELOCITY; i++) {
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "imu.gyroscope[%d]: %12f", i, HighState->imu.gyroscope[i]);
        }

        for (i = 0; i < UNITREE_A1_IMU_ACCELEROMETER; i++) {
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "imu.gyroscope[%d]: %12f", i, HighState->imu.accelerometer[i]);
        }
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "imu.temperature: %12f", HighState->imu.temperature);
    } 
    else {
        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to call service");
    }
    return;
}


int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<ClientNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}

