#include "RunningGameState.h"

RunningGameState::RunningGameState()
{
}

void RunningGameState::init()
{
  d.init("RunningGameState");
  interfaceBehaviorModel.init();
  /*behavior, determination, determinationParam, pwm, kp, ki, kd, targetVal, spinturnLorR*/
  // runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 800, 50, 2.0, 0.03, 0.2, 18, NONE});
  runSectionParamVector.push_back({SPIN_TURN, SPIN_TURN_ANGLE, DEGREE90, 20, 0, 0, 0, 0, LEFTWARD});
  runSectionParamVector.push_back({SPIN_TURN, SPIN_TURN_ANGLE, DEGREE90, 20, 0, 0, 0, 0, RIGHTWARD});
  runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 800, 90, 2.0, 0.03, 0.2, 18, NONE});
  // runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 1200, 80, 2.0, 0.03, 0.2, 18, NONE});
  // runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 400, 90, 2.0, 0.03, 0.2, 18, NONE});
  // runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 1200, 70, 2.0, 0.03, 0.2, 18, NONE});
  // /* Gate 1*/
  // runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 600, 90, 2.0, 0.03, 0.2, 18, NONE});
  // runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 500, 70, 2.0, 0.03, 0.2, 18, NONE});
  // runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 600, 80, 2.0, 0.03, 0.2, 18, NONE});
  // runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 1700, 70, 2.0, 0.03, 0.2, 18, NONE});
  // runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 500, 80, 2.0, 0.03, 0.2, 18, NONE});
  // /* Gate 2*/
  // runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 800, 80, 2.0, 0.03, 0.2, 18, NONE});
  // runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 1550, 100, 2.0, 0.03, 0.2, 18, NONE});
  // runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 550, 70, 2.0, 0.03, 0.2, 18, NONE});
  // runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 1100, 85, 2.0, 0.03, 0.2, 18, NONE});
}

void RunningGameState::run()
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

bool RunningGameState::isFinished()
{
  return runSectionParamVector.empty();
}

void RunningGameState::terminate()
{
  d.lcd_msg_debug("Stopped.", 1);
  d.led_debug(LED_RED);
  interfaceBehaviorModel.terminate();
}

RunningGameState::~RunningGameState()
{
  this->terminate();
}
