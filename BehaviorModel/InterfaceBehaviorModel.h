#pragma once

#include "LineTraceBehaviorModel.h"
#include "SpinTurnBehaviorModel.h"
#include "RunSectionParam.h"

class InterfaceBehaviorModel
{
    LineTraceBehaviorModel lineTraceBehaviorModel;
    SpinTurnBehaviorModel spinTurnBehaviorModel;

public:
    void init();
    void run(RunSectionParam currentRunSectionParam);
    void terminate();
};