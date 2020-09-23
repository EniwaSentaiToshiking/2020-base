#pragma once

#include "Motor.h"
#include "ColorSensor.h"
#include "DebugUtil.h"
#include "PIDController.h"

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
  ColorSensor colorSensor;
  PIDController pidController;
  DebugUtil debugUtil;
  const int8_t pwm = (Motor::PWM_MAX) / 2 + 20;
};
