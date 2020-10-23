#include "BlockBingoGameState.h"

BlockBingoGameState::BlockBingoGameState()
{
}

void BlockBingoGameState::init()
{
  d.init("BlockBingoGameState");
  interfaceBehaviorModel.init();
  runSectionParamVector.push_back({LINE_TRAICE, COLOR, COLOR_BLUE, 70, 2.0, 0.03, 0.2, 18, NONE});
}

void BlockBingoGameState::run()
{
  d.lcd_msg_debug("running...", 1);
  RunSectionParam currentRunSectionParam = runSectionParamVector.front();
  interfaceBehaviorModel.run(currentRunSectionParam);

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
  interfaceBehaviorModel.terminate();
}

