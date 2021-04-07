//
// Created by sun on 2021/2/24.
//

#include <memory>
#include <chrono>
#include <unistd.h>
#include "rclcpp/rclcpp.hpp"
#include "a1_comm/A1_comm.h"


using namespace std::chrono_literals;

class PubNode : public rclcpp::Node {
public:
    PubNode(float forwardSpeed, float sideSpeed, float rotateSpeed) : Node("pub_node"), count_(0) {
        m_forwardSpeed = forwardSpeed;
        m_sideSpeed = sideSpeed;
        m_rotateSpeed = rotateSpeed;
        walk_pub = this->create_publisher<geometry_msgs::msg::Twist>(ROS2_TOPIC_SET_VELOCITY, 10);
        timer_ = this->create_wall_timer(500ms, std::bind(&PubNode::pub_callback, this));
    }
private:
    void pub_callback() {
        geometry_msgs::msg::Twist msg;
        msg.linear.x = m_forwardSpeed;
        msg.linear.y = m_sideSpeed;
        msg.angular.z = m_rotateSpeed;
        RCLCPP_INFO(this->get_logger(), "sending forwardSpeed[%f],sideSpeed[%f],rotateSpeed[%f]", msg.linear.x, msg.linear.y, msg.angular.z);
        walk_pub->publish(msg);
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr walk_pub;
    size_t count_;
    float m_forwardSpeed;
    float m_sideSpeed;
    float m_rotateSpeed;
};

float str_to_float(char *str) {
    int i = 0, flag  = 0;
    int base = 1;
    float integer = 0, decimal = 0;
    float res;
    
    while(*(str + i) != '\0') {
        if (*(str + i) == '-') {
            flag = 1;
            i++;
            continue;
        }
        while(*(str + i) >= '0' && *(str + i) <= '9') {
            integer = integer * 10 + *(str + i) - '0';
            i++;
        }
        i++;
        while(*(str + i) >= '0' && *(str + i) <= '9') {
            decimal = decimal * 10 + *(str + i) - '0';
            base *= 10;
            i++;
        }
    }
    res = integer + decimal/base;
    if (flag == 1) {
        res = 0 - res;
    }
    return res;
}
int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    float forwardSpeed;
    float sideSpeed;
    float rotateSpeed;

    if (argc < 4) {
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Invalid number of input parameters");
        return -1;
    }
    for (int i = 1; i <= 3; i++) {
        if (strlen(argv[i]) > 7 || strstr(argv[i], ".") == NULL || str_to_float(argv[i]) < -1 || str_to_float(argv[i]) > 1) {
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "The input parameter content is not valid");
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "ros2 run a1_example pub_vel_msg -0.52 1.0 0.09");
            return -1;
        }
    }
    
    forwardSpeed = str_to_float(argv[1]);
    sideSpeed = str_to_float(argv[2]);
    rotateSpeed = str_to_float(argv[3]);
    auto node = std::make_shared<PubNode>(forwardSpeed, sideSpeed, rotateSpeed);
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}

