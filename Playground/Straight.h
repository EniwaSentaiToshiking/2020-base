#pragma once
#include "Motor.h"

using namespace ev3api;

class Straight
{
    public:
        Straight();
        void init();
        void terminate();
        void forward();
        void backward();

    private:
        Motor leftWheel;
        Motor rightWheel;
        const int8_t pwm = (Motor::PWM_MAX)/2;
};