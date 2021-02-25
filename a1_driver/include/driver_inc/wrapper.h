#include "unitree_inc/unitree_legged_sdk.h"
#include <math.h>
#include <iostream>
#include <unistd.h>
#include <string.h>

using namespace UNITREE_LEGGED_SDK;
class unitreeWrapper{
public:
    unitreeWrapper(){

    }
    void UDPRecv();
    void UDPSend();
private:
    void robotToLocalTime();
    void walkCmd(float forwardSpeed, float sideSpeed, float rotateSpeed, float time);
    void standCmd(unit8_t mode);
    UDP robot_command;
};