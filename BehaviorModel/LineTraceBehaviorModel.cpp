#include "LineTraceBehaviorModel.h"


void LineTraceBehaviorModel::init()
{
    d.init("LineTraceBehavior");
    pidCalculator.init();
    wheelDeviceDriver.init();
    colorSensorDeviceDriver.init();
    sensorVal = 0;
}

void LineTraceBehaviorModel::run(int pwm, float kP, float kI, float kD, int targetVal)
{
    sensorVal = colorSensorDeviceDriver.getBrightness();
    int controlValue = pidCalculator.calcPID(kP,kI,kD,targetVal,sensorVal);
    switch (edge)
    {
    case RIGHT_EDGE:
        wheelDeviceDriver.setLeftPWM(pwm + controlValue);
        wheelDeviceDriver.setRightPWM(pwm - controlValue);
        break;
    
    case LEFT_EDGE:
        wheelDeviceDriver.setLeftPWM(pwm - controlValue);
        wheelDeviceDriver.setRightPWM(pwm + controlValue);
        break;
    default:
        break;
    }
}

void LineTraceBehaviorModel::terminate()
{
    
}