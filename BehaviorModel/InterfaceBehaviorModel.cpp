#include "InterfaceBehaviorModel.h"

void InterfaceBehaviorModel::selectLineTrace(int pwm, float kP, float kI, float kD, int targetVal)
{
    lineTraceBehaviorModel.run(pwm, kP, kI, kD, targetVal);
}