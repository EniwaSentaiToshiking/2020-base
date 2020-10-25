#include "PlaygroundGameState.h"

PlaygroundGameState::PlaygroundGameState()
{
}

extern int edge;
extern char syslogBuf[50];
void PlaygroundGameState::init()
{
  d.init("PlaygroundGameState");
  armDeviceDriver.init();
  snprintf(syslogBuf, sizeof(syslogBuf), "init arm");
  syslog(LOG_NOTICE, syslogBuf);

  interfaceBehaviorModel.init();
  interfaceDeterminationModel.init();
  switch (edge)
  {
  case RIGHT_EDGE:
    this->createRunSectionL();
    break;
  
  case LEFT_EDGE:
    // this->createRunSectionR();
    break;
  
  default:
    break;
  }
}

void PlaygroundGameState::createRunSectionL()
{
  /* behavior, determination, determinationParam, pwm, kP, kI, kD, targetVal, spinTurnLeftOrRight, straightForwardOrBackward */
  /* ラインからガレージ入口へ向かう */
  // runSectionParamVector.push_back({LINE_TRAICE, COLOR, COLOR_BLUE, 20, 2.0, 0.03, 0.03, 18, NONE_L_R, NONE_F_B});
  // runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 220, 20, 2.0, 0.03, 0.03, 18, NONE_L_R, NONE_F_B});
  // runSectionParamVector.push_back({LINE_TRAICE, COLOR, COLOR_WHITE, 20, 2.0, 0.03, 0, 18, NONE_L_R, NONE_F_B});
  // /* ガレージへ進入・停止 */
  // runSectionParamVector.push_back({STRAIGHT, DISTANCE, 200, 20, 0, 0, 0, 0, NONE_L_R, FORWARD});
  // runSectionParamVector.push_back({STOP, WAIT_TIME, 6000, 0, 0, 0, 0, 0, NONE_L_R, NONE_F_B});

  // /* ガレージ前のラインに復帰する */
  // runSectionParamVector.push_back({STRAIGHT, DISTANCE, 300, 20, 0, 0, 0, 0, NONE_L_R, BACKWARD});
  // runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 100, 10, 2.0, 0.03, 0.02, 18, NONE_L_R, NONE_F_B});
  // runSectionParamVector.push_back({STRAIGHT, DISTANCE, 425, 20, 0, 0, 0, 0, NONE_L_R, BACKWARD});


  runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 190, 25, 2.0, 0.03, 0.02, 18, NONE_L_R, NONE_F_B});
  runSectionParamVector.push_back({STOP, WAIT_TIME, 100, 0, 0, 0, 0, 0, NONE_L_R, NONE_F_B});
  runSectionParamVector.push_back({SPIN_TURN, SPIN_TURN_ANGLE, DEGREE90, 20, 0, 0, 0, 0, RIGHTWARD, NONE_F_B});
  // runSectionParamVector.push_back({STRAIGHT, DISTANCE, 650, 20, 0, 0, 0, 0, NONE_L_R, FORWARD});
  runSectionParamVector.push_back({STRAIGHT, COLOR, COLOR_BLACK, 40, 0, 0, 0, 0, NONE_L_R, FORWARD});
  runSectionParamVector.push_back({STOP, WAIT_TIME, 100, 0, 0, 0, 0, 0, NONE_L_R, NONE_F_B});
  runSectionParamVector.push_back({SPIN_TURN, SPIN_TURN_ANGLE, DEGREE45, 20, 0, 0, 0, 0, LEFTWARD, NONE_F_B});


  /* ブロックビンゴエリア内 */
  /* 1つめ搬入 直進搬入 */
  this->lineTraceBetweenCircles();
  this->straightCircle();
  this->rightCarryInBlock45Degree();
  this->rightReturnLine45Degree();

  /* 2つめ搬入 旋回搬入 */
  this->lineTraceBetweenCircles();
  this->straightCircle();
  this->lineTraceBetweenCircles();
  this->rightTurnCircle90Degree();
  this->rightCarryInBlock45Degree();
  this->rightReturnLine45Degree();

  /* 回送 直進*/
  this->lineTraceBetweenCircles();
  this->straightCircle();

  /* 3つめ搬入 直進搬入 */
  this->lineTraceBetweenCircles();
  this->straightCircle();
  this->rightCarryInBlock45Degree();
  this->rightReturnLine45Degree();

  /* 回送 右90*/
  this->lineTraceBetweenCircles();
  this->rightTurnCircle90Degree();

  /* 4つめ 直進搬入 */
  this->lineTraceBetweenCircles();
  this->straightCircle();
  this->rightCarryInBlock45Degree();
  this->rightReturnLine45Degree();

  /* 回送 直進*/
  this->lineTraceBetweenCircles();
  this->straightCircle();

  /* 5つめ搬入 旋回搬入 */
  this->lineTraceBetweenCircles();
  this->straightCircle();
  this->lineTraceBetweenCircles();
  this->rightTurnCircle90Degree();
  this->rightCarryInBlock45Degree();
  this->rightReturnLine45Degree();






  // runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 300, 20, 2.0, 0.03, 0.03, 18, NONE_L_R, NONE_F_B});
  // runSectionParamVector.push_back({LINE_TRAICE, COLOR, COLOR_WHITE, 20, 1.3, 0.03, 0, 18, NONE_L_R, NONE_F_B});
  /* ブロックビンゴエリアに向かう */
  // runSectionParamVector.push_back({STOP, WAIT_TIME, 100, 0, 0, 0, 0, 0, NONE_L_R, NONE_F_B});
  // runSectionParamVector.push_back({SPIN_TURN, SPIN_TURN_ANGLE, DEGREE90, 20, 0, 0, 0, 0, LEFTWARD, NONE_F_B});
  // runSectionParamVector.push_back({STRAIGHT, COLOR, COLOR_BLACK, 20, 0, 0, 0, 0, NONE_L_R, FORWARD});
  runSectionParamVector.push_back({STOP, STOP_DETERMINATION, 0, 0, 0, 0, 0, 0, NONE_L_R, NONE_F_B});
}

void PlaygroundGameState::createRunSectionR()
{
  /* behavior, determination, determinationParam, pwm, kP, kI, kD, targetVal, spinTurnLeftOrRight, straightForwardOrBackward */
  runSectionParamVector.push_back({STOP, STOP_DETERMINATION, 0, 0, 0, 0, 0, 0, NONE_L_R, NONE_F_B});
}

void PlaygroundGameState::lineTraceBetweenCircles()
{
  runSectionParamVector.push_back({LINE_TRAICE, COLOR_CIRCLE, 0, 15, 2.0, 0.03, 0.02, 18, NONE_L_R, NONE_F_B});
}

void PlaygroundGameState::straightCircle()
{
  runSectionParamVector.push_back({STRAIGHT, DISTANCE, 106, 20, 0, 0, 0, 0, NONE_L_R, FORWARD});
}

// void PlaygroundGameState::straightHoldBlock()
// {
//   this->straightCircle();
// }

void PlaygroundGameState::rightTurnCircle90Degree()
{
  runSectionParamVector.push_back({STRAIGHT, DISTANCE, 50, 20, 0, 0, 0, 0, NONE_L_R, FORWARD});
  runSectionParamVector.push_back({STOP, WAIT_TIME, 50, 0, 0, 0, 0, 0, NONE_L_R, NONE_F_B});
  runSectionParamVector.push_back({SPIN_TURN, SPIN_TURN_ANGLE, 90, 20, 0, 0, 0, 0, RIGHTWARD, NONE_F_B});
  runSectionParamVector.push_back({STOP, WAIT_TIME, 50, 0, 0, 0, 0, 0, NONE_L_R, NONE_F_B});
  runSectionParamVector.push_back({STRAIGHT, DISTANCE, 50, 20, 0, 0, 0, 0, NONE_L_R, FORWARD});
}

// void PlaygroundGameState::rightTurnRHoldBlock90Degree()
// {
//   this->rightTurnRCircle90Degree();
// }

void PlaygroundGameState::rightCarryInBlock45Degree()
{
  runSectionParamVector.push_back({STOP, WAIT_TIME, 50, 0, 0, 0, 0, 0, NONE_L_R, FORWARD});
  runSectionParamVector.push_back({SPIN_TURN, SPIN_TURN_ANGLE, DEGREE45, 20, 0, 0, 0, 0, RIGHTWARD, NONE_F_B});
  runSectionParamVector.push_back({STRAIGHT, DISTANCE, 200, 20, 0, 0, 0, 0, NONE_L_R, FORWARD});
}

void PlaygroundGameState::rightReturnLine45Degree()
{
  runSectionParamVector.push_back({STRAIGHT, DISTANCE, 150, 20, 0, 0, 0, 0, NONE_L_R, BACKWARD});
  runSectionParamVector.push_back({STOP, WAIT_TIME, 50, 0, 0, 0, 0, 0, NONE_L_R, NONE_F_B});
  runSectionParamVector.push_back({SPIN_TURN, SPIN_TURN_ANGLE, DEGREE45, 20, 0, 0, 0, 0, LEFTWARD, NONE_F_B});
}


extern char syslogBuf[50];
void PlaygroundGameState::run()
{
  d.lcd_msg_debug("running...", 1);
  armDeviceDriver.rotateDefault();
  RunSectionParam currentRunSectionParam = runSectionParamVector.front();
  interfaceBehaviorModel.run(currentRunSectionParam);

  if (interfaceDeterminationModel.determine(currentRunSectionParam))
  {
    interfaceDeterminationModel.terminate();
    snprintf(syslogBuf, sizeof(syslogBuf), "bhavior, %d, pwm, %d",
             currentRunSectionParam.behavior, currentRunSectionParam.pwm);
    syslog(LOG_NOTICE, syslogBuf);
    runSectionParamVector.erase(runSectionParamVector.begin());
  }
}

bool PlaygroundGameState::isFinished()
{
  return runSectionParamVector.empty();
  // return false;
}


void PlaygroundGameState::terminate()
{
  d.led_debug(LED_RED);
  d.lcd_msg_debug("Stopped.", 1);
  interfaceBehaviorModel.terminate();
  interfaceDeterminationModel.terminate();
}
