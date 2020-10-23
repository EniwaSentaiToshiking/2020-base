#pragma once

#include "TemplateBehaviorModel.h"
#include "StraightBehaviorModel.h"
#include "WheelDeviceDriver.h"
#include "StraightForwardOrBackward.h"

class StopBehaviorModel : public TemplateBehaviorModel
{
    WheelDeviceDriver wheelDeviceDriver;

public:
    void init();
    void run(int pwm);
    void terminate();
};