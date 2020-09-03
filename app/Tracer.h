#include "Motor.h"
#include "ColorSensor.h"
#include "util.h"
#include "pid_controller.h"

using namespace ev3api;

class Tracer
{
public:
  Tracer();
  void run();
  void init();
  void terminate();

private:
  Motor leftWheel;
  Motor rightWheel;
  ColorSensor colorSensor;
  PIDController pidController;
  static const int8_t pwm = (Motor::PWM_MAX) / 2 + 10;
};
