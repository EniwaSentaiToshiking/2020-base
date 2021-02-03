/*
 * Created on Wed Feb 03 2021
 *
 * Copyright (c) 2021 Kazuki Hamaguchi
 */

#pragma once

#include "TemplateBehaviorModel.h"
#include "WheelDeviceDriver.h"
#include "ColorSensorDeviceDriver.h"
#include "PIDCalculator.h"
#include "Edge.h"

#include "DebugUtil.h"

extern int edge;
class LineTraceBehaviorModel : public TemplateBehaviorModel
{
    PIDCalculator pidCalculator;
    WheelDeviceDriver wheelDeviceDriver;
    ColorSensorDeviceDriver colorSensorDeviceDriver;

    DebugUtil d;

public:
    void init();
    void run(int pwm, float kP, float kI, float kD, int targetVal);
    void terminate();

private:
    int sensorVal;
};