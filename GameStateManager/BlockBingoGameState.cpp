#include "BlockBingoGameState.h"

BlockBingoGameState::BlockBingoGameState()
{
}

void BlockBingoGameState::init()
{
  d.init("BlockBingoGameState");
  runSectionParamVector.push_back({COLOR, COLOR_YELLOW, 40, 2.0, 0.03, 0.2, 18});
}

void BlockBingoGameState::run()
{
  d.lcd_msg_debug("running...", 1);
  RunSectionParam currentRunSectionParam = runSectionParamVector.front();
  interfaceBehaviorModel.selectLineTrace(currentRunSectionParam.pwm, currentRunSectionParam.kP,
                                         currentRunSectionParam.kI, currentRunSectionParam.kD, currentRunSectionParam.targetVal);
  
  switch (currentRunSectionParam.determinationActionList)
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

