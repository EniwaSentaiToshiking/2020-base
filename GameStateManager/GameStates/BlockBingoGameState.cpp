#include "BlockBingoGameState.h"

BlockBingoGameState::BlockBingoGameState()
{
}

void BlockBingoGameState::init()
{
  d.init("BlockBingoGameState");
  interfaceBehaviorModel.init();
  interfaceDeterminationModel.init();
  this->createRunSection();
}

void BlockBingoGameState::createRunSection()
{
  runSectionParamVector.push_back({LINE_TRAICE, COLOR, COLOR_BLUE, 40, 2.0, 0.03, 0.03, 18, NONE_L_R, NONE_F_B});
  runSectionParamVector.push_back({LINE_TRAICE, COLOR, COLOR_YELLOW, 30, 0.8, 0.01, 0, 18, NONE_L_R, NONE_F_B});
}

// extern char syslogBuf[50];
void BlockBingoGameState::run()
{
  d.lcd_msg_debug("running...", 1);
  RunSectionParam currentRunSectionParam = runSectionParamVector.front();
  interfaceBehaviorModel.run(currentRunSectionParam);

  if (interfaceDeterminationModel.determine(currentRunSectionParam))
  {
    interfaceDeterminationModel.terminate();
    // snprintf(syslogBuf, sizeof(syslogBuf), "dis, %d, pwm, %d",
    //          currentRunSectionParam.determinationParam, currentRunSectionParam.pwm);
    // syslog(LOG_NOTICE, syslogBuf);
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

