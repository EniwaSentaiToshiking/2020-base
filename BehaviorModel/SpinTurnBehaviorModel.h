#pragma once

#include "TemplateBehaviorModel.h"
#include "SpinTurnAngleList.h"
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