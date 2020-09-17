#include "Straight.h"

Straight::Straight() : leftWheel(PORT_B), rightWheel(PORT_C)
{
}

Straight::~Straight()
{
}

void Straight::init()
{
}

void Straight::terminate()
{
    leftWheel.stop();
    rightWheel.stop();
}

void Straight::forward()
{
    int left_pwm = pwm;
    int right_pwm = pwm;
    leftWheel.setPWM(left_pwm);
    rightWheel.setPWM(right_pwm);
}

void Straight::backward()
{
    int left_pwm = -pwm;
    int right_pwm = -pwm;
    leftWheel.setPWM(left_pwm);
    rightWheel.setPWM(right_pwm);
}
