#include "InterfaceBehaviorModel.h"

void InterfaceBehaviorModel::init()
{
    lineTraceBehaviorModel.init();
    straightBehaviorModel.init();
    spinTurnBehaviorModel.init();
    stopBehaviorModel.init();
}

void InterfaceBehaviorModel::run(RunSectionParam currentRunSectionParam)
{
    switch (currentRunSectionParam.behavior)
    {
    case LINE_TRAICE:
        lineTraceBehaviorModel.run(currentRunSectionParam.pwm, currentRunSectionParam.kP,
                                               currentRunSectionParam.kI, currentRunSectionParam.kD, currentRunSectionParam.targetVal);
        break;
    case STRAIGHT:
        straightBehaviorModel.run(currentRunSectionParam.pwm, currentRunSectionParam.straightForwardOrBackward);
        break;

    case SPIN_TURN:
        spinTurnBehaviorModel.run(currentRunSectionParam.pwm, currentRunSectionParam.spinTurnLeftOrRight);
        break;
    
    case STOP:
        stopBehaviorModel.run(currentRunSectionParam.pwm);
        break;

    default:
        break;
    }
}

void InterfaceBehaviorModel::terminate()
{
    lineTraceBehaviorModel.terminate();
    straightBehaviorModel.terminate();
    spinTurnBehaviorModel.terminate();
    stopBehaviorModel.terminate();
}