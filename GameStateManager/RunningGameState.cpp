#include "RunningGameState.h"

RunningGameState::RunningGameState()
{
}

void RunningGameState::init()
{
  d.init("RunningGameState");
  /*distance, pwm, kp, ki, kd, targetVal*/
  runSectionParamVector.push_back({800.0, 90, 2.0, 0.03, 0.2, 18});
  runSectionParamVector.push_back({1200.0, 80, 2.0, 0.03, 0.2, 18});
  runSectionParamVector.push_back({400.0, 90, 2.0, 0.03, 0.2, 18});
  runSectionParamVector.push_back({1200.0, 70, 2.0, 0.03, 0.2, 18});
  /* Gate 1*/
  runSectionParamVector.push_back({600.0, 90, 2.0, 0.03, 0.2, 18});
  runSectionParamVector.push_back({500.0, 70, 2.0, 0.03, 0.2, 18});
  runSectionParamVector.push_back({600.0, 80, 2.0, 0.03, 0.2, 18});
  runSectionParamVector.push_back({1700.0, 70, 2.0, 0.03, 0.2, 18});
  runSectionParamVector.push_back({500.0, 80, 2.0, 0.03, 0.2, 18});
  /* Gate 2*/
  runSectionParamVector.push_back({800.0, 80, 2.0, 0.03, 0.2, 18});
  runSectionParamVector.push_back({1550.0, 100, 2.0, 0.03, 0.2, 18});
  runSectionParamVector.push_back({550.0, 70, 2.0, 0.03, 0.2, 18});
  runSectionParamVector.push_back({1100.0, 90, 2.0, 0.03, 0.2, 18});
}

void RunningGameState::run()
{
  d.lcd_msg_debug("running...", 1);
  RunSectionParam currentRunSectionParam = runSectionParamVector.front();
  interfaceBehaviorModel.selectLineTrace(currentRunSectionParam.pwm, currentRunSectionParam.kP,
                                         currentRunSectionParam.kI, currentRunSectionParam.kD, currentRunSectionParam.targetVal);

  if (interfaceDeterminationModel.selectDistance(currentRunSectionParam.distance))
  {
    interfaceDeterminationModel.terminate();
    runSectionParamVector.erase(runSectionParamVector.begin());
  }
}

bool RunningGameState::isFinished()
{
  return runSectionParamVector.empty();
}

void RunningGameState::terminate()
{
  d.lcd_msg_debug("Stopped.", 1);
  d.led_debug(LED_RED);
}

RunningGameState::~RunningGameState()
{
  this->terminate();
}

