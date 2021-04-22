//
// Created by sun on 2021/3/1.
//

#ifndef UNITREE_DRIVER_A1_WRAPPER_H
#define UNITREE_DRIVER_A1_WRAPPER_H

#include <iostream>
#include "geometry_msgs/msg/twist.hpp"
#include "a1_msgs/srv/state.hpp"
#include "unitree_legged_sdk/unitree_legged_sdk.h"

enum SetCmd{
    CMD_SET_MODE_STAND = 0,
    CMD_SET_MODE_FORCE_STAND,
    CMD_SET_MODE_WALK,
    CMD_SET_BODY_HEIGH_UP,
    CMD_SET_BODY_HEIGH_DOWN,
    CMD_SET_YAW_UP,
    CMD_SET_YAW_DOWN,
    CMD_SET_PITCH_UP,
    CMD_SET_PITCH_DOWN,
    CMD_SET_ROLL_LEFT,
    CMD_SET_ROLL_RIGHT,
    CMD_SET_CLEAR_ALL
};
enum GetInfoCmd{
    CMD_GET_SPEED_INFO = CMD_SET_CLEAR_ALL + 1,
    CMD_GET_IMU_INFO,
    CMD_GET_CARTESIAN_INFO,
    CMD_GET_BODYHEIGH_INFO,
    CMD_GET_YAW_INFO,
    CMD_GET_PITCH_INFO,
    CMD_GET_ALL_HIGH_STATE_INFO
};

class A1Wrapper {
public:
#ifdef SPORT_MODE
    /*sport mode*/
    A1Wrapper() : udp(8081, "192.168.123.161", 8082, UNITREE_LEGGED_SDK::HIGH_CMD_LENGTH, UNITREE_LEGGED_SDK::HIGH_STATE_LENGTH), safety(UNITREE_LEGGED_SDK::LeggedType::A1), cmd({0}) {
        udp.InitCmdData(cmd);
    }
#else
    /*basic mode*/
    A1Wrapper() : udp(UNITREE_LEGGED_SDK::HIGHLEVEL), safety(UNITREE_LEGGED_SDK::LeggedType::A1), cmd({0}) {
        udp.InitCmdData(cmd);
    }
#endif
    void UDPRecv() {
        udp.Recv();
    }

    void UDPSend() {
        udp.Send();
    }

    void walkCmd(float forwardSpeed, float sideSpeed, float rotateSpeed);

    void stop();

    void setVel(float forward_speed);

    void setWalkMode();
    void setControlCmd(uint8_t mode, float value);
    void getHighState();
    UNITREE_LEGGED_SDK::UDP udp;
    UNITREE_LEGGED_SDK::Safety safety;
    UNITREE_LEGGED_SDK::HighCmd cmd;
    UNITREE_LEGGED_SDK::HighState state= {0};
};

#endif //UNITREE_DRIVER_A1_WRAPPER_H
