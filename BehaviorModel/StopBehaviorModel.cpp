/*
 * Created on Wed Feb 03 2021
 *
 * Copyright (c) 2021 Kazuki Hamaguchi
 */

#include "StopBehaviorModel.h"

void StopBehaviorModel::init()
{
    wheelDeviceDriver.init();
}

void StopBehaviorModel::run(int pwm)
{
    wheelDeviceDriver.terminate();
    // pwm = 0;
    // wheelDeviceDriver.setLeftPWM(pwm);
    // wheelDeviceDriver.setRightPWM(pwm);
}

void StopBehaviorModel::terminate()
{
    wheelDeviceDriver.terminate();
}