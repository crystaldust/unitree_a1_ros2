//
// Created by sun on 2021/3/1.
//

#include <time.h>
#include "a1_driver/A1_wrapper.h"

void A1Wrapper::velocity_set_cmd(float forwardSpeed, float sideSpeed, float rotateSpeed) {
    UNITREE_LEGGED_SDK::HighCmd high_cmd = {0};
    
    if (forwardSpeed == 0 && sideSpeed == 0 && rotateSpeed == 0) {
        high_cmd.mode = CMD_SET_MODE_FORCE_STAND;
        high_cmd.forwardSpeed = forwardSpeed;
        high_cmd.sideSpeed = sideSpeed;
        high_cmd.rotateSpeed = rotateSpeed;
    } else {
        high_cmd.mode = CMD_SET_MODE_WALK;
        high_cmd.forwardSpeed = forwardSpeed;
        high_cmd.sideSpeed = sideSpeed;
        high_cmd.rotateSpeed = rotateSpeed;
    }
    udp.SetSend(high_cmd);
    std::cout << "set speed succcess. mode = " << int(mode) <<std::endl;
}

void A1Wrapper::mode_set_cmd(uint8_t mode) {
    UNITREE_LEGGED_SDK::HighCmd high_cmd = {0};

    high_cmd.mode = mode;
    udp.SetSend(high_cmd);
    std::cout << "set mode succcess. mode = " << int(mode) <<std::endl;
}
void A1Wrapper::pose_set_cmd(uint8_t cmd_code, float value) {
    UNITREE_LEGGED_SDK::HighCmd high_cmd = {0};

    switch (cmd_code) {
        case CMD_SET_YAW:
            high_cmd.yaw = value;
            break;
        case CMD_SET_PITCH:
            high_cmd.pitch = value;
            break;
        case CMD_SET_ROLL:
            high_cmd.roll = value;
            break;
        case CMD_SET_BODY_HEIGH:
            high_cmd.bodyHeight = value;
            break;
        case CMD_SET_CLEAR_ALL:
            high_cmd.mode = CMD_SET_MODE_FORCE_STAND;
            break;
        default:
            std::cout << "set mode invalid"<< std::endl;
            return;
    }
    high_cmd.mode = CMD_SET_MODE_FORCE_STAND;
    udp.SetSend(high_cmd);
    std::cout << "set pose succcess." <<std::endl;
}

void A1Wrapper::recv_high_state() {
    udp.GetRecv(state);
}
