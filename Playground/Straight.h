#pragma once
#include "Motor.h"

using namespace ev3api;

class Straight
{
    public:
        Straight();
        void forward();
        void backward();
        void init();
        void terminate();
        virtual ~Straight();

    private:
        Motor leftWheel;
        Motor rightWheel;
        const int8_t pwm = (Motor::PWM_MAX);
};