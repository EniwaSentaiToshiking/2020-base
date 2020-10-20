#pragma once

#include "LineTraceBehaviorModel.h"
// #include "SpinTurnBehaviorModel.h"
// #include "StraightBehaviorModel.h"

class InterfaceBehaviorModel
{
    LineTraceBehaviorModel lineTraceBehaviorModel;

public:
    void selectLineTrace(int pwm, float kP, float kI, float kD, int targetVal);
};