//
// Created by sun on 2021/3/1.
//

#ifndef UNITREE_DRIVER_A1_WRAPPER_H
#define UNITREE_DRIVER_A1_WRAPPER_H

#include <iostream>
#include "unitree_legged_sdk/unitree_legged_sdk.h"

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
    void velocity_set_cmd(float forwardSpeed, float sideSpeed, float rotateSpeed);
    void pose_set_cmd(float yaw, float pitch, float roll, float bodyHeight);
    void mode_set_cmd(uint8_t mode);
    void recv_high_state();
    UNITREE_LEGGED_SDK::UDP udp;
    UNITREE_LEGGED_SDK::Safety safety;
    UNITREE_LEGGED_SDK::HighCmd cmd;
    UNITREE_LEGGED_SDK::HighState state= {0};
};

#endif //UNITREE_DRIVER_A1_WRAPPER_H
