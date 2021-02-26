//
// Created by sun on 2021/2/24.
//

#include <memory>
#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;

class PubNode: public rclcpp::Node
{
public:
    PubNode():Node("pub_node"), count_(0){
        walk_pub = this->create_publisher<geometry_msgs::msg::Twist>("topic", 10);
        timer_ = this->create_wall_timer(500ms, std::bind(&PubNode::pub_callback, this));
    }

private:
    void pub_callback(){
        geometry_msgs::msg::Twist msg;
        msg.linear.x = 0.1;
        msg.linear.y = 0.0;
        msg.angular.z = 0.0;
        RCLCPP_INFO(this->get_logger(), "sending");
        walk_pub->publish(msg);
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr walk_pub;
    size_t count_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<PubNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;

}

