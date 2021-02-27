//
// Created by sun on 2021/2/26.
//

#ifndef UNITREE_DRIVER_UNITREE_WRAPPER_H
#define UNITREE_DRIVER_UNITREE_WRAPPER_H

#include <iostream>
#include "time.h"
#include "geometry_msgs/msg/twist.hpp"
#include "unitree_legged_sdk/unitree_legged_sdk.h"

class udpWrapper{
public:
    udpWrapper():udp(UNITREE_LEGGED_SDK::HIGHLEVEL), safety(UNITREE_LEGGED_SDK::LeggedType::A1), cmd({0}){
    }

    void UDPInit(){
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
    UNITREE_LEGGED_SDK::UDP udp;
    UNITREE_LEGGED_SDK::Safety safety;
    UNITREE_LEGGED_SDK::HighCmd cmd;
};

//class unitreeWrapper{
//public:
//    unitreeWrapper( udpWrapper &udp_wrapper ){
//        this->udp_wrapper = udp_wrapper;
//    }
//
//    void walkCmd(float forwardSpeed, float sideSpeed, float rotateSpeed);
//    void stop();
//    udpWrapper udp_wrapper;
//private:
////    void robotToLocalTime();
//    void standCmd();
//
//};

#endif //UNITREE_DRIVER_UNITREE_WRAPPER_H
