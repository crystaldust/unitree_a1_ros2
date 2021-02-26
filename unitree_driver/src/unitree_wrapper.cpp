//
// Created by sun on 2021/2/24.
//

#include "unitree_driver/unitree_wrapper.h"

void unitreeWrapper::walkCmd(float forwardSpeed, float sideSpeed, float rotateSpeed){

    UNITREE_LEGGED_SDK::HighState current_state;
    UNITREE_LEGGED_SDK::HighCmd high_cmd = {0};

    udp_wrapper.udp.GetRecv(current_state);
    if (current_state.mode == 1){
        std::cout << "received : 1 //" << current_state.mode << std::endl;
    }

    high_cmd.mode = 2;
    high_cmd.forwardSpeed = forwardSpeed;
    high_cmd.sideSpeed = sideSpeed;
    high_cmd.rotateSpeed = rotateSpeed;

    udp_wrapper.udp.SetSend(high_cmd);
    sleep(4);
    stop();
}

void unitreeWrapper::stop() {
    UNITREE_LEGGED_SDK::HighCmd stop_cmd = {0};
    stop_cmd.mode = 1;
    udp_wrapper.udp.SetSend(stop_cmd);
}



