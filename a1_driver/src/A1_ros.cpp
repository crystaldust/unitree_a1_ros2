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

#include "a1_driver/A1_ros.hpp"

void A1ROS::get_high_state_msg(HighStateResponse response)
{
  wrapper.recv_high_state();
  response->levelflag = wrapper.highState.levelFlag;
  response->commversion = wrapper.highState.commVersion;
  response->robotid = wrapper.highState.robotID;
  response->sn = wrapper.highState.SN;
  response->bandwidth = wrapper.highState.bandWidth;
  response->mode = wrapper.highState.mode;
  // IMU
  for (int i = 0; i < UNITREE_A1_IMU_QUATERNION; i++) {
    response->imu.quaternion[i] = wrapper.highState.imu.quaternion[i];
  }
  for (int i = 0; i < UNITREE_A1_IMU_ANGULAR_VELOCITY; i++) {
    response->imu.gyroscope[i] = wrapper.highState.imu.gyroscope[i];
  }
  for (int i = 0; i < UNITREE_A1_IMU_ACCELEROMETER; i++) {
    response->imu.accelerometer[i] = wrapper.highState.imu.accelerometer[i];
  }
  response->imu.temperature =
    static_cast<int>(wrapper.highState.imu.temperature);
  response->forwardspeed = wrapper.highState.forwardSpeed;
  response->sidespeed = wrapper.highState.sideSpeed;
  response->rotatespeed = wrapper.highState.rotateSpeed;
  response->bodyheight = wrapper.highState.bodyHeight;
  response->updownspeed = wrapper.highState.updownSpeed;
  response->forwardposition = wrapper.highState.forwardPosition;
  response->sideposition = wrapper.highState.sidePosition;
  // Cartesian
  for (int i = 0; i < UNITREE_A1_DOG_LEGS; i++) {
    response->footposition2body[i].x = wrapper.highState.footPosition2Body[i].x;
    response->footposition2body[i].y = wrapper.highState.footPosition2Body[i].y;
    response->footposition2body[i].z = wrapper.highState.footPosition2Body[i].z;
    response->footspeed2body[i].x = wrapper.highState.footSpeed2Body[i].x;
    response->footspeed2body[i].y = wrapper.highState.footSpeed2Body[i].y;
    response->footspeed2body[i].z = wrapper.highState.footSpeed2Body[i].z;
    response->footforce[i] = wrapper.highState.footForce[i];
    response->footforceest[i] = wrapper.highState.footForceEst[i];
  }
  response->tick = wrapper.highState.tick;
  for (int i = 0; i < UNITREE_A1_WIRELESS_REMOTE_BYTE; i++) {
    response->wirelessremote[i] = wrapper.highState.wirelessRemote[i];
  }
  response->reserve = wrapper.highState.reserve;
  response->crc = wrapper.highState.crc;
}

void A1ROS::get_low_state_msg(LowStateResponse response)
{
  wrapper.recv_low_state();
  response->levelflag = wrapper.lowState.levelFlag;
  response->commversion = wrapper.lowState.commVersion;
  response->robotid = wrapper.lowState.robotID;
  response->sn = wrapper.lowState.SN;
  response->bandwidth = wrapper.lowState.bandWidth;
  // IMU
  for (int i = 0; i < UNITREE_A1_IMU_QUATERNION; i++) {
    response->imu.quaternion[i] = wrapper.lowState.imu.quaternion[i];
  }
  for (int i = 0; i < UNITREE_A1_IMU_ANGULAR_VELOCITY; i++) {
    response->imu.gyroscope[i] = wrapper.lowState.imu.gyroscope[i];
  }
  for (int i = 0; i < UNITREE_A1_IMU_ACCELEROMETER; i++) {
    response->imu.accelerometer[i] = wrapper.lowState.imu.accelerometer[i];
  }
  response->imu.temperature =
    static_cast<int>(wrapper.lowState.imu.temperature);

  for (int i = 0; i < UNITREE_A1_MOTOR_STATE_ELEMENT_NUMS; i++) {
    response->motorstate[i].mode = wrapper.lowState.motorState[i].mode;
    response->motorstate[i].q = wrapper.lowState.motorState[i].q;
    response->motorstate[i].dq = wrapper.lowState.motorState[i].dq;
    response->motorstate[i].ddq = wrapper.lowState.motorState[i].ddq;
    response->motorstate[i].tau_est = wrapper.lowState.motorState[i].tauEst;
    response->motorstate[i].q_raw = wrapper.lowState.motorState[i].q_raw;
    response->motorstate[i].dq_raw = wrapper.lowState.motorState[i].dq_raw;
    response->motorstate[i].ddq_raw = wrapper.lowState.motorState[i].ddq_raw;
    response->motorstate[i].temperature =
      wrapper.lowState.motorState[i].temperature;
    response->motorstate[i].reserve[0] =
      wrapper.lowState.motorState[i].reserve[0];
    response->motorstate[i].reserve[1] =
      wrapper.lowState.motorState[i].reserve[1];
  }

  for (int i = 0; i < UNITREE_A1_DOG_LEGS; i++) {
    response->footforce[i] = wrapper.lowState.footForce[i];
    response->footforceest[i] = wrapper.lowState.footForceEst[i];
  }
  response->tick = wrapper.lowState.tick;
  for (int i = 0; i < UNITREE_A1_WIRELESS_REMOTE_BYTE; i++) {
    response->wirelessremote[i] = wrapper.lowState.wirelessRemote[i];
  }
  response->reserve = wrapper.lowState.reserve;
  response->crc = wrapper.lowState.crc;
}

void A1ROS::get_imu_msg(ImuResponse response)
{
  wrapper.recv_imu_msg();
  for (int i = 0; i < UNITREE_A1_IMU_QUATERNION; i++) {
    response->quaternion[i] = wrapper.highState.imu.quaternion[i];
  }
  for (int i = 0; i < UNITREE_A1_IMU_ANGULAR_VELOCITY; i++) {
    response->gyroscope[i] = wrapper.highState.imu.gyroscope[i];
  }

  for (int i = 0; i < UNITREE_A1_IMU_ACCELEROMETER; i++) {
    response->accelerometer[i] = wrapper.highState.imu.accelerometer[i];
  }
  response->temperature = static_cast<int>(wrapper.highState.imu.temperature);
}

void A1ROS::get_cartesian_msg(CartesianResponse response)
{
  wrapper.recv_cartesian_msg();
  for (int i = 0; i < UNITREE_A1_DOG_LEGS; i++) {
    response->footposition2body[i].x = wrapper.highState.footPosition2Body[i].x;
    response->footposition2body[i].y = wrapper.highState.footPosition2Body[i].y;
    response->footposition2body[i].z = wrapper.highState.footPosition2Body[i].z;
    response->footspeed2body[i].x = wrapper.highState.footSpeed2Body[i].x;
    response->footspeed2body[i].y = wrapper.highState.footSpeed2Body[i].y;
    response->footspeed2body[i].z = wrapper.highState.footSpeed2Body[i].z;
  }
}

int A1ROS::node_init(int argc, char * argv[])
{
  rclcpp::init(argc, argv);

  auto A1_node = rclcpp::Node::make_shared(this->node_name);
  auto vel_sub = A1_node->create_subscription<geometry_msgs::msg::Twist>(
    ROS2_TOPIC_SET_VELOCITY, 10,
    [this](geometry_msgs::msg::Twist::UniquePtr msg) {
      RCLCPP_INFO(
        rclcpp::get_logger("rcv_vel"),
        "forwardSpeed[%0.2f],sideSpeed[%0.2f],rotateSpeed[%0.2f]",
        msg->linear.x, msg->linear.y, msg->angular.z);
      wrapper.set_velocity(msg->linear.x, msg->linear.y, msg->angular.z);
    });
  auto pose_sub = A1_node->create_subscription<a1_msgs::msg::Pose>(
    ROS2_TOPIC_SET_POSE, 10, [this](a1_msgs::msg::Pose::UniquePtr msg) {
      RCLCPP_INFO(
        rclcpp::get_logger("rcv_pose"),
        "yaw[%0.2f], pitch[%0.2f], roll[%0.2f], bodyHeight[%0.2f]",
        msg->yaw, msg->pitch, msg->roll, msg->bodyheight);
      wrapper.set_pose(msg->yaw, msg->pitch, msg->roll, msg->bodyheight);
    });
  auto mode_service = A1_node->create_service<a1_msgs::srv::Mode>(
    ROS2_SERVICE_SET_MODE,
    [this](const ModeRequest request, ModeResponse response) {
      response->value = wrapper.set_mode(request->mode);
    });
  auto hgih_state_service = A1_node->create_service<a1_msgs::srv::HighState>(
    ROS2_SERVICE_GET_HIGH_STATE_MSG,
    [this](const HighStateRequest request, HighStateResponse response) {
      get_high_state_msg(response);
    });
  auto low_state_service = A1_node->create_service<a1_msgs::srv::LowState>(
    ROS2_SERVICE_GET_LOW_STATE_MSG,
    [this](const LowStateRequest request, LowStateResponse response) {
      get_low_state_msg(response);
    });
  auto imu_service = A1_node->create_service<a1_msgs::srv::Imu>(
    ROS2_SERVICE_GET_IMU_MSG,
    [this](const ImuRequest request, ImuResponse response) {
      get_imu_msg(response);
    });
  auto cartesian_service = A1_node->create_service<a1_msgs::srv::Cartesian>(
    ROS2_SERVICE_GET_CARTESIAN_MSG,
    [this](const CartesianRequest request, CartesianResponse response) {
      get_cartesian_msg(response);
    });
  UNITREE_LEGGED_SDK::InitEnvironment();
  float dt = 0.002f;
  UNITREE_LEGGED_SDK::LoopFunc loop_udpRecv(
    "udp_recv", dt, 3, boost::bind(&A1Wrapper::UDPRecv, &wrapper));
  UNITREE_LEGGED_SDK::LoopFunc loop_udpSend(
    "udp_send", dt, 3, boost::bind(&A1Wrapper::UDPSend, &wrapper));
  loop_udpRecv.start();
  loop_udpSend.start();
  rclcpp::spin(A1_node);
  rclcpp::shutdown();
  return 0;
}
