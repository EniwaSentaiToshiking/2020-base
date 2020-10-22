#include "RunningGameState.h"

RunningGameState::RunningGameState()
{
}

void RunningGameState::init()
{
  d.init("RunningGameState");
  /*determination, determinationParam, pwm, kp, ki, kd, targetVal*/
  runSectionParamVector.push_back({DISTANCE,800, 90, 2.0, 0.03, 0.2, 18});
  runSectionParamVector.push_back({DISTANCE,1200, 80, 2.0, 0.03, 0.2, 18});
  runSectionParamVector.push_back({DISTANCE,400, 90, 2.0, 0.03, 0.2, 18});
  runSectionParamVector.push_back({DISTANCE,1200, 70, 2.0, 0.03, 0.2, 18});
  /* Gate 1*/
  runSectionParamVector.push_back({DISTANCE,600, 90, 2.0, 0.03, 0.2, 18});
  runSectionParamVector.push_back({DISTANCE,500, 70, 2.0, 0.03, 0.2, 18});
  runSectionParamVector.push_back({DISTANCE,600, 80, 2.0, 0.03, 0.2, 18});
  runSectionParamVector.push_back({DISTANCE,1700, 70, 2.0, 0.03, 0.2, 18});
  runSectionParamVector.push_back({DISTANCE,500, 80, 2.0, 0.03, 0.2, 18});
  /* Gate 2*/
  runSectionParamVector.push_back({DISTANCE,800, 80, 2.0, 0.03, 0.2, 18});
  runSectionParamVector.push_back({DISTANCE,1550, 100, 2.0, 0.03, 0.2, 18});
  runSectionParamVector.push_back({DISTANCE,550, 70, 2.0, 0.03, 0.2, 18});
  runSectionParamVector.push_back({DISTANCE,1100, 85, 2.0, 0.03, 0.2, 18});
}

void RunningGameState::run()
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

