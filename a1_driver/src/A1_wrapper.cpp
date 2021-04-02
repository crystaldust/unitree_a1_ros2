//
// Created by sun on 2021/3/1.
//

#include <time.h>
#include "a1_driver/A1_wrapper.h"

void A1Wrapper::velocity_set_cmd(float forwardSpeed, float sideSpeed, float rotateSpeed) {
    UNITREE_LEGGED_SDK::HighCmd high_cmd = {0};
    
    if (forwardSpeed == 0 && sideSpeed == 0 && rotateSpeed == 0) {
        high_cmd.mode = CMD_SET_MODE_FORCE_STAND;
        high_cmd.forwardSpeed = 0;
        high_cmd.sideSpeed = 0;
        high_cmd.rotateSpeed = 0;
    } else {
        high_cmd.mode = CMD_SET_MODE_WALK;
        high_cmd.forwardSpeed = forwardSpeed;
        high_cmd.sideSpeed = sideSpeed;
        high_cmd.rotateSpeed = rotateSpeed;
    }
    udp.SetSend(high_cmd);
    std::cout << "set speed succcess."  <<std::endl;
}

void A1Wrapper::mode_set_cmd(uint8_t mode) {
    UNITREE_LEGGED_SDK::HighCmd high_cmd = {0};

    high_cmd.mode = mode;
    udp.SetSend(high_cmd);
    std::cout << "set mode succcess. mode = " << int(mode) <<std::endl;
}

void A1Wrapper::pose_set_cmd(float yaw, float pitch, float roll, float bodyHeight) {
    UNITREE_LEGGED_SDK::HighCmd high_cmd = {0};

    high_cmd.mode = CMD_SET_MODE_FORCE_STAND;
    if (bodyHeight == 0 && yaw == 0 && pitch == 0 && roll == 0) {
        
        high_cmd.bodyHeight = 0;
        high_cmd.yaw = 0;
        high_cmd.pitch = 0;
        high_cmd.roll = 0;
    } else {
        high_cmd.bodyHeight = bodyHeight;
        high_cmd.yaw = yaw;
        high_cmd.pitch = pitch;
        high_cmd.roll = roll;
    }
    udp.SetSend(high_cmd);
    std::cout << "set pose succcess." <<std::endl;
    std::cout << bodyHeight << " " << yaw << " " << pitch <<" " << roll <<std::endl;
}

void A1Wrapper::recv_high_state() {
    udp.GetRecv(state);
}
