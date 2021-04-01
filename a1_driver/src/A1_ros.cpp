//
// Created by sun on 2021/3/1.
//

#include "a1_driver/A1_ros.h"

void A1ROS::get_high_state_msg(const std::shared_ptr<a1_msgs::srv::HighState::Request> request,
                   std::shared_ptr<a1_msgs::srv::HighState::Response> response) {
    int i;
    wrapper.recv_high_state();
    response->levelflag = wrapper.state.levelFlag;
    response->commversion = wrapper.state.commVersion;
    response->robotid = wrapper.state.robotID;
    response->sn = wrapper.state.SN;
    response->bandwidth = wrapper.state.bandWidth;
    response->mode = wrapper.state.mode;
    //IMU
    for (i = 0; i < UNITREE_A1_IMU_QUATERNION; i++) {
        response->imu.quaternion[i] = wrapper.state.imu.quaternion[i];
    }
    
    for (i = 0; i < UNITREE_A1_IMU_ANGULAR_VELOCITY; i++) {
        response->imu.gyroscope[i] = wrapper.state.imu.gyroscope[i];
    }

    for (i = 0; i < UNITREE_A1_IMU_ACCELEROMETER; i++) {
        response->imu.accelerometer[i] = wrapper.state.imu.accelerometer[i];
    }
    response->imu.temperature = int(wrapper.state.imu.temperature);
    
    response->forwardspeed = wrapper.state.forwardSpeed;
    response->sidespeed    = wrapper.state.sideSpeed;
    response->rotatespeed  = wrapper.state.rotateSpeed;
    response->bodyheight = wrapper.state.bodyHeight;
    response->updownspeed = wrapper.state.updownSpeed;
    response->forwardposition = wrapper.state.forwardPosition;
    response->sideposition = wrapper.state.sidePosition;
    for(i = 0; i< UNITREE_A1_DOG_LEGS; i++) {
        response->footposition2body[i].x = wrapper.state.footPosition2Body[i].x;
        response->footposition2body[i].y = wrapper.state.footPosition2Body[i].y;
        response->footposition2body[i].z = wrapper.state.footPosition2Body[i].z;
        response->footspeed2body[i].x    = wrapper.state.footSpeed2Body[i].x;
        response->footspeed2body[i].y    = wrapper.state.footSpeed2Body[i].y;
        response->footspeed2body[i].z    = wrapper.state.footSpeed2Body[i].z;
        response->footforce[i]           = wrapper.state.footForce[i];
        response->footforceest[i]        = wrapper.state.footForceEst[i];
    }
    response->tick = wrapper.state.tick;
    for(i = 0; i < UNITREE_A1_WIRELESS_REMOTE_BYTE; i++) {
        response->wirelessremote[i] = wrapper.state.wirelessRemote[i];
    }
    response->reserve = wrapper.state.reserve;
    response->crc = wrapper.state.crc;
}

void A1ROS::get_imu_msg(const std::shared_ptr<a1_msgs::srv::Imu::Request> request,
                  std::shared_ptr<a1_msgs::srv::Imu::Response> response) {
    int i;
    wrapper.recv_high_state();
    //IMU
    for (i = 0; i < UNITREE_A1_IMU_QUATERNION; i++) {
        response->imu.quaternion[i] = wrapper.state.imu.quaternion[i];
    }
    
    for (i = 0; i < UNITREE_A1_IMU_ANGULAR_VELOCITY; i++) {
        response->imu.gyroscope[i] = wrapper.state.imu.gyroscope[i];
    }

    for (i = 0; i < UNITREE_A1_IMU_ACCELEROMETER; i++) {
        response->imu.accelerometer[i] = wrapper.state.imu.accelerometer[i];
    }
    response->imu.temperature = int(wrapper.state.imu.temperature);
}

void A1ROS::set_mode(const std::shared_ptr<a1_msgs::srv::Mode::Request> request,
                  std::shared_ptr<a1_msgs::srv::Mode::Response> response) {
    wrapper.mode_set_cmd(request->mode);
}
int A1ROS::node_init(int argc, char *argv[]) {
    rclcpp::init(argc, argv);

    auto A1_node = rclcpp::Node::make_shared(this->node_name);
    auto A1_sub = A1_node->create_subscription<geometry_msgs::msg::Twist>(
            ROS2_TOPIC_SET_VELOCITY,
            10,
            [this](geometry_msgs::msg::Twist::UniquePtr msg) {
                RCLCPP_INFO(rclcpp::get_logger("rcv_vel"),
                            "forwardSpeed[%0.2f],sideSpeed[%0.2f],rotateSpeed[%0.2f]", msg->linear.x,msg->linear.y,msg->angular.z);
                wrapper.velocity_set_cmd(msg->linear.x, msg->linear.y, msg->angular.z);
            }
    );
    auto mode_service = A1_node->create_service<a1_msgs::srv::Mode>(
            ROS2_TOPIC_SET_MODE,
            [this](const std::shared_ptr<a1_msgs::srv::Mode::Request> request,
                   std::shared_ptr<a1_msgs::srv::Mode::Response> response) {
                set_mode(request, response);
            }
    );
    auto hgih_state_service = A1_node->create_service<a1_msgs::srv::HighState>(
            ROS2_TOPIC_GET_HIGH_STATE_MSG,
            [this](const std::shared_ptr<a1_msgs::srv::HighState::Request> request,
                   std::shared_ptr<a1_msgs::srv::HighState::Response> response) {
                get_high_state_msg(request, response);
            }
    );

    auto imu_service = A1_node->create_service<a1_msgs::srv::Imu>(
            ROS2_TOPIC_GET_IMU_MSG,
            [this](const std::shared_ptr<a1_msgs::srv::Imu::Request> request,
                   std::shared_ptr<a1_msgs::srv::Imu::Response> response) {
                get_imu_msg(request, response);
            }
    );
    UNITREE_LEGGED_SDK::InitEnvironment();
    float dt = 0.002f;
    UNITREE_LEGGED_SDK::LoopFunc loop_udpRecv("udp_recv", dt, 1, boost::bind(&A1Wrapper::UDPRecv, &wrapper));
    UNITREE_LEGGED_SDK::LoopFunc loop_udpSend("udp_send", dt, 1, boost::bind(&A1Wrapper::UDPSend, &wrapper));
    loop_udpRecv.start();
    loop_udpSend.start();
    rclcpp::spin(A1_node);
    rclcpp::shutdown();
}