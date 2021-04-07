//
// Created by sun on 2021/3/1.
//

#ifndef UNITREE_DRIVER_A1_WRAPPER_H
#define UNITREE_DRIVER_A1_WRAPPER_H

#include <iostream>
#include "unitree_legged_sdk/unitree_legged_sdk.h"
#include "a1_comm/A1_comm.h"

enum SetCmd {
    CMD_SET_MODE_STAND = 0,
    CMD_SET_MODE_FORCE_STAND,
    CMD_SET_MODE_WALK,
    CMD_SET_BODY_HEIGH,
    CMD_SET_YAW,
    CMD_SET_PITCH,
    CMD_SET_ROLL,
    CMD_SET_CLEAR_ALL
};
class A1Wrapper {
public:

    /*sport mode*/
    A1Wrapper(int sport_mode) : udp(8081, "192.168.123.161", 8082, UNITREE_LEGGED_SDK::HIGH_CMD_LENGTH, UNITREE_LEGGED_SDK::HIGH_STATE_LENGTH), safety(UNITREE_LEGGED_SDK::LeggedType::A1), cmd({0}) {
        udp.InitCmdData(cmd);
    }
    /*basic mode*/
    A1Wrapper() : udp(UNITREE_LEGGED_SDK::HIGHLEVEL), safety(UNITREE_LEGGED_SDK::LeggedType::A1), cmd({0}) {
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
    UNITREE_LEGGED_SDK::HighState state= {0};
    UNITREE_LEGGED_SDK::IMU imu = {0};
    UNITREE_LEGGED_SDK::Cartesian footPosition2Body[4] = {0};
    UNITREE_LEGGED_SDK::Cartesian footSpeed2Body[4] = {0};
};

#endif //UNITREE_DRIVER_A1_WRAPPER_H
