//
// Created by sun on 2021/3/1.
//

#ifndef A1_DRIVER__A1_WRAPPER_H_
#define A1_DRIVER__A1_WRAPPER_H_

#include <iostream>
#include "a1_comm/A1_comm.h"
#include "unitree_legged_sdk/unitree_legged_sdk.h"

#define SEND_LENGTH UNITREE_LEGGED_SDK::HIGH_CMD_LENGTH
#define RECV_LENGTH UNITREE_LEGGED_SDK::HIGH_CMD_LENGTH

class A1Wrapper {
 public:
  /*sport mode*/
  explicit A1Wrapper(uint8_t sport_mode)
      : udp(8081, "192.168.123.161", 8082, SEND_LENGTH, RECV_LENGTH),
        safety(UNITREE_LEGGED_SDK::LeggedType::A1) {
    memset(&cmd, 0, sizeof(cmd));
    r_mode = sport_mode;
    udp.InitCmdData(cmd);
  }
  /*basic mode*/
  A1Wrapper()
      : udp(UNITREE_LEGGED_SDK::HIGHLEVEL),
        safety(UNITREE_LEGGED_SDK::LeggedType::A1),
        r_mode(0) {
    udp.InitCmdData(cmd);
  }
  void UDPRecv() { udp.Recv(); }

  void UDPSend() { udp.Send(); }
  void set_velocity(float forwardSpeed, float sideSpeed, float rotateSpeed);
  void set_pose(float yaw, float pitch, float roll, float bodyHeight);
  bool set_mode(uint8_t mode);
  void recv_high_state();
  void recv_imu_msg();
  void recv_cartesian_msg();
  UNITREE_LEGGED_SDK::UDP udp;
  UNITREE_LEGGED_SDK::Safety safety;
  UNITREE_LEGGED_SDK::HighCmd cmd;
  UNITREE_LEGGED_SDK::HighState state;
  uint8_t r_mode;
};

#endif  // A1_DRIVER__A1_WRAPPER_H_

