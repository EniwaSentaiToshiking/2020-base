#pragma once

#include "TemplateGameState.h"
#include "InterfaceDeterminationModel.h"
#include "InterfaceBehaviorModel.h"
#include "BehaviorDetermination.h"
#include "RunSectionParam.h"
#include <vector>

#include "DebugUtil.h"

using namespace ev3api;
using namespace std;

class PlaygroundGameState : public TemplateGameState
{
  InterfaceDeterminationModel iDeterminationModel;
  InterfaceBehaviorModel iBehaviorModel;
  vector<RunSectionParam> runSectionParamVector;

  DebugUtil d;

public:
  PlaygroundGameState();
  void init();
  void run();
  bool isFinished();
  void terminate();
};
