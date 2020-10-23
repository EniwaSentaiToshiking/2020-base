#include "SpinTurnBehaviorModel.h"

void SpinTurnBehaviorModel::init()
{
    wheelDeviceDriver.init();
    
}

void SpinTurnBehaviorModel::run(int pwm, SpinTurnLeftOrRight spinTurnLeftOrRight)
{
    switch (spinTurnLeftOrRight)
    {
    case NONE:
        break;

    case LEFTWARD:
        wheelDeviceDriver.setLeftPWM(-pwm);
        wheelDeviceDriver.setRightPWM(pwm);
        break;

    case RIGHTWARD:
        wheelDeviceDriver.setLeftPWM(pwm);
        wheelDeviceDriver.setRightPWM(-pwm);
        break;
        
    default:
        break;
    }
}

void SpinTurnBehaviorModel::terminate()
{
}