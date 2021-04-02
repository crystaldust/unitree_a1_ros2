#ifndef UNITREE_A1_ROS2_COMMON_H
#define UNITREE_A1_ROS2_COMMON_H

#include "geometry_msgs/msg/twist.hpp"
#include "a1_msgs/srv/mode.hpp"
#include "a1_msgs/srv/high_state.hpp"
#include "a1_msgs/srv/imu.hpp"
#include "a1_msgs/msg/pose.hpp"

//IMU
#define UNITREE_A1_IMU_QUATERNION 4
#define UNITREE_A1_IMU_ANGULAR_VELOCITY  3
#define UNITREE_A1_IMU_ACCELEROMETER  3
#define UNITREE_A1_DOG_LEGS  4
#define UNITREE_A1_WIRELESS_REMOTE_BYTE 40

//TOPIC
#define ROS2_TOPIC_SET_VELOCITY "unitree_a1/vel_cmd"
#define ROS2_TOPIC_SET_MODE "set_mode"
#define ROS2_TOPIC_SET_POSE "set_pose"
#define ROS2_TOPIC_GET_HIGH_STATE_MSG "get_high_state"
#define ROS2_TOPIC_GET_IMU_MSG "get_imu_msg"
#endif //UNITREE_A1_ROS2_COMMON_H