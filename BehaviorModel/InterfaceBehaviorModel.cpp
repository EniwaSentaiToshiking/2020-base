#include "InterfaceBehaviorModel.h"

void InterfaceBehaviorModel::init()
{
    lineTraceBehaviorModel.init();
    spinTurnBehaviorModel.init();
}

void InterfaceBehaviorModel::run(RunSectionParam currentRunSectionParam)
{
    switch (currentRunSectionParam.behavior)
    {
    case LINE_TRAICE:
        lineTraceBehaviorModel.run(currentRunSectionParam.pwm, currentRunSectionParam.kP,
                                               currentRunSectionParam.kI, currentRunSectionParam.kD, currentRunSectionParam.targetVal);
        break;
    case SPIN_TURN:
        spinTurnBehaviorModel.run(currentRunSectionParam.pwm, currentRunSectionParam.spinTurnLeftOrRight);
        break;

    default:
        break;
    }
}

void InterfaceBehaviorModel::terminate()
{
    lineTraceBehaviorModel.terminate();
    spinTurnBehaviorModel.terminate();
}