#include "RunningGameState.h"

RunningGameState::RunningGameState()
{
}

extern int edge;
void RunningGameState::init()
{
  d.init("RunningGameState");
  interfaceBehaviorModel.init();
  interfaceDeterminationModel.init();
  switch (edge)
  {
  case RIGHT_EDGE:
    this->createRunSectionL();
    break;
  
  case LEFT_EDGE:
    this->createRunSectionR();
    break;
  
  default:
    break;
  }
}

void RunningGameState::createRunSectionL()
{
    /* behavior, determination, determinationParam, pwm, kP, kI, kD, targetVal, spinTurnLeftOrRight, straightForwardOrBackward */
    runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 776, 90, 2.0, 0.03, 0.2, 18, NONE_L_R, NONE_F_B});
    runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 942, 80, 2.0, 0.03, 0.2, 18, NONE_L_R, NONE_F_B});
    runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 500, 90, 2.0, 0.03, 0.2, 18, NONE_L_R, NONE_F_B});
    runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 1000, 75, 2.0, 0.03, 0.2, 18, NONE_L_R, NONE_F_B});
    runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 700, 85, 2.0, 0.03, 0.2, 18, NONE_L_R, NONE_F_B});
    /* Passed Gate 1*/
    runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 350, 65, 2.0, 0.03, 0.2, 18, NONE_L_R, NONE_F_B});
    runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 550, 90, 2.0, 0.03, 0.2, 18, NONE_L_R, NONE_F_B});
    runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 582, 80, 2.0, 0.03, 0.2, 18, NONE_L_R, NONE_F_B});
    runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 251, 80, 2.0, 0.03, 0.2, 18, NONE_L_R, NONE_F_B});
    runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 582, 80, 2.0, 0.03, 0.2, 18, NONE_L_R, NONE_F_B});
    runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 547, 90, 2.0, 0.03, 0.2, 18, NONE_L_R, NONE_F_B});
    /* Passed Gate 2*/
    runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 574, 80, 2.0, 0.03, 0.2, 18, NONE_L_R, NONE_F_B});
    runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 1552, 100, 2.0, 0.03, 0.2, 18, NONE_L_R, NONE_F_B});
    runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 425, 75, 2.0, 0.03, 0.2, 18, NONE_L_R, NONE_F_B});
    runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 1100, 90, 2.0, 0.03, 0.2, 18, NONE_L_R, NONE_F_B});
}

void RunningGameState::createRunSectionR()
{
    /* behavior, determination, determinationParam, pwm, kP, kI, kD, targetVal, spinTurnLeftOrRight, straightForwardOrBackward */
    runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 776, 90, 2.0, 0.03, 0.2, 18, NONE_L_R, NONE_F_B});
    runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 942, 80, 2.0, 0.03, 0.2, 18, NONE_L_R, NONE_F_B});
    runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 500, 90, 2.0, 0.03, 0.2, 18, NONE_L_R, NONE_F_B});
    runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 1000, 75, 2.0, 0.03, 0.2, 18, NONE_L_R, NONE_F_B});
    runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 700, 85, 2.0, 0.03, 0.2, 18, NONE_L_R, NONE_F_B});
    /* Passed Gate 1*/
    runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 350, 65, 2.0, 0.03, 0.2, 18, NONE_L_R, NONE_F_B});
    runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 550, 90, 2.0, 0.03, 0.2, 18, NONE_L_R, NONE_F_B});
    runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 582, 80, 2.0, 0.03, 0.2, 18, NONE_L_R, NONE_F_B});
    runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 251, 80, 2.0, 0.03, 0.2, 18, NONE_L_R, NONE_F_B});
    runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 582, 80, 2.0, 0.03, 0.2, 18, NONE_L_R, NONE_F_B});
    runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 547, 90, 2.0, 0.03, 0.2, 18, NONE_L_R, NONE_F_B});
    /* Passed Gate 2*/
    runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 574, 80, 2.0, 0.03, 0.2, 18, NONE_L_R, NONE_F_B});
    runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 1552, 100, 2.0, 0.03, 0.2, 18, NONE_L_R, NONE_F_B});
    runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 425, 75, 2.0, 0.03, 0.2, 18, NONE_L_R, NONE_F_B});
    runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 1100, 90, 2.0, 0.03, 0.2, 18, NONE_L_R, NONE_F_B});
}

// extern char syslogBuf[50];
void RunningGameState::run()
{
  d.lcd_msg_debug("running...", 1);
  RunSectionParam currentRunSectionParam = runSectionParamVector.front();
  interfaceBehaviorModel.run(currentRunSectionParam);

  if (interfaceDeterminationModel.determine(currentRunSectionParam))
  {
    interfaceDeterminationModel.terminate();
    // snprintf(syslogBuf, sizeof(syslogBuf), "dis, %d, pwm, %d", 
    //   currentRunSectionParam.determinationParam, currentRunSectionParam.pwm);
    // syslog(LOG_NOTICE, syslogBuf);
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
