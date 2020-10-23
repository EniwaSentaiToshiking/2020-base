#include "BlockBingoGameState.h"

BlockBingoGameState::BlockBingoGameState()
{
}

void BlockBingoGameState::init()
{
  d.init("BlockBingoGameState");
  interfaceBehaviorModel.init();
  interfaceDeterminationModel.init();
  
  runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 300, 20, 2.0, 0.03, 0.2, 18, NONE_L_R, NONE_F_B});
  runSectionParamVector.push_back({LINE_TRAICE, COLOR, COLOR_BLUE, 60, 2.0, 0.03, 0.2, 18, NONE_L_R, NONE_F_B});
}


void BlockBingoGameState::run()
{
  d.lcd_msg_debug("running...", 1);
  RunSectionParam currentRunSectionParam = runSectionParamVector.front();
  interfaceBehaviorModel.run(currentRunSectionParam);

  if (interfaceDeterminationModel.determine(currentRunSectionParam))
  {
    interfaceDeterminationModel.terminate();
    runSectionParamVector.erase(runSectionParamVector.begin());
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
  interfaceDeterminationModel.terminate();
}

