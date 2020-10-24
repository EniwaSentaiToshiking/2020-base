#pragma once

#include "TemplateGameState.h"
#include "InterfaceDeterminationModel.h"
#include "InterfaceBehaviorModel.h"
#include "RunSectionParam.h"
#include <vector>

using namespace std;

class RunningGameState : public TemplateGameState
{
  InterfaceDeterminationModel interfaceDeterminationModel;
  InterfaceBehaviorModel interfaceBehaviorModel;
  vector<RunSectionParam> runSectionParamVector;

  DebugUtil d;

public:
  RunningGameState();
  void init();
  void createRunSectionL();
  void createRunSectionR();
  void run();
  bool isFinished();
  void terminate();
  ~RunningGameState();
};
