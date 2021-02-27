//
// Created by sun on 2021/2/24.
//

#include "unitree_driver/unitree_wrapper.h"

void udpWrapper::walkCmd(float forwardSpeed, float sideSpeed, float rotateSpeed){

    UNITREE_LEGGED_SDK::HighState current_state;
    UNITREE_LEGGED_SDK::HighCmd high_cmd = {0};

    udp.GetRecv(current_state);
    std::cout<<unsigned(current_state.mode)<<std::endl;

    if (unsigned(current_state.mode) == 0){
        std::cout << "mode : " << unsigned(current_state.mode) << std::endl;
        high_cmd.mode = 1;
        std::cout << "change mode 0 -> 1"<< std::endl;
        udp.SetSend(high_cmd);
        sleep(4);
    }
    else if (unsigned(current_state.mode) == 1){
        high_cmd.mode = 2;
        std::cout << "change mode 1 -> 2"<< std::endl;
        udp.SetSend(high_cmd);
        sleep(4);
    }
    else if (unsigned(current_state.mode) ==2) {
        std::cout << " walking ..."<< std::endl;
        high_cmd.mode = 2;
        high_cmd.forwardSpeed = forwardSpeed;
        high_cmd.sideSpeed = sideSpeed;
        high_cmd.rotateSpeed = rotateSpeed;
        udp.SetSend(high_cmd);
        sleep(2);
        std::cout << " stop "<< std::endl;
        stop();
    }
    else{
        std::cout << "mode : " << unsigned(current_state.mode) << std::endl;
    }
}

void udpWrapper::stop() {
    UNITREE_LEGGED_SDK::HighCmd stop_cmd = {0};
    stop_cmd.mode = 1;
    udp.SetSend(stop_cmd);
    sleep(10);
}



