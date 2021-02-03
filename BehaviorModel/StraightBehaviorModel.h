/*
 * Created on Wed Feb 03 2021
 *
 * Copyright (c) 2021 Kazuki Hamaguchi
 */

#pragma once

#include "TemplateBehaviorModel.h"
#include "StraightBehaviorModel.h"
#include "WheelDeviceDriver.h"
#include "StraightForwardOrBackward.h"

class StraightBehaviorModel : public TemplateBehaviorModel
{
    WheelDeviceDriver wheelDeviceDriver;

public:
    void init();
    void run(int pwm, StraightForwardOrBackward straightForwardOrBackward);
    void terminate();
};