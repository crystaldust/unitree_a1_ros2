//
// Created by sun on 2021/2/24.
//

#include <memory>
#include "geometry_msgs/msg/twist.hpp"
#include "rclcpp/rclcpp.hpp"
#include "unitree_driver/unitree_wrapper.h"

class unitreeROS : public rclcpp::Node
{
public:
    unitreeROS():Node("node"){

        sub = this->create_subscription<geometry_msgs::msg::Twist>(
                "topic",
                10,
                std::bind(&unitreeROS::walkCallback,
                          this,
                          std::placeholders::_1)
                );
    }
    udpWrapper wrapper = udpWrapper();

private:

    void walkCallback(const geometry_msgs::msg::Twist::SharedPtr msg) {
        wrapper.walkCmd(msg->linear.x, msg->linear.y, msg->angular.z);
    }
    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr sub;
};


int main(int argc, char* argv[]){
    UNITREE_LEGGED_SDK::InitEnvironment();


    rclcpp::init(argc, argv);
    auto ros_node = std::make_shared<unitreeROS>();
    float dt = 0.002f;

    UNITREE_LEGGED_SDK::LoopFunc loop_udpRecv("udp_recv", dt, 3, boost::bind(&udpWrapper::UDPRecv, &ros_node->wrapper));
    UNITREE_LEGGED_SDK::LoopFunc loop_udpSend("udp_send", dt, 3, boost::bind(&udpWrapper::UDPSend, &ros_node->wrapper));
    loop_udpRecv.start();
    loop_udpSend.start();

    rclcpp::spin(ros_node);
    rclcpp::shutdown();
    return 0;
}
