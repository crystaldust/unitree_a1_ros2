//
// Created by sun on 2021/3/1.
//

#ifndef UNITREE_DRIVER_A1_WRAPPER_H
#define UNITREE_DRIVER_A1_WRAPPER_H

#include <iostream>
#include "unitree_legged_sdk/unitree_legged_sdk.h"
#include "a1_comm/A1_comm.h"
#include "geometry_msgs/msg/twist.hpp"
#include "a1_msgs/srv/mode.hpp"
#include "a1_msgs/srv/high_state.hpp"
#include "a1_msgs/srv/imu.hpp"
#include "a1_msgs/srv/cartesian.hpp"
#include "a1_msgs/msg/pose.hpp"
#define SEND_LENGTH UNITREE_LEGGED_SDK::HIGH_CMD_LENGTH
#define RECV_LENGTH UNITREE_LEGGED_SDK::HIGH_CMD_LENGTH

class A1Wrapper {
public:
    /*sport mode*/
    A1Wrapper(uint8_t sport_mode) : udp(8081, "192.168.123.161", 8082, SEND_LENGTH, RECV_LENGTH), 
                                   safety(UNITREE_LEGGED_SDK::LeggedType::A1) {
        memset(&cmd, 0, sizeof(cmd));
        r_mode = sport_mode;
        udp.InitCmdData(cmd);
    }
    /*basic mode*/
    A1Wrapper() : udp(UNITREE_LEGGED_SDK::HIGHLEVEL), safety(UNITREE_LEGGED_SDK::LeggedType::A1), r_mode(0) {
        udp.InitCmdData(cmd);
    }
    void UDPRecv() {
        udp.Recv();
    }

    void UDPSend() {
        udp.Send();
    }
    void set_velocity(float forwardSpeed, float sideSpeed, float rotateSpeed);
    void set_pose(float yaw, float pitch, float roll, float bodyHeight);
    void set_mode(uint8_t mode);
    void recv_high_state(std::shared_ptr<a1_msgs::srv::HighState::Response> response);
    void recv_imu_msg(std::shared_ptr<a1_msgs::srv::Imu::Response> response);
    void recv_cartesian_msg(std::shared_ptr<a1_msgs::srv::Cartesian::Response> response);
    UNITREE_LEGGED_SDK::UDP udp;
    UNITREE_LEGGED_SDK::Safety safety;
    UNITREE_LEGGED_SDK::HighCmd cmd;
    UNITREE_LEGGED_SDK::HighState state;
    uint8_t r_mode;
};

#endif //UNITREE_DRIVER_A1_WRAPPER_H
