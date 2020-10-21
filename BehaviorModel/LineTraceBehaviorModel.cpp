#include "LineTraceBehaviorModel.h"


void LineTraceBehaviorModel::init()
{
    d.init("LineTraceBehavior");
    pidCalculator.init();
    wheelDeviceDriver.init();
    colorSensorDeviceDriver.init();
    sensorVal = 0;
}
// extern char syslogBuf[50];
void LineTraceBehaviorModel::run(int pwm, float kP, float kI, float kD, int targetVal)
{
    sensorVal = colorSensorDeviceDriver.getBrightness();
    int controlValue = pidCalculator.calcPID(kP,kI,kD,targetVal,sensorVal);
    int leftPWM = 0;
    int rightPWM = 0;
    switch (edge)
    {
    case RIGHT_EDGE:
        leftPWM = pwm + controlValue;
        rightPWM = pwm - controlValue;
        break;
    
    case LEFT_EDGE:
        leftPWM = pwm - controlValue;
        rightPWM = pwm + controlValue;
        break;
    default:
        break;
    }
    wheelDeviceDriver.setLeftPWM(leftPWM);
    wheelDeviceDriver.setRightPWM(rightPWM);
    // snprintf(syslogBuf, sizeof(syslogBuf), "leftPWM, %d, rightPWM %d", leftPWM, rightPWM);
    // syslog(LOG_NOTICE, syslogBuf);
}

void LineTraceBehaviorModel::terminate()
{
    
}