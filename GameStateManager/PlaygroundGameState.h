#pragma once

#include "DebugUtil.h"
#include "ColorSensorDeviceDriver.h"

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
  ColorSensorDeviceDriver colorSensorDeviceDriver;
  DebugUtil debugUtil;
};
