#pragma once

#include "RunSectionParam.h"
#include "LineTraceBehaviorModel.h"
#include "SpinTurnBehaviorModel.h"
#include "StraightBehaviorModel.h"
#include "StopBehaviorModel.h"

class InterfaceBehaviorModel
{
    LineTraceBehaviorModel lineTraceBehaviorModel;
    StraightBehaviorModel straightBehaviorModel;
    SpinTurnBehaviorModel spinTurnBehaviorModel;
    StopBehaviorModel stopBehaviorModel;

public:
    void init();
    void run(RunSectionParam currentRunSectionParam);
    void terminate();
};