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
    unitreeROS():Node("node"), wrapper(unitreeWrapper()){

        sub = this->create_subscription<geometry_msgs::msg::Twist>(
                "topic",
                10,
                std::bind(&unitreeROS::walkCallback,
                          this,
                          std::placeholders::_1)
                );

    }

private:

    void walkCallback(const geometry_msgs::msg::Twist::SharedPtr msg) {		
        wrapper.walkCmd(msg->linear.x, msg->linear.y, msg->angular.z);
    }
   unitreeWrapper wrapper;
    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr sub;
};


int main(int argc, char* argv[]){
    rclcpp::init(argc, argv);
    auto ros_node = std::make_shared<unitreeROS>();
    rclcpp::spin(ros_node);
    rclcpp::shutdown();
    return 0;
}
