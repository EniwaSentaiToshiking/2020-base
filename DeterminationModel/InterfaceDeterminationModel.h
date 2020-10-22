#pragma once

// #include "TouchDeterminationModel.h"
#include "ColorDeterminationModel.h"
#include "DistanceDeterminationModel.h"

using namespace ev3api;
class InterfaceDeterminationModel
{
    // TouchDeterminationModel touchDeterminationModel;
    ColorDeterminationModel colorDeterminationModel;
    DistanceDeterminationModel distanceDeterminationModel;
    
public:
    void init();
    // bool selectTouch();
    bool selectColor(colorid_t color);
    bool selectDistance(float distance);
    void terminate();
};