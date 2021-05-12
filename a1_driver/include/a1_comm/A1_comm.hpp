// Copyright 2021 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef A1_COMM__A1_COMM_HPP_
#define A1_COMM__A1_COMM_HPP_

enum StartupMode { STARTUP_BASIC_MODE = 0, STARTUP_SPORT_MODE };
enum SetLevel { HIGH_LEVEL = 0X00, LOW_LEVEL = 0xff };
enum SetCmd
{
  CMD_SET_MODE_STAND = 0,
  CMD_SET_MODE_FORCE_STAND,
  CMD_SET_MODE_WALK
};
// IMU
#define UNITREE_A1_IMU_QUATERNION 4
#define UNITREE_A1_IMU_ANGULAR_VELOCITY 3
#define UNITREE_A1_IMU_ACCELEROMETER 3
#define UNITREE_A1_DOG_LEGS 4
#define UNITREE_A1_WIRELESS_REMOTE_BYTE 40
#define UNITREE_A1_MOTOR_STATE_ELEMENT_NUMS 40

// TOPIC
#define ROS2_TOPIC_SET_VELOCITY "unitree_a1/cmd_vel"
#define ROS2_TOPIC_SET_POSE "unitree_a1/cmd_pose"
// Service
#define ROS2_SERVICE_SET_MODE "unitree_a1/set_mode"
#define ROS2_SERVICE_GET_HIGH_STATE_MSG "unitree_a1/get_high_state"
#define ROS2_SERVICE_GET_LOW_STATE_MSG "unitree_a1/get_low_state"
#define ROS2_SERVICE_GET_IMU_MSG "unitree_a1/get_imu_msg"
#define ROS2_SERVICE_GET_CARTESIAN_MSG "unitree_a1/get_cartesian_msg"
#endif  // A1_COMM__A1_COMM_HPP_
