#include <memory>
#include <chrono>
#include <unistd.h>
#include "rclcpp/rclcpp.hpp"
#include "comm/comm_ros.h"

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
    void client_node();
private:
    void pub_callback() {
        a1_msgs::msg::Pose msg;
        msg.yaw = m_yaw;
        msg.pitch = m_pitch;
        msg.roll = m_roll;
        msg.bodyheight = m_bodyHeight;
        RCLCPP_INFO(this->get_logger(), "sending");
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

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    
    auto node = std::make_shared<PubNode>(0.1, 0.1, 0, 0.5);
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}

