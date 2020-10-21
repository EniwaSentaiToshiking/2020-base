#pragma once

#include "TemplateGameState.h"
#include "InterfaceDeterminationModel.h"
#include "InterfaceBehaviorModel.h"
#include "BehaviorDetermination.h"
#include <vector>

#include "DebugUtil.h"

#define SECTION_NUM 15

using namespace ev3api;
using namespace std;


typedef struct 
{
  float distance;
  int pwm;
  float kP;
  float kI;
  float kD;
  int targetVal;
}RunSectionParam;

// typedef std::queue<RunSectionParam> RunSectionParamQueue;

class PlaygroundGameState : public TemplateGameState
{
  // std::queue<BehaviorDetermination> behaviorDeterminationQueue;
  InterfaceDeterminationModel iDeterminationModel;
  InterfaceBehaviorModel iBehaviorModel;
  WheelDeviceDriver wheelDeviceDriver;
  // RunSectionParam runSectionParam[SECTION_NUM] =
  // {
  //     {600.0, 90, 2.0, 0.03, 0.2, 18},
  //     {800.0, 90, 2.0, 0.03, 0.2, 18},
  //     {1000.0, 80, 2.0, 0.03, 0.2, 18},
  //     {500.0, 80, 2.0, 0.03, 0.2, 18},
  //     {800.0, 0, 2.0, 0.03, 0.2, 18}
  // };
  vector<RunSectionParam> runSectionParamVector;

  DebugUtil d;

public:
  PlaygroundGameState();
  void init();
  void run();
  // bool isFinished();
  void terminate();
  bool isFinishedFlag;

private:
  // BehaviorDetermination currentBehaviorDetermination;
  int runSection;
};
