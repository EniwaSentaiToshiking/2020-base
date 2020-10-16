#pragma once

// #include "TouchDeterminationModel.h"
#include "ColorDeterminationModel.h"
// #include "DistanceDeterminationModel.h"

using namespace ev3api;
class InterfaceDeterminationModel
{
    // TouchDeterminationModel touchDeterminationModel;
    ColorDeterminationModel colorDeterminationModel;
    
public:
    // bool selectTouch();
    bool selectColor(colorid_t color);

};