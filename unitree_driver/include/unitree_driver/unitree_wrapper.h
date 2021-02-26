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
        udp.InitCmdData(cmd);
    }

    void UDPRecv(){
        udp.Recv();
    }
    void UDPSend(){
        udp.Send();
    }

    UNITREE_LEGGED_SDK::UDP udp;
    UNITREE_LEGGED_SDK::Safety safety;
    UNITREE_LEGGED_SDK::HighCmd cmd;
};

class unitreeWrapper{
public:
    unitreeWrapper(){
		UNITREE_LEGGED_SDK::InitEnvironment();
        UNITREE_LEGGED_SDK::LoopFunc loop_udpRecv("udp_recv", dt, 3, boost::bind(&udpWrapper::UDPRecv, &udp_wrapper));
        UNITREE_LEGGED_SDK::LoopFunc loop_udpSend("udp_send", dt, 3, boost::bind(&udpWrapper::UDPSend, &udp_wrapper));
        loop_udpRecv.start();
        loop_udpSend.start();
    }
    void walkCmd(double forwardSpeed, double sideSpeed, double rotateSpeed);
    void stop();

private:
//    void robotToLocalTime();
    udpWrapper udp_wrapper = udpWrapper();
    void standCmd();
//   dt: period
    float dt = 0.002f;
};

#endif //UNITREE_DRIVER_UNITREE_WRAPPER_H
