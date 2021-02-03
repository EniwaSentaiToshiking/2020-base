/*
 * Created on Wed Feb 03 2021
 *
 * Copyright (c) 2021 Kazuki Hamaguchi
 */

#include "StraightBehaviorModel.h"

void StraightBehaviorModel::init()
{
    wheelDeviceDriver.init();
}

void StraightBehaviorModel::run(int pwm, StraightForwardOrBackward straightForwardOrBackward)
{
    switch (straightForwardOrBackward)
    {
    case NONE_F_B:
        break;

    case FORWARD:
        wheelDeviceDriver.setLeftPWM(pwm);
        wheelDeviceDriver.setRightPWM(pwm);
        break;

    case BACKWARD:
        wheelDeviceDriver.setLeftPWM(-pwm);
        wheelDeviceDriver.setRightPWM(-pwm);
        break;

    default:
        break;
    }
}

void StraightBehaviorModel::terminate()
{
    wheelDeviceDriver.terminate();
}