#include "BlockBingoGameState.h"

BlockBingoGameState::BlockBingoGameState()
{
}

extern int edge;
void BlockBingoGameState::init()
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

void BlockBingoGameState::createRunSectionL()
{
  /* ガレージ前のラインに復帰する */
  runSectionParamVector.push_back({STRAIGHT, DISTANCE, 300, 20, 0, 0, 0, 0, NONE_L_R, BACKWARD});
  runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 100, 10, 2.0, 0.03, 0.02, 18, NONE_L_R, NONE_F_B});
  runSectionParamVector.push_back({STRAIGHT, DISTANCE, 425, 20, 0, 0, 0, 0, NONE_L_R, BACKWARD});
  runSectionParamVector.push_back({STOP, WAIT_TIME, 100, 0, 0, 0, 0, 0, NONE_L_R, NONE_F_B});
  runSectionParamVector.push_back({SPIN_TURN, SPIN_TURN_ANGLE, DEGREE90, 20, 0, 0, 0, 0, RIGHTWARD, NONE_F_B});
  // runSectionParamVector.push_back({STRAIGHT, DISTANCE, 650, 20, 0, 0, 0, 0, NONE_L_R, FORWARD});
  runSectionParamVector.push_back({STRAIGHT, COLOR, COLOR_BLACK, 20, 0, 0, 0, 0, NONE_L_R, FORWARD});
  runSectionParamVector.push_back({LINE_TRAICE, COLOR, COLOR_YELLOW, 10, 2.0, 0.03, 0.02, 18, NONE_L_R, NONE_F_B});
  // runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 300, 20, 2.0, 0.03, 0.03, 18, NONE_L_R, NONE_F_B});
  // runSectionParamVector.push_back({LINE_TRAICE, COLOR, COLOR_WHITE, 20, 1.3, 0.03, 0, 18, NONE_L_R, NONE_F_B});
  /* ブロックビンゴエリアに向かう */
  // runSectionParamVector.push_back({STOP, WAIT_TIME, 100, 0, 0, 0, 0, 0, NONE_L_R, NONE_F_B});
  // runSectionParamVector.push_back({SPIN_TURN, SPIN_TURN_ANGLE, DEGREE90, 20, 0, 0, 0, 0, LEFTWARD, NONE_F_B});
  // runSectionParamVector.push_back({STRAIGHT, COLOR, COLOR_BLACK, 20, 0, 0, 0, 0, NONE_L_R, FORWARD});
  runSectionParamVector.push_back({STOP, STOP_DETERMINATION, 0, 0, 0, 0, 0, 0, NONE_L_R, NONE_F_B});
}

void BlockBingoGameState::createRunSectionR()
{
  runSectionParamVector.push_back({STOP, STOP_DETERMINATION, 0, 0, 0, 0, 0, 0, NONE_L_R, NONE_F_B});
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
    // snprintf(syslogBuf, sizeof(syslogBuf), "bhavior, %d, pwm, %d",
    //          currentRunSectionParam.behavior, currentRunSectionParam.pwm);
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

