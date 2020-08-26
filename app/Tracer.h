#include "Motor.h"
#include "ColorSensor.h"
#include "util.h"
#include "PID.h"
#include "PIDController.h"

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
  PID *pid;
  PIDController pidController;
  const int8_t pwm = (Motor::PWM_MAX) / 2;

  float calc_proportional_control_pwm_value(); // <1>
};
