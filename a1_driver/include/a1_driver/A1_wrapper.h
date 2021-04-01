//
// Created by sun on 2021/3/1.
//

#ifndef UNITREE_DRIVER_A1_WRAPPER_H
#define UNITREE_DRIVER_A1_WRAPPER_H

#include <iostream>
#include "unitree_legged_sdk/unitree_legged_sdk.h"
#include "comm/comm_ros.h"
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
    void velocity_set_cmd(float forwardSpeed, float sideSpeed, float rotateSpeed);
    void pose_set_cmd(uint8_t cmd_code, float value);
    void mode_set_cmd(uint8_t mode);
    void recv_high_state();
    UNITREE_LEGGED_SDK::UDP udp;
    UNITREE_LEGGED_SDK::Safety safety;
    UNITREE_LEGGED_SDK::HighCmd cmd;
    UNITREE_LEGGED_SDK::HighState state= {0};
};

#endif //UNITREE_DRIVER_A1_WRAPPER_H
