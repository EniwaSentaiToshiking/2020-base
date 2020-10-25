#pragma once

#include "Motor.h"
#include "DebugUtil.h"
#include <math.h>
#include <stdlib.h>

using namespace ev3api;

class WheelDeviceDriver
{
    Motor leftWheel;
    Motor rightWheel;

public:
    WheelDeviceDriver();
    void init();
    void resetDistance();
    float getDistance();
    void setLeftPWM(int leftPWM);
    void setRightPWM(int rightPWM);
    void terminate();
    ~WheelDeviceDriver();

private:
    void updateDistance();
    float tireRadius = 45.0f; //45mm

    float currentDistance;
    
    float handlerCycleDistance;
    float handlerCycleDistanceL;
    float handlerCycleDistanceR;

    float previousAngleL;
    float previousAngleR;
    float currentAngleL;
    float currentAngleR;
    float diffAngleL;
    float diffAngleR;

    /* debug */
    DebugUtil d;
    // FILE *file;
};