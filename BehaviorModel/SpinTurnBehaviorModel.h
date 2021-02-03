/*
 * Created on Wed Feb 03 2021
 *
 * Copyright (c) 2021 Kazuki Hamaguchi
 */

#pragma once

#include "TemplateBehaviorModel.h"
#include "SpinTurnLeftOrRight.h"
#include "WheelDeviceDriver.h"

class SpinTurnBehaviorModel: public TemplateBehaviorModel
{
    WheelDeviceDriver wheelDeviceDriver;
public:
    void init();
    void run(int pwm, SpinTurnLeftOrRight spinTurnLeftOrRight);
    void terminate();
};