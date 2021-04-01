#ifndef UNITREE_A1_ROS2_COMMON_H
#define UNITREE_A1_ROS2_COMMON_H

#include "geometry_msgs/msg/twist.hpp"
#include "a1_msgs/srv/mode.hpp"
#include "a1_msgs/srv/high_state.hpp"
#include "a1_msgs/srv/imu.hpp"

//IMU
#define UNITREE_A1_IMU_QUATERNION 4
#define UNITREE_A1_IMU_ANGULAR_VELOCITY  3
#define UNITREE_A1_IMU_ACCELEROMETER  3
#define UNITREE_A1_DOG_LEGS  4
#define UNITREE_A1_WIRELESS_REMOTE_BYTE 40

//TOPIC
#define ROS2_TOPIC_SET_VELOCITY "unitree_a1/vel_cmd"
#define ROS2_TOPIC_SET_MODE "set_mode"
#define ROS2_TOPIC_GET_HIGH_STATE_MSG "get_high_state"
#define ROS2_TOPIC_GET_IMU_MSG "get_imu_msg"

//SET COMMAND CODE
enum SetCmd {
    CMD_SET_MODE_STAND = 0,
    CMD_SET_MODE_FORCE_STAND,
    CMD_SET_MODE_WALK,
    CMD_SET_BODY_HEIGH,
    CMD_SET_YAW,
    CMD_SET_PITCH,
    CMD_SET_ROLL,
    CMD_SET_CLEAR_ALL
};
enum GetInfoCmd {
    CMD_GET_SPEED_INFO = CMD_SET_CLEAR_ALL + 1,
    CMD_GET_IMU_INFO,
    CMD_GET_CARTESIAN_INFO,
    CMD_GET_BODYHEIGH_INFO,
    CMD_GET_YAW_INFO,
    CMD_GET_PITCH_INFO,
    CMD_GET_ALL_HIGH_STATE_INFO
};

#endif //UNITREE_A1_ROS2_COMMON_H