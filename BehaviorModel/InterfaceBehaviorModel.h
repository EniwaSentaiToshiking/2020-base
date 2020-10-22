#pragma once

#include "LineTraceBehaviorModel.h"
#include "SpinTurnBehaviorModel.h"
// #include "SpinTurnLeftOrRight.h"
// #include "StraightBehaviorModel.h"

class InterfaceBehaviorModel
{
    LineTraceBehaviorModel lineTraceBehaviorModel;
    SpinTurnBehaviorModel spinTurnBehaviorModel;

public:
    void selectLineTrace(int pwm, float kP, float kI, float kD, int targetVal);
    void selectSpinTrun(int pwm, SpinTurnLeftOrRight spinTurnLeftOrRight);
};