/*
 * Created on Wed Feb 03 2021
 *
 * Copyright (c) 2021 Kazuki Hamaguchi
 */

#pragma once

// #include "TouchDeterminationModel.h"
#include "ColorDeterminationModel.h"
#include "DistanceDeterminationModel.h"
#include "SpinTurnAngleDeterminationModel.h"
#include "WaitTimeDterminationModel.h"
#include "ColorCircleDeterminationModel.h"
#include "RunSectionParam.h"

using namespace ev3api;
class InterfaceDeterminationModel
{
    // TouchDeterminationModel touchDeterminationModel;
    ColorDeterminationModel colorDeterminationModel;
    DistanceDeterminationModel distanceDeterminationModel;
    SpinTurnAngleDeterminationModel spinTurnAngleDeterminationModel;
    WaitTimeDterminationModel waitTimeDterminationModel;
    ColorCircleDeterminationModel colorCircleDeterminationModel;

    
public:
    void init();
    bool determine(RunSectionParam currentRunSectionParam);
    void terminate();
};