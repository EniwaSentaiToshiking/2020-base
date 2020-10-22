
#pragma once

#include "TemplateDeterminationModel.h"
#include "WheelDeviceDriver.h"
#include "SpinTurnAngleList.h"
#include <math.h>

class SpinTurnAngleDeterminationModel : public TemplateDeterminationModel
{
    WheelDeviceDriver wheelDeviceDriver;

public:
    void init();
    bool determine(SpinTurnAngleList spinTurnAngle);
    void terminate();

private:
    /*
    トレッド幅の半径(mm)
    参考：https://cars-japan.net/body/bdy03.html
    */
    // const int treadWidthRadius = 65;
    // int calcedSpinTurnAngle;
    // int calcSpinTrunDistance();
};