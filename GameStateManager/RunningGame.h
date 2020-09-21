#pragma once

#include "Motor.h"
#include "ColorSensor.h"
#include "util.h"
#include "PIDController.h"

using namespace ev3api;

class RunningGame
{
public:
  RunningGame();
  void run();
  void init();
  void terminate();

private:
  Motor leftWheel;
  Motor rightWheel;
  ColorSensor colorSensor;
  PIDController pidController;
  const int8_t pwm = (Motor::PWM_MAX) / 2 + 10;
};
