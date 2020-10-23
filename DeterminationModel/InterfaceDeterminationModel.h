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
    bool determine(RunSectionParam currentRunSectionParam);
    void terminate();
};