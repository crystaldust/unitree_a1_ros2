//
// Created by sun on 2021/3/1.
//

#include "a1_driver/A1_ros.h"

int A1ROS::node_init(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    auto A1_node = rclcpp::Node::make_shared(this->node_name);
    auto A1_sub = A1_node->create_subscription<geometry_msgs::msg::Twist>(
            "unitree_a1/cmd_vel",
            10,
            [this, A1_node](geometry_msgs::msg::Twist::UniquePtr msg) {
                RCLCPP_INFO(A1_node->get_logger(),
                            "received: speed = %f", msg->linear.x);
                wrapper.walkCmd(msg->linear.x, msg->linear.y, msg->angular.z);
            }
    );
//    A1_node->create_subscription<...>();
    UNITREE_LEGGED_SDK::InitEnvironment();
    float dt = 0.002f;
    UNITREE_LEGGED_SDK::LoopFunc loop_udpRecv("udp_recv", dt, 3, boost::bind(&A1Wrapper::UDPRecv, &wrapper));
    UNITREE_LEGGED_SDK::LoopFunc loop_udpSend("udp_send", dt, 3, boost::bind(&A1Wrapper::UDPSend, &wrapper));
    loop_udpRecv.start();
    loop_udpSend.start();
    rclcpp::spin(A1_node);
    rclcpp::shutdown();
}
