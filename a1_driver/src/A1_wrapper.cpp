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

#include "a1_driver/A1_wrapper.hpp"
#include <time.h>

void A1Wrapper::set_velocity(
  float forwardSpeed, float sideSpeed,
  float rotateSpeed)
{
  UNITREE_LEGGED_SDK::HighCmd high_cmd{};

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

bool A1Wrapper::set_mode(uint8_t mode) {
  UNITREE_LEGGED_SDK::HighCmd high_cmd{};
  high_cmd.mode = mode;
  if (udp.SetSend(high_cmd) != 0) {
    return false;
  }

  return true;
}

void A1Wrapper::set_pose(float yaw, float pitch, float roll, float bodyHeight) {
  UNITREE_LEGGED_SDK::HighCmd high_cmd{};

  high_cmd.mode = CMD_SET_MODE_FORCE_STAND;
  high_cmd.yaw = yaw;
  high_cmd.pitch = pitch;
  high_cmd.roll = roll;
  high_cmd.bodyHeight = bodyHeight;
  udp.SetSend(high_cmd);
}

void A1Wrapper::recv_imu_msg() {udp.GetRecv(highState);}

void A1Wrapper::recv_cartesian_msg() {udp.GetRecv(highState);}

void A1Wrapper::recv_high_state() {udp.GetRecv(highState);}

void A1Wrapper::recv_low_state() { udp.GetRecv(lowState); }
