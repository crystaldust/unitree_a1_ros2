//
// Created by sun on 2021/3/1.
//

#ifndef UNITREE_DRIVER_A1_WRAPPER_H
#define UNITREE_DRIVER_A1_WRAPPER_H

#include <iostream>
#include "time.h"
#include "geometry_msgs/msg/twist.hpp"
#include "unitree_legged_sdk/unitree_legged_sdk.h"

class A1Wrapper{
public:
    A1Wrapper():udp(UNITREE_LEGGED_SDK::HIGHLEVEL), safety(UNITREE_LEGGED_SDK::LeggedType::A1), cmd({0}){
        udp.InitCmdData(cmd);
    }
    void UDPRecv(){
        udp.Recv();
    }
    void UDPSend(){
        udp.Send();
    }
    void walkCmd(float forwardSpeed, float sideSpeed, float rotateSpeed);
    void stop();
    void setVel(float forward_speed);
    void setWalkMode();
    UNITREE_LEGGED_SDK::UDP udp;
    UNITREE_LEGGED_SDK::Safety safety;
    UNITREE_LEGGED_SDK::HighCmd cmd;
};

#endif //UNITREE_DRIVER_A1_WRAPPER_H
