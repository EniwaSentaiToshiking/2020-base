#pragma once

#include "Motor.h"
#include "ColorSensorDeviceDriver.h"
#include "DebugUtil.h"
#include "PIDCalculator.h"

using namespace ev3api;

class RunningGameState
{
public:
  RunningGameState();
  void init();
  void run();
  bool isChanged();
  void terminate();

private:
  Motor leftWheel;
  Motor rightWheel;
  ColorSensorDeviceDriver colorSensorDeviceDriver;
  PIDCalculator pidCalculator;
  DebugUtil debugUtil;
  const int8_t pwm = (Motor::PWM_MAX) / 2 + 20;
};
