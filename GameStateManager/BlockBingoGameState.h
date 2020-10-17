#pragma once

#include "Motor.h"
#include "ColorSensorDeviceDriver.h"
#include "DebugUtil.h"
#include "PIDCalculator.h"

using namespace ev3api;

class BlockBingoGameState
{
  Motor leftWheel;
  Motor rightWheel;
  ColorSensorDeviceDriver colorSensorDeviceDriver;
  PIDCalculator pidCalculator;
  DebugUtil debugUtil;

public:
  BlockBingoGameState();
  void init();
  void run();
  bool isChanged();
  void terminate();

private:
  const int8_t pwm = (Motor::PWM_MAX) / 3;
};
