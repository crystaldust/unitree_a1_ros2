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
        std::cout << "======stand====="<< std::endl;
    }
    else
    {
        high_cmd.mode = CMD_SET_MODE_WALK;
        high_cmd.forwardSpeed = forwardSpeed;
        high_cmd.sideSpeed = sideSpeed;
        high_cmd.rotateSpeed = rotateSpeed;
	      std::cout << "======walk====="<< std::endl;
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
             high_cmd.yaw = value;
	           break;
        case CMD_SET_YAW_DOWN:	
	           high_cmd.yaw = value;
	           break;
	      case CMD_SET_PITCH_UP:
             high_cmd.pitch = value;
	           break;
	      case CMD_SET_PITCH_DOWN:
	           high_cmd.pitch = value;
	           break;
	      case CMD_SET_ROLL_LEFT:
	           high_cmd.roll = value;
	           break;
	      case CMD_SET_ROLL_RIGHT:
             high_cmd.roll = value;
	           break;
        case CMD_SET_BODY_HEIGH_DOWN:
	           high_cmd.bodyHeight = value;
	           break;
	      case CMD_SET_BODY_HEIGH_UP:
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
    UNITREE_LEGGED_SDK::HighState current_state;
    udp.GetRecv(current_state);

    std::cout << "levelFlag = "  << current_state.levelFlag << std::endl;
    std::cout << "commVersion = "  << current_state.commVersion << std::endl;
    std::cout << "robotID = "  << current_state.robotID << std::endl;
    std::cout << "SN = "  << current_state.SN << std::endl;
    std::cout << "bandWidth = "  << current_state.bandWidth << std::endl;
    std::cout << "mode = "  << current_state.mode << std::endl;
    std::cout << "forwardSpeed = "  << current_state.forwardSpeed << std::endl;
    std::cout << "sideSpeed = "  << current_state.sideSpeed << std::endl;
    std::cout << "rotateSpeed = "  << current_state.rotateSpeed << std::endl;
    std::cout << "bodyHeight = "  << current_state.bodyHeight << std::endl;
    std::cout << "updownSpeed = "  << current_state.updownSpeed << std::endl;
    std::cout << "forwardPosition = "  << current_state.forwardPosition << std::endl;
    std::cout << "sidePosition = "  << current_state.sidePosition << std::endl;

}

void A1Wrapper::stop() {
    UNITREE_LEGGED_SDK::HighCmd stop_cmd = {0};
    stop_cmd.mode = 1;
    udp.SetSend(stop_cmd);
    sleep(10);
}

void A1Wrapper::setVel(float forward_speed) {
    UNITREE_LEGGED_SDK::HighCmd foward_cmd = {0};
    foward_cmd.forwardSpeed = forward_speed;
    udp.SetSend(foward_cmd);
    sleep(10);
}

void A1Wrapper::setWalkMode() {
    UNITREE_LEGGED_SDK::HighCmd walk_mode = {0};
    walk_mode.mode = 1;
    udp.SetSend(walk_mode);
    sleep(10);

}
