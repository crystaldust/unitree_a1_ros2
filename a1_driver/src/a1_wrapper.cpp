class unitreeWrapper{
public:
    unitreeWrapper(){

    }

private:
    void robotToLocalTime();
    void walkCmd(float forwardSpeed, float sideSpeed, float rotateSpeed, float time);
    void standCmd();
    udp robot_command;
};

void unitreeWrapper::walkCmd(float forwardSpeed, float sideSpeed, float rotateSpeed, float time) {
//    build udp command


}
