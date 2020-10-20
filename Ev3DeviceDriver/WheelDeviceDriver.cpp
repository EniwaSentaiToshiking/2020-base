#include "WheelDeviceDriver.h"

WheelDeviceDriver::WheelDeviceDriver() : leftWheel(PORT_C), rightWheel(PORT_B)
{
    this->init();
}

void WheelDeviceDriver::init()
{
    this->resetDistance();
}

void WheelDeviceDriver::resetDistance()
{
    currentDistance = 0.0;
    handlerCycleDistanceL = 0.0;
    handlerCycleDistanceR = 0.0;
    previousAngleL = leftWheel.getCount();
    previousAngleR = rightWheel.getCount();
}

void WheelDeviceDriver::updateDistance()
{
    currentAngleL = leftWheel.getCount();
    currentAngleR = leftWheel.getCount();
    handlerCycleDistance = 0.0;

    diffAngleL = currentAngleL - previousAngleL;
    diffAngleR = currentAngleR - previousAngleR;

    handlerCycleDistanceL = 2 * M_PI * tireRadius * diffAngleL / 360.0;
    handlerCycleDistanceR = 2 * M_PI * tireRadius * diffAngleR / 360.0;
    handlerCycleDistance = (handlerCycleDistanceL + handlerCycleDistanceR) / 2.0; //タイヤの中央の軌跡を測る
    currentDistance += handlerCycleDistance;

    previousAngleL = currentAngleL;
    previousAngleR = currentAngleR;
}


// int t = 0;
// char buffer[30];

float WheelDeviceDriver::getDistance()
{
    this->updateDistance();
    // if (t > 200)
    // {
    //     // syslog(LOG_NOTICE, "Distance %f", currentDistance);
    //     snprintf(buffer, sizeof(buffer), "Distance %f", currentDistance);
    //     syslog(LOG_NOTICE, buffer);
    //     t = 0;
    // }
    // t++;
    return currentDistance;
}

void WheelDeviceDriver::setLeftPWM(int leftPWM)
{
    leftWheel.setPWM(leftPWM);
}

void WheelDeviceDriver::setRightPWM(int rightPWM)
{
    rightWheel.setPWM(rightPWM);
}

void WheelDeviceDriver::terminate()
{
  leftWheel.stop();
  rightWheel.stop();
}

WheelDeviceDriver::~WheelDeviceDriver()
{
    this->terminate();
}