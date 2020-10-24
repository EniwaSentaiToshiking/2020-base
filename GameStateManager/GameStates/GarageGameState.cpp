#include "GarageGameState.h"

GarageGameState::GarageGameState()
{
}

extern int edge;
void GarageGameState::init()
{
  d.init("BlockBingoGameState");
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

void GarageGameState::createRunSectionL()
{
  runSectionParamVector.push_back({LINE_TRAICE, COLOR, COLOR_BLUE, 50, 2.0, 0.03, 0.03, 18, NONE_L_R, NONE_F_B});
  runSectionParamVector.push_back({LINE_TRAICE, COLOR, COLOR_YELLOW, 40, 0.8, 0.01, 0, 18, NONE_L_R, NONE_F_B});
  // runSectionParamVector.push_back({LINE_TRAICE, COLOR, COLOR_YELLOW, 40, 1.5, 0.01, 0, 18, NONE_L_R, NONE_F_B});
  /* ガレージ前のラインまで向かう */
  runSectionParamVector.push_back({STOP, STOP_DETERMINATION, 0, 0, 0, 0, 0, 0, NONE_L_R, NONE_F_B});
  runSectionParamVector.push_back({STRAIGHT, DISTANCE, 600, 20, 0, 0, 0, 0, NONE_L_R, FORWARD});
  runSectionParamVector.push_back({SPIN_TURN, SPIN_TURN_ANGLE, DEGREE45, 10, 0, 0, 0, 0, RIGHTWARD, NONE_F_B});
  runSectionParamVector.push_back({STRAIGHT, COLOR, COLOR_BLACK, 20, 0, 0, 0, 0, NONE_L_R, FORWARD});
  runSectionParamVector.push_back({STOP, WAIT_TIME, 60, 0, 0, 0, 0, 0, NONE_L_R, NONE_F_B});
  runSectionParamVector.push_back({SPIN_TURN, SPIN_TURN_ANGLE, DEGREE45, 20, 0, 0, 0, 0, RIGHTWARD, NONE_F_B});
  /* ラインからガレージ入口へ向かう */
  runSectionParamVector.push_back({LINE_TRAICE, COLOR, COLOR_BLUE, 20, 2.0, 0.03, 0.03, 18, NONE_L_R, NONE_F_B});
  runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 220, 20, 2.0, 0.03, 0.03, 18, NONE_L_R, NONE_F_B});
  runSectionParamVector.push_back({LINE_TRAICE, COLOR, COLOR_WHITE, 20, 2.0, 0.03, 0, 18, NONE_L_R, NONE_F_B});
  /* ガレージへ進入・停止 */
  runSectionParamVector.push_back({STRAIGHT, DISTANCE, 200, 20, 0, 0, 0, 0, NONE_L_R, FORWARD});
  runSectionParamVector.push_back({STOP, WAIT_TIME, 6000, 0, 0, 0, 0, 0, NONE_L_R, NONE_F_B});
}

void GarageGameState::createRunSectionR()
{
  runSectionParamVector.push_back({LINE_TRAICE, COLOR, COLOR_BLUE, 40, 2.0, 0.03, 0.03, 18, NONE_L_R, NONE_F_B});
  runSectionParamVector.push_back({LINE_TRAICE, COLOR, COLOR_YELLOW, 30, 0.8, 0.01, 0, 18, NONE_L_R, NONE_F_B});
  // runSectionParamVector.push_back({LINE_TRAICE, COLOR, COLOR_YELLOW, 40, 1.5, 0.01, 0, 18, NONE_L_R, NONE_F_B});
  /* ガレージ前のラインまで向かう */
  runSectionParamVector.push_back({STOP, STOP_DETERMINATION, 0, 0, 0, 0, 0, 0, NONE_L_R, NONE_F_B});
  runSectionParamVector.push_back({STRAIGHT, DISTANCE, 600, 20, 0, 0, 0, 0, NONE_L_R, FORWARD});
  runSectionParamVector.push_back({SPIN_TURN, SPIN_TURN_ANGLE, DEGREE45, 10, 0, 0, 0, 0, LEFTWARD, NONE_F_B});
  runSectionParamVector.push_back({STRAIGHT, COLOR, COLOR_BLACK, 20, 0, 0, 0, 0, NONE_L_R, FORWARD});
  runSectionParamVector.push_back({STOP, STOP_DETERMINATION, 0, 0, 0, 0, 0, 0, NONE_L_R, NONE_F_B});
  runSectionParamVector.push_back({SPIN_TURN, SPIN_TURN_ANGLE, DEGREE45, 20, 0, 0, 0, 0, LEFTWARD, NONE_F_B});
  /* ラインからガレージ入口へ向かう */
  runSectionParamVector.push_back({LINE_TRAICE, COLOR, COLOR_BLUE, 20, 2.0, 0.03, 0.03, 18, NONE_L_R, NONE_F_B});
  runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 220, 20, 2.0, 0.03, 0.03, 18, NONE_L_R, NONE_F_B});
  runSectionParamVector.push_back({LINE_TRAICE, COLOR, COLOR_WHITE, 20, 2.0, 0.03, 0, 18, NONE_L_R, NONE_F_B});
  /* ガレージへ進入・停止 */
  runSectionParamVector.push_back({STRAIGHT, DISTANCE, 200, 20, 0, 0, 0, 0, NONE_L_R, FORWARD});
  runSectionParamVector.push_back({STOP, WAIT_TIME, 6000, 0, 0, 0, 0, 0, NONE_L_R, NONE_F_B});
}

// extern char syslogBuf[50];
void GarageGameState::run()
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

bool GarageGameState::isFinished()
{
  return runSectionParamVector.empty();
}

void GarageGameState::terminate()
{
  d.lcd_msg_debug("Stopped.", 1);
  interfaceBehaviorModel.terminate();
  interfaceDeterminationModel.terminate();
}

