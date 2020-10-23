#include "BlockBingoGameState.h"

BlockBingoGameState::BlockBingoGameState()
{
}

void BlockBingoGameState::init()
{
  d.init("BlockBingoGameState");

}

void BlockBingoGameState::run()
{
  d.lcd_msg_debug("running...", 1);
  RunSectionParam currentRunSectionParam = runSectionParamVector.front();

  switch (currentRunSectionParam.behavior)
  {
  case LINE_TRAICE:
    interfaceBehaviorModel.selectLineTrace(currentRunSectionParam.pwm, currentRunSectionParam.kP,
                                           currentRunSectionParam.kI, currentRunSectionParam.kD, currentRunSectionParam.targetVal);
    break;
  case SPIN_TURN:
    interfaceBehaviorModel.selectSpinTrun(currentRunSectionParam.pwm, currentRunSectionParam.spinTurnLeftOrRight);
    break;

  default:
    break;
  }

  switch (currentRunSectionParam.determination)
  {
  case COLOR:
    if (interfaceDeterminationModel.selectColor((colorid_t)currentRunSectionParam.determinationParam))
    {
      interfaceDeterminationModel.terminate();
      runSectionParamVector.erase(runSectionParamVector.begin());
    }
    break;

  case DISTANCE:
    if (interfaceDeterminationModel.selectDistance(currentRunSectionParam.determinationParam))
    {
      interfaceDeterminationModel.terminate();
      runSectionParamVector.erase(runSectionParamVector.begin());
    }
    break;

  case SPIN_TURN_ANGLE:
    if (interfaceDeterminationModel.selectAngle((SpinTurnAngleList)currentRunSectionParam.determinationParam))
    {
      interfaceDeterminationModel.terminate();
      runSectionParamVector.erase(runSectionParamVector.begin());
    }
    break;
  default:
    break;
  }
}

bool BlockBingoGameState::isFinished()
{
  return runSectionParamVector.empty();
}

void BlockBingoGameState::terminate()
{
  d.lcd_msg_debug("Stopped.", 1);
  interfaceBehaviorModel.selectLineTrace(0, 0, 0, 0, 0);
}

