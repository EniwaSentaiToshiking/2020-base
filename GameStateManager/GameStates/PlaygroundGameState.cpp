/*
 * Created on Wed Feb 03 2021
 *
 * Copyright (c) 2021 Kazuki Hamaguchi
 */
#include "PlaygroundGameState.h"

PlaygroundGameState::PlaygroundGameState()
{
    // logfile = fopen("logging_block_bingo.csv", "a");
}

extern char syslogBuf[50];

extern int edge;
void PlaygroundGameState::init()
{
  d.init("PlaygroundGameState");
  armDeviceDriver.init();

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

void PlaygroundGameState::createRunSectionL()
{
  /* behavior, determination, determinationParam, pwm, kP, kI, kD, targetVal, spinTurnLeftOrRight, straightForwardOrBackward */
  /* ラインからガレージ入口へ向かう */
  runSectionParamVector.push_back({LINE_TRAICE, COLOR, COLOR_BLUE, 40, 2.0, 0.03, 0.03, 18, NONE_L_R, NONE_F_B});
  runSectionParamVector.push_back({LINE_TRAICE, DISTANCE, 220, 40, 2.0, 0.03, 0.03, 18, NONE_L_R, NONE_F_B});
  runSectionParamVector.push_back({LINE_TRAICE, COLOR, COLOR_WHITE, 30, 2.0, 0.03, 0, 18, NONE_L_R, NONE_F_B});
  // /* ガレージへ進入・停止 */
  runSectionParamVector.push_back({STRAIGHT, DISTANCE, 200, 20, 0, 0, 0, 0, NONE_L_R, FORWARD});
  runSectionParamVector.push_back({STOP, WAIT_TIME, 6000, 0, 0, 0, 0, 0, NONE_L_R, NONE_F_B});

  // /* ガレージ前のラインに復帰する */
  runSectionParamVector.push_back({STRAIGHT, DISTANCE, 500, 40, 0, 0, 0, 0, NONE_L_R, BACKWARD});
  runSectionParamVector.push_back({STRAIGHT, DISTANCE, 200, 20, 0, 0, 0, 0, NONE_L_R, BACKWARD});


  runSectionParamVector.push_back({STOP, WAIT_TIME, 150, 0, 0, 0, 0, 0, NONE_L_R, NONE_F_B});
  runSectionParamVector.push_back({SPIN_TURN, SPIN_TURN_ANGLE, DEGREE90, 30, 0, 0, 0, 0, RIGHTWARD, NONE_F_B});
  runSectionParamVector.push_back({STOP, WAIT_TIME, 150, 0, 0, 0, 0, 0, NONE_L_R, NONE_F_B});
  runSectionParamVector.push_back({STRAIGHT, DISTANCE, 100, 20, 0, 0, 0, 0, NONE_L_R, FORWARD});
  runSectionParamVector.push_back({STRAIGHT, COLOR, COLOR_BLACK, 50, 0, 0, 0, 0, NONE_L_R, FORWARD});
  runSectionParamVector.push_back({STOP, WAIT_TIME, 100, 0, 0, 0, 0, 0, NONE_L_R, NONE_F_B});
  runSectionParamVector.push_back({SPIN_TURN, SPIN_TURN_ANGLE, DEGREE45, 30, 0, 0, 0, 0, LEFTWARD, NONE_F_B});
  runSectionParamVector.push_back({STOP, WAIT_TIME, 100, 0, 0, 0, 0, 0, NONE_L_R, NONE_F_B});


  /* ブロックビンゴエリア内 */
  /* 1つめ搬入 直進搬入 */
  this->straightHoldCarryInBlock();

  /* 回送 直進*/
  this->straightPassThroughCircle();
  
  /* 2つめ搬入 旋回搬入 */
  this->rightTurnHoldCarryInBlock();

  /* 回送 直進*/
  this->straightPassThroughCircle();

  /* 3つめ搬入 直進搬入 */
  this->straightHoldCarryInBlock();

  /* 回送 右90*/
  this->rightTurnPassThroughCircle();

  /* 4つめ 直進搬入 */
  this->straightHoldCarryInBlock();

  /* 回送 直進*/
  this->straightPassThroughCircle();

  /* 5つめ搬入 旋回搬入 */
  this->rightTurnHoldCarryInBlock();

  this->straightPassThroughCircle();
  this->rightTurnHoldCarryInBlock();

  this->straightPassThroughCircle();
  this->straightHoldCarryInBlock();

  this->rightTurnPassThroughCircle();
  this->rightTurnPassThroughCircle();
  this->straightPassThroughCircle();
  this->straightHoldCarryInBlock();

  runSectionParamVector.push_back({STOP, STOP_DETERMINATION, 0, 0, 0, 0, 0, 0, NONE_L_R, NONE_F_B});
}



void PlaygroundGameState::createRunSectionR()
{
  /* behavior, determination, determinationParam, pwm, kP, kI, kD, targetVal, spinTurnLeftOrRight, straightForwardOrBackward */
  runSectionParamVector.push_back({STOP, STOP_DETERMINATION, 0, 0, 0, 0, 0, 0, NONE_L_R, NONE_F_B});
}

void PlaygroundGameState::lineTraceBetweenCircles()
{
  runSectionParamVector.push_back({LINE_TRAICE, COLOR_CIRCLE, 0, 30, 2.0, 0.03, 0, 18, NONE_L_R, NONE_F_B});
}

void PlaygroundGameState::straightCircle()
{
  runSectionParamVector.push_back({STRAIGHT, DISTANCE, 110, 30, 0, 0, 0, 0, NONE_L_R, FORWARD});
}

void PlaygroundGameState::straightHoldBlock()
{
  runSectionParamVector.push_back({STRAIGHT, DISTANCE, 110, 20, 0, 0, 0, 0, NONE_L_R, FORWARD});
}

void PlaygroundGameState::rightTurnCircle90Degree()
{
  runSectionParamVector.push_back({STRAIGHT, DISTANCE, 60, 30, 0, 0, 0, 0, NONE_L_R, FORWARD});
  runSectionParamVector.push_back({STOP, WAIT_TIME, 50, 0, 0, 0, 0, 0, NONE_L_R, NONE_F_B});
  runSectionParamVector.push_back({SPIN_TURN, SPIN_TURN_ANGLE, DEGREE90, 30, 0, 0, 0, 0, RIGHTWARD, NONE_F_B});
  runSectionParamVector.push_back({STOP, WAIT_TIME, 50, 0, 0, 0, 0, 0, NONE_L_R, NONE_F_B});
  runSectionParamVector.push_back({STRAIGHT, DISTANCE, 55, 30, 0, 0, 0, 0, NONE_L_R, FORWARD});
}

void PlaygroundGameState::rightTurnRHoldBlock90Degree()
{
  runSectionParamVector.push_back({STRAIGHT, DISTANCE, 55, 20, 0, 0, 0, 0, NONE_L_R, FORWARD});
  runSectionParamVector.push_back({STOP, WAIT_TIME, 50, 0, 0, 0, 0, 0, NONE_L_R, NONE_F_B});
  runSectionParamVector.push_back({SPIN_TURN, SPIN_TURN_ANGLE, DEGREE90, 15, 0, 0, 0, 0, RIGHTWARD, NONE_F_B});
  runSectionParamVector.push_back({STOP, WAIT_TIME, 50, 0, 0, 0, 0, 0, NONE_L_R, NONE_F_B});
  runSectionParamVector.push_back({STRAIGHT, DISTANCE, 55, 20, 0, 0, 0, 0, NONE_L_R, FORWARD});
}

void PlaygroundGameState::rightCarryInBlock45Degree()
{
  runSectionParamVector.push_back({STOP, WAIT_TIME, 50, 0, 0, 0, 0, 0, NONE_L_R, FORWARD});
  runSectionParamVector.push_back({SPIN_TURN, SPIN_TURN_ANGLE, DEGREE45, 15, 0, 0, 0, 0, RIGHTWARD, NONE_F_B});
  runSectionParamVector.push_back({STOP, WAIT_TIME, 50, 0, 0, 0, 0, 0, NONE_L_R, NONE_F_B});
  runSectionParamVector.push_back({STRAIGHT, DISTANCE, 140, 25, 0, 0, 0, 0, NONE_L_R, FORWARD});
}

void PlaygroundGameState::rightReturnLine45Degree()
{
  runSectionParamVector.push_back({STRAIGHT, DISTANCE, 125, 30, 0, 0, 0, 0, NONE_L_R, BACKWARD});
  runSectionParamVector.push_back({STOP, WAIT_TIME, 50, 0, 0, 0, 0, 0, NONE_L_R, NONE_F_B});
  runSectionParamVector.push_back({SPIN_TURN, SPIN_TURN_ANGLE, DEGREE45, 25, 0, 0, 0, 0, LEFTWARD, NONE_F_B});
  runSectionParamVector.push_back({STOP, WAIT_TIME, 50, 0, 0, 0, 0, 0, NONE_L_R, NONE_F_B});
}


void PlaygroundGameState::straightHoldCarryInBlock()
{
  this->lineTraceBetweenCircles();
  this->straightHoldBlock();
  this->rightCarryInBlock45Degree();
  this->rightReturnLine45Degree();
}

void PlaygroundGameState::straightPassThroughCircle()
{
  this->lineTraceBetweenCircles();
  this->straightCircle();
}

void PlaygroundGameState::rightTurnHoldCarryInBlock()
{
  this->lineTraceBetweenCircles();
  this->rightTurnRHoldBlock90Degree();
  this->rightCarryInBlock45Degree();
  this->rightReturnLine45Degree();
}

void PlaygroundGameState::rightTurnPassThroughCircle()
{
  this->lineTraceBetweenCircles();
  this->rightTurnCircle90Degree();
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
    // fprintf(logfile, "behav,%d,determ,%d,determ_pram,%d,pwm,%d,targetVal,%d\n",
    //          currentRunSectionParam.behavior, currentRunSectionParam.determination,
    //           currentRunSectionParam.determinationParam, currentRunSectionParam.pwm, currentRunSectionParam.targetVal);
    // syslog(LOG_NOTICE, syslogBuf);
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
  // fclose(logfile);
}
