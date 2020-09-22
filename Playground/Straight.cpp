#include "Straight.h"

Straight::Straight() : leftWheel(PORT_B), rightWheel(PORT_C)
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
    leftWheel.setPWM(pwm);
    rightWheel.setPWM(pwm);
}

void Straight::backward()
{
    leftWheel.setPWM(-pwm);
    rightWheel.setPWM(-pwm);
}
