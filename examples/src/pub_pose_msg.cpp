#include <memory>
#include <chrono>
#include <unistd.h>
#include "rclcpp/rclcpp.hpp"
#include "a1_comm/A1_comm.h"

using namespace std::chrono_literals;

class PubNode : public rclcpp::Node {
public:
    PubNode(float yaw, float pitch, float roll, float bodyHeight) : Node("pub_node"), count_(0) {
        m_yaw = yaw;
        m_pitch = pitch;
        m_roll = roll;
        m_bodyHeight = bodyHeight;
        pose_pub = this->create_publisher<a1_msgs::msg::Pose>(ROS2_TOPIC_SET_POSE, 10);
        timer_ = this->create_wall_timer(500ms, std::bind(&PubNode::pub_callback, this));
    }
private:
    void pub_callback() {
        a1_msgs::msg::Pose msg;
        msg.yaw = m_yaw;
        msg.pitch = m_pitch;
        msg.roll = m_roll;
        msg.bodyheight = m_bodyHeight;
        RCLCPP_INFO(this->get_logger(), "yaw[%f], pitch[%f], roll[%f], bodyHeight[%f]",msg.yaw, msg.pitch, msg.roll, msg.bodyheight);
        pose_pub->publish(msg);
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<a1_msgs::msg::Pose>::SharedPtr pose_pub;
    size_t count_;
    float m_yaw;
    float m_pitch;
    float m_roll;
    float m_bodyHeight;
};

float str_to_float(char *str) {
    int i = 0, flag = 0;
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
    if (argc < 5) {
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Invalid number of input parameters");
        return -1;
    }
    for (int i = 1; i <= 3; i++) {
        if (strlen(argv[i]) > 7 || strstr(argv[i], ".") == NULL || str_to_float(argv[i]) < -1 || str_to_float(argv[i]) > 1) {
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "The input parameter content is not valid");
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "ros2 run a1_example pub_pose_msg -0.52 1.0 0.09 0.48");
            return -1;
        }
    }
    
    float yaw   = str_to_float(argv[1]);
    float pitch = str_to_float(argv[2]);
    float roll  = str_to_float(argv[3]);
    float bodyHeight = str_to_float(argv[4]);
    auto node = std::make_shared<PubNode>(yaw, pitch, roll, bodyHeight);
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}

