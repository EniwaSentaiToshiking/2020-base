/*
 * Created on Wed Feb 03 2021
 *
 * Copyright (c) 2021 Kazuki Hamaguchi
 */

#pragma once

#include "Motor.h"
#include "DebugUtil.h"
#include <math.h>
#include <stdlib.h>

using namespace ev3api;

class ArmDeviceDriver
{
    Motor armMotor;

public:
    ArmDeviceDriver();
    void init();
    void resetArmAngle();
    void rotate(int32_t angle);
    void setPWM(int armPWM);
    void rotateDefault();
    void terminate();
    ~ArmDeviceDriver();

private:
    const int DEFAULT_ANGLE = -55;

    const int KP = 2.5F;
    const int PWM_ABS_MAX = 60;
    /* debug */
    DebugUtil d;
    // FILE *file;
};