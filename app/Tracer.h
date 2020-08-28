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
  const int8_t pwm = (Motor::PWM_MAX) / 4 * 3;
  float previous_error;
  float current_error;
  float integral;

  float calc_proportional_control_pwm_value(); // <1>
  float calc_pid_control_pwm_value();
  int pwm_controller_limit(int pid_value, int absMax);
};
