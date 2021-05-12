// Copyright 2015 Open Source Robotics Foundation, Inc.
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

#ifndef A1_DRIVER__A1_WRAPPER_HPP_
#define A1_DRIVER__A1_WRAPPER_HPP_

#include <iostream>
#include "a1_comm/A1_comm.hpp"
#include "unitree_legged_sdk/unitree_legged_sdk.h"

#define SEND_LENGTH UNITREE_LEGGED_SDK::HIGH_CMD_LENGTH
#define RECV_LENGTH UNITREE_LEGGED_SDK::HIGH_CMD_LENGTH

class A1Wrapper
{
public:
  /*sport mode*/
  A1Wrapper(uint8_t sport_mode, int level)
  : udp(8081, "192.168.123.161", 8082, SEND_LENGTH, RECV_LENGTH),
    safety(UNITREE_LEGGED_SDK::LeggedType::A1)
  {
    run_mode = sport_mode;
    this->level = level;
    if (level == UNITREE_LEGGED_SDK::HIGHLEVEL) {
      udp.InitCmdData(highCmd);
    } else {
      udp.InitCmdData(lowCmd);
    }
  }
  /*basic mode*/
  explicit A1Wrapper(int level)
  : udp(level), safety(UNITREE_LEGGED_SDK::LeggedType::A1), run_mode(0)
  {
    this->level = level;
    if (level == UNITREE_LEGGED_SDK::HIGHLEVEL) {
      udp.InitCmdData(highCmd);
    } else {
      udp.InitCmdData(lowCmd);
    }
  }
  void UDPRecv() {udp.Recv();}

  void UDPSend() {udp.Send();}
  void set_velocity(float forwardSpeed, float sideSpeed, float rotateSpeed);
  void set_pose(float yaw, float pitch, float roll, float bodyHeight);
  bool set_mode(uint8_t mode);
  void recv_high_state();
  void recv_low_state();
  void recv_imu_msg();
  void recv_cartesian_msg();

  UNITREE_LEGGED_SDK::UDP udp;
  UNITREE_LEGGED_SDK::Safety safety;
  UNITREE_LEGGED_SDK::HighCmd highCmd {};
  UNITREE_LEGGED_SDK::LowCmd lowCmd {};
  UNITREE_LEGGED_SDK::LowState lowState;
  UNITREE_LEGGED_SDK::HighState highState;
  uint8_t run_mode;
  int level;
};

#endif  // A1_DRIVER__A1_WRAPPER_HPP_
