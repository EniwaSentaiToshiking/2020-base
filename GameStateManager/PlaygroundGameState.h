#pragma once

#include "DebugUtil.h"
#include "ColorDeviceDriver.h"

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
  ColorDeviceDriver colorSensor;
  DebugUtil debugUtil;
};
