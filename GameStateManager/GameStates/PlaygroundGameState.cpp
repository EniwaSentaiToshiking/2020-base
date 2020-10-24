#include "PlaygroundGameState.h"

PlaygroundGameState::PlaygroundGameState()
{
}

void PlaygroundGameState::init()
{
  d.init("PlaygroundGameState");
  interfaceBehaviorModel.init();
  interfaceDeterminationModel.init();
  this->createRunSection();
}

void PlaygroundGameState::createRunSection()
{
  /* behavior, determination, determinationParam, pwm, kP, kI, kD, targetVal, spinTurnLeftOrRight, straightForwardOrBackward */
  runSectionParamVector.push_back({STOP, WAIT_TIME, 10*1000, 0, 0, 0, 0, 0, NONE_L_R, NONE_F_B});
  runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 776, 50, 2.0, 0.03, 0.2, 18, NONE_L_R, NONE_F_B});
  runSectionParamVector.push_back({STOP, WAIT_TIME, 5000, 0, 0, 0, 0, 0, NONE_L_R, NONE_F_B});
  runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 776, 50, 2.0, 0.03, 0.2, 18, NONE_L_R, NONE_F_B});
  runSectionParamVector.push_back({STOP, WAIT_TIME, 4000, 0, 0, 0, 0, 0, NONE_L_R, NONE_F_B});
  runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 776, 50, 2.0, 0.03, 0.2, 18, NONE_L_R, NONE_F_B});
}

extern char syslogBuf[50];
void PlaygroundGameState::run()
{
  d.lcd_msg_debug("running...", 1);
  RunSectionParam currentRunSectionParam = runSectionParamVector.front();
  interfaceBehaviorModel.run(currentRunSectionParam);

  if (interfaceDeterminationModel.determine(currentRunSectionParam))
  {
    interfaceDeterminationModel.terminate();
    snprintf(syslogBuf, sizeof(syslogBuf), "dis, %d, pwm, %d",
             currentRunSectionParam.determinationParam, currentRunSectionParam.pwm);
    syslog(LOG_NOTICE, syslogBuf);
    runSectionParamVector.erase(runSectionParamVector.begin());
  }
}

bool PlaygroundGameState::isFinished()
{
  return runSectionParamVector.empty();
}


void PlaygroundGameState::terminate()
{
  d.led_debug(LED_RED);
  d.lcd_msg_debug("Stopped.", 1);
  interfaceBehaviorModel.terminate();
  interfaceDeterminationModel.terminate();
}
