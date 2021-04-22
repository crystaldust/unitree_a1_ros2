//
// Created by sun on 2021/3/1.
//

#ifndef UNITREE_DRIVER_A1_ROS_H
#define UNITREE_DRIVER_A1_ROS_H

#include <memory>
#include "geometry_msgs/msg/twist.hpp"
#include "a1_msgs/msg/mode.hpp"
#include "a1_msgs/srv/state.hpp"
#include "rclcpp/rclcpp.hpp"
#include "a1_driver/A1_wrapper.h"

class A1ROS{
public:
    A1ROS(std::string node_name) : wrapper(A1Wrapper()) {
        this->node_name = node_name;
    };

    int node_init(int argc, char *argv[]);
    void requestHighState(const std::shared_ptr<a1_msgs::srv::State::Request> request,
                   std::shared_ptr<a1_msgs::srv::State::Response> response);
    A1Wrapper wrapper;
private:
    std::string node_name;
};

#endif //UNITREE_DRIVER_A1_ROS_H