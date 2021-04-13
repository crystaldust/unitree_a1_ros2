//
// Created by sun on 2021/3/1.
//

#include "a1_driver/A1_ros.h"

void A1ROS::get_high_state_msg(const std::shared_ptr<a1_msgs::srv::HighState::Request> request,
                   std::shared_ptr<a1_msgs::srv::HighState::Response> response) {
    request->flag = UNUSED_VARIABLE_MARK;
    wrapper.recv_high_state(response);
}

void A1ROS::get_imu_msg(const std::shared_ptr<a1_msgs::srv::Imu::Request> request,
                  std::shared_ptr<a1_msgs::srv::Imu::Response> response) {
    request->flag = UNUSED_VARIABLE_MARK;
    wrapper.recv_imu_msg(response);
}

void A1ROS::get_cartesian_msg(const std::shared_ptr<a1_msgs::srv::Cartesian::Request> request,
                std::shared_ptr<a1_msgs::srv::Cartesian::Response> response) {
    request->flag = UNUSED_VARIABLE_MARK;
    wrapper.recv_cartesian_msg(response);
}

void A1ROS::set_mode(const std::shared_ptr<a1_msgs::srv::Mode::Request> request,
                  std::shared_ptr<a1_msgs::srv::Mode::Response> response) {
    wrapper.set_mode(request->mode);
    response->value = UNUSED_VARIABLE_MARK;
}
int A1ROS::node_init(int argc, char *argv[]) {
    rclcpp::init(argc, argv);

    auto A1_node = rclcpp::Node::make_shared(this->node_name);
    auto vel_sub = A1_node->create_subscription<geometry_msgs::msg::Twist>(
            ROS2_TOPIC_SET_VELOCITY,
            10,
            [this](geometry_msgs::msg::Twist::UniquePtr msg) {
                RCLCPP_INFO(rclcpp::get_logger("rcv_vel"),
                            "forwardSpeed[%0.2f],sideSpeed[%0.2f],rotateSpeed[%0.2f]", 
                            msg->linear.x,msg->linear.y,msg->angular.z);
                wrapper.set_velocity(msg->linear.x, msg->linear.y, msg->angular.z);
            }
    );
    auto pose_sub = A1_node->create_subscription<a1_msgs::msg::Pose>(
            ROS2_TOPIC_SET_POSE,
            10,
            [this](a1_msgs::msg::Pose::UniquePtr msg) {
                RCLCPP_INFO(rclcpp::get_logger("rcv_pose"),
                            "yaw[%0.2f], pitch[%0.2f], roll[%0.2f], bodyHeight[%0.2f]", 
                            msg->yaw, msg->pitch, msg->roll, msg->bodyheight);
                wrapper.set_pose(msg->yaw, msg->pitch, msg->roll, msg->bodyheight);
            }
    );
    auto mode_service = A1_node->create_service<a1_msgs::srv::Mode>(
            ROS2_SERVICE_SET_MODE,
            [this](const std::shared_ptr<a1_msgs::srv::Mode::Request> request,
                   std::shared_ptr<a1_msgs::srv::Mode::Response> response) {
                set_mode(request, response);
            }
    );
    auto hgih_state_service = A1_node->create_service<a1_msgs::srv::HighState>(
            ROS2_SERVICE_GET_HIGH_STATE_MSG,
            [this](const std::shared_ptr<a1_msgs::srv::HighState::Request> request,
                   std::shared_ptr<a1_msgs::srv::HighState::Response> response) {
                get_high_state_msg(request, response);
            }
    );

    auto imu_service = A1_node->create_service<a1_msgs::srv::Imu>(
            ROS2_SERVICE_GET_IMU_MSG,
            [this](const std::shared_ptr<a1_msgs::srv::Imu::Request> request,
                   std::shared_ptr<a1_msgs::srv::Imu::Response> response) {
                get_imu_msg(request, response);
            }
    );
    auto cartesian_service = A1_node->create_service<a1_msgs::srv::Cartesian>(
            ROS2_SERVICE_GET_CARTESIAN_MSG,
            [this](const std::shared_ptr<a1_msgs::srv::Cartesian::Request> request,
                   std::shared_ptr<a1_msgs::srv::Cartesian::Response> response) {
                get_cartesian_msg(request, response);
            }
    );
    UNITREE_LEGGED_SDK::InitEnvironment();
    float dt = 0.002f;
    UNITREE_LEGGED_SDK::LoopFunc loop_udpRecv("udp_recv", dt, 3, boost::bind(&A1Wrapper::UDPRecv, &wrapper));
    UNITREE_LEGGED_SDK::LoopFunc loop_udpSend("udp_send", dt, 3, boost::bind(&A1Wrapper::UDPSend, &wrapper));
    loop_udpRecv.start();
    loop_udpSend.start();
    rclcpp::spin(A1_node);
    rclcpp::shutdown();
    return 0;
}
