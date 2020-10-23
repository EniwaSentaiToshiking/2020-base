#pragma once

// #include "TouchDeterminationModel.h"
#include "ColorDeterminationModel.h"
#include "DistanceDeterminationModel.h"
#include "SpinTurnAngleDeterminationModel.h"
#include "RunSectionParam.h"

using namespace ev3api;
class InterfaceDeterminationModel
{
    // TouchDeterminationModel touchDeterminationModel;
    ColorDeterminationModel colorDeterminationModel;
    DistanceDeterminationModel distanceDeterminationModel;
    SpinTurnAngleDeterminationModel spinTurnAngleDeterminationModel;

    
public:
    void init();
    // bool selectTouch();
    bool selectColor(colorid_t color);
    bool selectDistance(float distance);
    bool selectAngle(SpinTurnAngleList spinTurnAngle);
    void terminate();
    // void run();
};