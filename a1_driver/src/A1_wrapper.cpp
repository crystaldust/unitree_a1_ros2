//
// Created by sun on 2021/3/1.
//

#include <time.h>
#include "a1_driver/A1_wrapper.h"

void A1Wrapper::walkCmd(float forwardSpeed, float sideSpeed, float rotateSpeed) {
    UNITREE_LEGGED_SDK::HighCmd high_cmd = {0};
    
    if (forwardSpeed == 0 && sideSpeed == 0 && rotateSpeed == 0)
    {
        high_cmd.mode = CMD_SET_MODE_FORCE_STAND;
        high_cmd.forwardSpeed = forwardSpeed;
        high_cmd.sideSpeed = sideSpeed;
        high_cmd.rotateSpeed = rotateSpeed;
    }
    else
    {
        high_cmd.mode = CMD_SET_MODE_WALK;
        high_cmd.forwardSpeed = forwardSpeed;
        high_cmd.sideSpeed = sideSpeed;
        high_cmd.rotateSpeed = rotateSpeed;
    }
    udp.SetSend(high_cmd);
}

void A1Wrapper::setControlCmd(uint8_t mode, float value){
    UNITREE_LEGGED_SDK::HighCmd high_cmd = {0};

    switch (mode){
        case CMD_SET_MODE_STAND:
        case CMD_SET_MODE_FORCE_STAND:
        case CMD_SET_MODE_WALK:
            high_cmd.mode = mode;
            break;
        case CMD_SET_YAW_UP:
            high_cmd.mode = CMD_SET_MODE_FORCE_STAND;
            high_cmd.yaw = value;
            break;
        case CMD_SET_YAW_DOWN:
            high_cmd.mode = CMD_SET_MODE_FORCE_STAND;
            high_cmd.yaw = value;
            break;
        case CMD_SET_PITCH_UP:
            high_cmd.mode = CMD_SET_MODE_FORCE_STAND;
            high_cmd.pitch = value;
            break;
        case CMD_SET_PITCH_DOWN:
            high_cmd.mode = CMD_SET_MODE_FORCE_STAND;
            high_cmd.pitch = value;
            break;
        case CMD_SET_ROLL_LEFT:
            high_cmd.mode = CMD_SET_MODE_FORCE_STAND;
            high_cmd.roll = value;
            break;
        case CMD_SET_ROLL_RIGHT:
            high_cmd.mode = CMD_SET_MODE_FORCE_STAND;
            high_cmd.roll = value;
            break;
        case CMD_SET_BODY_HEIGH_DOWN:
            high_cmd.mode = CMD_SET_MODE_FORCE_STAND;
            high_cmd.bodyHeight = value;
            break;
        case CMD_SET_BODY_HEIGH_UP:
            high_cmd.mode = CMD_SET_MODE_FORCE_STAND;
            high_cmd.bodyHeight = value;
            break;
        case CMD_SET_CLEAR_ALL:
            high_cmd.mode = CMD_SET_MODE_FORCE_STAND;
            break;
        default:
            std::cout << "set mode invalid"<< std::endl;
            return;
        }
        udp.SetSend(high_cmd);
}

void A1Wrapper::getHighState()
{
    udp.GetRecv(state);
}
