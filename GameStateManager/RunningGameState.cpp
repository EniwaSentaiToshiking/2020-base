#include "RunningGameState.h"

RunningGameState::RunningGameState()
{
}

void RunningGameState::init()
{
  d.init("RunningGameState");
  interfaceBehaviorModel.init();
  interfaceDeterminationModel.init();
  /*behavior, determination, determinationParam, pwm, kp, ki, kd, targetVal, spinturnLorR*/
  runSectionParamVector.push_back({STRAIGHT, DISTANCE, 100, 10, 0, 0, 0, 0, NONE_L_R, FORWARD});
  runSectionParamVector.push_back({STRAIGHT, DISTANCE, 100, 10, 0, 0, 0, 0, NONE_L_R, BACKWARD});
  runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 50, 10, 2.0, 0.03, 0.2, 18, NONE_L_R, NONE_F_B});
  runSectionParamVector.push_back({SPIN_TURN, SPIN_TURN_ANGLE, DEGREE90, 20, 0, 0, 0, 0, LEFTWARD, NONE_F_B});
  runSectionParamVector.push_back({SPIN_TURN, SPIN_TURN_ANGLE, DEGREE90, 20, 0, 0, 0, 0, RIGHTWARD, NONE_F_B});
  runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 20, 30, 2.0, 0.03, 0.2, 18, NONE_L_R, NONE_F_B});
  runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 800, 90, 2.0, 0.03, 0.2, 18, NONE_L_R, NONE_F_B});
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

  if (interfaceDeterminationModel.determine(currentRunSectionParam))
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
  interfaceBehaviorModel.terminate();
  interfaceDeterminationModel.terminate();
}

RunningGameState::~RunningGameState()
{
  this->terminate();
}
