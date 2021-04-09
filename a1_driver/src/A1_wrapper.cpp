//
// Created by sun on 2021/3/1.
//

#include <time.h>
#include "a1_driver/A1_wrapper.h"

void A1Wrapper::set_velocity(float forwardSpeed, float sideSpeed, float rotateSpeed) {
    UNITREE_LEGGED_SDK::HighCmd high_cmd {};
    
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
}

void A1Wrapper::set_mode(uint8_t mode) {
    UNITREE_LEGGED_SDK::HighCmd high_cmd {};

    high_cmd.mode = mode;
    udp.SetSend(high_cmd);
}

void A1Wrapper::set_pose(float yaw, float pitch, float roll, float bodyHeight) {
    UNITREE_LEGGED_SDK::HighCmd high_cmd {};

    high_cmd.mode = CMD_SET_MODE_FORCE_STAND;
    high_cmd.yaw = yaw;
    high_cmd.pitch = pitch;
    high_cmd.roll = roll;
    high_cmd.bodyHeight = bodyHeight;
    udp.SetSend(high_cmd);
}

void A1Wrapper::recv_imu_msg(std::shared_ptr<a1_msgs::srv::Imu::Response> response) {
    udp.GetRecv(state);
    for (int i = 0; i < UNITREE_A1_IMU_QUATERNION; i++) {
        response->quaternion[i] = state.imu.quaternion[i];
    }
    
    for (int i = 0; i < UNITREE_A1_IMU_ANGULAR_VELOCITY; i++) {
        response->gyroscope[i] = state.imu.gyroscope[i];
    }

    for (int i = 0; i < UNITREE_A1_IMU_ACCELEROMETER; i++) {
        response->accelerometer[i] = state.imu.accelerometer[i];
    }
    response->temperature = int(state.imu.temperature);
}

void A1Wrapper::recv_cartesian_msg(std::shared_ptr<a1_msgs::srv::Cartesian::Response> response) {
    udp.GetRecv(state);
    for(int i = 0; i< UNITREE_A1_DOG_LEGS; i++) {
        response->footposition2body[i].x = state.footPosition2Body[i].x;
        response->footposition2body[i].y = state.footPosition2Body[i].y;
        response->footposition2body[i].z = state.footPosition2Body[i].z;
        response->footspeed2body[i].x    = state.footSpeed2Body[i].x;
        response->footspeed2body[i].y    = state.footSpeed2Body[i].y;
        response->footspeed2body[i].z    = state.footSpeed2Body[i].z;
    }
}

void A1Wrapper::recv_high_state(std::shared_ptr<a1_msgs::srv::HighState::Response> response) {
    udp.GetRecv(state);
    response->levelflag = state.levelFlag;
    response->commversion = state.commVersion;
    response->robotid = state.robotID;
    response->sn = state.SN;
    response->bandwidth = state.bandWidth;
    response->mode = state.mode;
    //IMU
    for (int i = 0; i < UNITREE_A1_IMU_QUATERNION; i++) {
        response->imu.quaternion[i] = state.imu.quaternion[i];
    }
    for (int i = 0; i < UNITREE_A1_IMU_ANGULAR_VELOCITY; i++) {
        response->imu.gyroscope[i] = state.imu.gyroscope[i];
    }
    for (int i = 0; i < UNITREE_A1_IMU_ACCELEROMETER; i++) {
        response->imu.accelerometer[i] = state.imu.accelerometer[i];
    }
    response->imu.temperature = int(state.imu.temperature);
    response->forwardspeed = state.forwardSpeed;
    response->sidespeed    = state.sideSpeed;
    response->rotatespeed  = state.rotateSpeed;
    response->bodyheight   = state.bodyHeight;
    response->updownspeed  = state.updownSpeed;
    response->forwardposition = state.forwardPosition;
    response->sideposition = state.sidePosition;
    //Cartesian
    for(int i = 0; i< UNITREE_A1_DOG_LEGS; i++) {
        response->footposition2body[i].x = state.footPosition2Body[i].x;
        response->footposition2body[i].y = state.footPosition2Body[i].y;
        response->footposition2body[i].z = state.footPosition2Body[i].z;
        response->footspeed2body[i].x    = state.footSpeed2Body[i].x;
        response->footspeed2body[i].y    = state.footSpeed2Body[i].y;
        response->footspeed2body[i].z    = state.footSpeed2Body[i].z;
        response->footforce[i]           = state.footForce[i];
        response->footforceest[i]        = state.footForceEst[i];
    }
    response->tick = state.tick;
    for(int i = 0; i < UNITREE_A1_WIRELESS_REMOTE_BYTE; i++) {
        response->wirelessremote[i] = state.wirelessRemote[i];
    }
    response->reserve = state.reserve;
    response->crc = state.crc;
}
