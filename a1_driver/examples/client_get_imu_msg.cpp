#include <memory>
#include <chrono>
#include <unistd.h>
#include "rclcpp/rclcpp.hpp"
#include "comm/comm_ros.h"

using namespace std::chrono_literals;

class ClientNode : public rclcpp::Node {
public:
    ClientNode() : Node("HighState"), wait_count(5) {
        client = this->create_client<a1_msgs::srv::High_State>(ROS2_TOPIC_GET_HIGH_STATE_MSG);
        timer_c = this->create_wall_timer(500ms, std::bind(&ClientNode::client_node_get_high_state, this));
    }
private:
    void client_node_get_high_state();
    rclcpp::TimerBase::SharedPtr timer_c;
    rclcpp::Client<a1_msgs::srv::State>::SharedPtr client;
    size_t wait_times;
};

void ClientNode::client_node_get_high_state() {
    int times = 0;
    auto request = std::make_shared<a1_msgs::srv::High_State::Request>();
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
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "##############ROBOT BASIC INFO#######################");
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "levelFlag: %12u    commVersion: %12u", HighState->levelflag, HighState->commversion);
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "robotID: %12u      SN: %12u", HighState->robotid, HighState->sn);
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "mode: %12u         bandWidth: %12u", HighState->mode, HighState->bandwidth);
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "##############ROBOT VELOCITY INFO#######################");
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "forwardSpeed: %12f   sideSpeed: %12f", HighState->forwardspeed, HighState->sidespeed);
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "rotateSpeed: %12f    bodyHeight: %12f", HighState->rotateSpeed, HighState->bodyheight);
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "updownSpeed: %12f    forwardPosition: %12f", HighState->updownspeed, HighState->forwardposition);
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sidePosition: %12f", HighState->sideposition);
        
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
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "#################ROBOT FOUR LEGS INFO####################");
        for(i = 0; i< UNITREE_A1_DOG_LEGS; i++) {
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "footposition2body[i].x: %12f", i, HighState->footposition2body[i].x);
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "footposition2body[i].y: %12f", i, HighState->footposition2body[i].y);
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "footposition2body[i].z: %12f", i, HighState->footposition2body[i].z);
            
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "footspeed2body[i].x: %12f", i, HighState->footspeed2body[i].x);
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "footspeed2body[i].y: %12f", i, HighState->footspeed2body[i].y);
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "footspeed2body[i].z: %12f", i, HighState->footspeed2body[i].z);

            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "footforce[i]: %12f", i, HighState->footforce[i]);
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "footforceest[i]: %12f", i, HighState->footforceest[i]);
        }
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

