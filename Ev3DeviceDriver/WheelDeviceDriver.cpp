#include "WheelDeviceDriver.h"


WheelDeviceDriver::WheelDeviceDriver() : leftWheel(PORT_C), rightWheel(PORT_B)
{
    this->init();
    file = fopen("logging_distance.csv", "w");
    fprintf(file, "Distance,difL,curL,preL,difR,curR,preR\n");
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
    currentAngleR = rightWheel.getCount();
    handlerCycleDistance = 0.0;

    diffAngleL = currentAngleL - previousAngleL;
    diffAngleR = currentAngleR - previousAngleR;

    handlerCycleDistanceL = 2 * M_PI * tireRadius * diffAngleL / 360.0;
    handlerCycleDistanceR = 2 * M_PI * tireRadius * diffAngleR / 360.0;
    handlerCycleDistance = (handlerCycleDistanceL + handlerCycleDistanceR) / 2.0; //タイヤの中央の軌跡を測る
    currentDistance += handlerCycleDistance;

    // fprintf(file, "%f,%f,%f,%f,%f,%f,%f\n",
    //         currentDistance, diffAngleL, currentAngleL, previousAngleL, diffAngleR, currentAngleR, previousAngleR);

    previousAngleL = currentAngleL;
    previousAngleR = currentAngleR;
}

extern char syslogBuf[50];
float WheelDeviceDriver::getDistance()
{
    this->updateDistance();
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
    fclose(file);
}