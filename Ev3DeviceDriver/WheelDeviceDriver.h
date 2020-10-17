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
    /* debug */
    DebugUtil d;
    // FILE *loggingFile;

public:
    WheelDeviceDriver();
    void init();
    float getDistance();
    void setLeftPWM(int8_t leftPWM);
    void setRightPWM(int8_t rightPWM);
    void terminate();
    ~WheelDeviceDriver();

private:
    void resetDistance();
    void updateDistance();
    float tireRadius = 50.0f; //50mm

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
};