#include "InterfaceBehaviorModel.h"

void InterfaceBehaviorModel::selectLineTrace(int pwm, float kP, float kI, float kD, int targetVal)
{
    lineTraceBehaviorModel.run(pwm, kP, kI, kD, targetVal);
}

void InterfaceBehaviorModel::selectSpinTrun(int pwm, SpinTurnLeftOrRight spinTurnLeftOrRight)
{
    spinTurnBehaviorModel.run(pwm, spinTurnLeftOrRight);
}