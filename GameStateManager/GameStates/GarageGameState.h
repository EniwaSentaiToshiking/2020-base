/*
 * Created on Wed Feb 03 2021
 *
 * Copyright (c) 2021 Kazuki Hamaguchi
 */
#pragma once

#include "TemplateGameState.h"
#include "InterfaceDeterminationModel.h"
#include "InterfaceBehaviorModel.h"
#include "RunSectionParam.h"
#include <vector>

#include "DebugUtil.h"

using namespace ev3api;
using namespace std;

class GarageGameState
{
    InterfaceDeterminationModel interfaceDeterminationModel;
    InterfaceBehaviorModel interfaceBehaviorModel;
    vector<RunSectionParam> runSectionParamVector;

    DebugUtil d;

public:
    GarageGameState();
    void init();
    void createRunSectionL();
    void createRunSectionR();
    void run();
    bool isFinished();
    void terminate();
};
