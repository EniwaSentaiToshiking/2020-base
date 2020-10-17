#pragma once

#include "TemplateGameState.h"
#include "DebugUtil.h"
#include "InterfaceDeterminationModel.h"
#include "PIDCalculator.h"

#include "ColorSensorDeviceDriver.h"
#include "WheelDeviceDriver.h"

using namespace ev3api;

class PlaygroundGameState : public TemplateGameState
{
  DebugUtil d;
  InterfaceDeterminationModel interfaceDeterminationModel;
  
  PIDCalculator pidCalculator;
  ColorSensorDeviceDriver colorSensorDeviceDriver;
  WheelDeviceDriver wheelDeviceDriver;

public:
  PlaygroundGameState();
  void init();
  void run();
  bool isFinished();
  void terminate();

private:
  const int8_t pwm = 30;
};
