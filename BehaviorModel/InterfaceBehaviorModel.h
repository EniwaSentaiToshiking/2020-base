#pragma once

#include "LineTraceBehaviorModel.h"
#include "SpinTurnBehaviorModel.h"
#include "StraightBehaviorModel.h"
#include "RunSectionParam.h"

class InterfaceBehaviorModel
{
    LineTraceBehaviorModel lineTraceBehaviorModel;
    StraightBehaviorModel straightBehaviorModel;
    SpinTurnBehaviorModel spinTurnBehaviorModel;

public:
    void init();
    void run(RunSectionParam currentRunSectionParam);
    void terminate();
};