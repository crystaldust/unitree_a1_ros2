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

#ifndef A1_DRIVER__A1_ROS_HPP_
#define A1_DRIVER__A1_ROS_HPP_

#include <memory>
#include <string>
#include "a1_comm/A1_comm.hpp"
#include "a1_driver/A1_wrapper.hpp"
#include "a1_msgs/msg/pose.hpp"
#include "a1_msgs/srv/cartesian.hpp"
#include "a1_msgs/srv/high_state.hpp"
#include "a1_msgs/srv/imu.hpp"
#include "a1_msgs/srv/low_state.hpp"
#include "a1_msgs/srv/mode.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "rclcpp/rclcpp.hpp"

class A1ROS
{
public:
  A1ROS(std::string node_name, int level)
  : wrapper(A1Wrapper(level))
  {
    this->node_name = node_name;
  }
  A1ROS(std::string node_name, uint8_t sport_mode, int level)
  : wrapper(A1Wrapper(sport_mode, level))
  {
    this->node_name = node_name;
  }
  int node_init(int argc, char * argv[]);
  void get_high_state_msg(
    std::shared_ptr<a1_msgs::srv::HighState::Response> response);

  void get_low_state_msg(
    std::shared_ptr<a1_msgs::srv::LowState::Response> response);
  void get_imu_msg(std::shared_ptr<a1_msgs::srv::Imu::Response> response);
  void get_cartesian_msg(
    std::shared_ptr<a1_msgs::srv::Cartesian::Response> response);
  A1Wrapper wrapper;

private:
  std::string node_name;
  using ModeRequest = std::shared_ptr<a1_msgs::srv::Mode::Request>;
  using ModeResponse = std::shared_ptr<a1_msgs::srv::Mode::Response>;
  using HighStateRequest = std::shared_ptr<a1_msgs::srv::HighState::Request>;
  using HighStateResponse = std::shared_ptr<a1_msgs::srv::HighState::Response>;
  using LowStateRequest = std::shared_ptr<a1_msgs::srv::LowState::Request>;
  using LowStateResponse = std::shared_ptr<a1_msgs::srv::LowState::Response>;
  using ImuRequest = std::shared_ptr<a1_msgs::srv::Imu::Request>;
  using ImuResponse = std::shared_ptr<a1_msgs::srv::Imu::Response>;
  using CartesianRequest = std::shared_ptr<a1_msgs::srv::Cartesian::Request>;
  using CartesianResponse = std::shared_ptr<a1_msgs::srv::Cartesian::Response>;
};

#endif  // A1_DRIVER__A1_ROS_HPP_
