#pragma once

#include "DebugUtil.h"
#include "ColorSensor.h"
#include <stdio.h>

using namespace ev3api;

class PlaygroundGameState
{
public:
  PlaygroundGameState();
  void init();
  void run();
  bool isChanged();
  void terminate();

private:
  ColorSensor colorSensor;
  DebugUtil debugUtil;
};
