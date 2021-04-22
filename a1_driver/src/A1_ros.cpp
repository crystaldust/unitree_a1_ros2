//
// Created by sun on 2021/3/1.
//

#include "a1_driver/A1_ros.h"

void A1ROS::requestHighState(const std::shared_ptr<a1_msgs::srv::State::Request> request,
                   std::shared_ptr<a1_msgs::srv::State::Response> response)
{
    int i;
    wrapper.getHighState();
    response->levelflag = wrapper.state.levelFlag;
    response->commversion = wrapper.state.commVersion;
    response->robotid = wrapper.state.robotID;
    response->sn = wrapper.state.SN;
    response->bandwidth = wrapper.state.bandWidth;
    response->mode = wrapper.state.mode;
    //IMU
    response->imu.quaternion[0] = wrapper.state.imu.quaternion[0];
    response->imu.quaternion[1] = wrapper.state.imu.quaternion[1];
    response->imu.quaternion[2] = wrapper.state.imu.quaternion[2];
    response->imu.quaternion[3] = wrapper.state.imu.quaternion[3];
    response->imu.gyroscope[0] = wrapper.state.imu.gyroscope[0];
    response->imu.gyroscope[1] = wrapper.state.imu.gyroscope[1];
    response->imu.gyroscope[2] = wrapper.state.imu.gyroscope[2];
    response->imu.accelerometer[0] = wrapper.state.imu.accelerometer[0];
    response->imu.accelerometer[1] = wrapper.state.imu.accelerometer[1];
    response->imu.accelerometer[2] = wrapper.state.imu.accelerometer[2];
    response->imu.temperature = int(wrapper.state.imu.temperature);
    
    response->forwardspeed = wrapper.state.forwardSpeed;
    response->sidespeed    = wrapper.state.sideSpeed;
    response->rotatespeed  = wrapper.state.rotateSpeed;
    response->bodyheight = wrapper.state.bodyHeight;
    response->updownspeed = wrapper.state.updownSpeed;
    response->forwardposition = wrapper.state.forwardPosition;
    response->sideposition = wrapper.state.sidePosition;
    for(i = 0; i< 4; i++){
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
    for(i = 0; i < 40; i++){
        response->wirelessremote[i] = wrapper.state.wirelessRemote[i];
    }
    response->reserve = wrapper.state.reserve;
    response->crc = wrapper.state.crc;
}


int A1ROS::node_init(int argc, char *argv[]) {
    rclcpp::init(argc, argv);

    auto A1_node = rclcpp::Node::make_shared(this->node_name);
    auto A1_sub = A1_node->create_subscription<geometry_msgs::msg::Twist>(
            "cmd_vel",
            10,
            [this](geometry_msgs::msg::Twist::UniquePtr msg) {
                RCLCPP_INFO(rclcpp::get_logger("rcv_vel"),
                            "forwardSpeed[%0.2f],sideSpeed[%0.2f],rotateSpeed[%0.2f]", msg->linear.x,msg->linear.y,msg->angular.z);
                wrapper.walkCmd(msg->linear.x, msg->linear.y, msg->angular.z);
            }
    );
    auto mode_sub =  A1_node->create_subscription<a1_msgs::msg::Mode>(
            "cmd_mode",
            10,
            [this](a1_msgs::msg::Mode::UniquePtr msg){
                RCLCPP_INFO(rclcpp::get_logger("rcv_mode"), "set cmd mode: [%d] value[%0.2f]", msg->mode, msg->value);
                wrapper.setControlCmd(msg->mode, msg->value);
            }
    );

    auto service = A1_node->create_service<a1_msgs::srv::State>(
            "get_high_state",
            [this](const std::shared_ptr<a1_msgs::srv::State::Request> request,
                   std::shared_ptr<a1_msgs::srv::State::Response> response){
                requestHighState(request, response);
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
}
