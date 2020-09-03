#include "pid_controller.h"

PIDController::PIDController()
{
  previous_error = 0;
  current_error = 0;
  integral = 0;
  differential = 0;
}

PIDController::~PIDController()
{
}

int PIDController::calc_pid_control_pwm_value(float k_p, float k_i, float k_d, unsigned int sensor_val, unsigned int target_val)
{
  int p, i, d;
  const float dt = 0.001; /* TRACER_TASKのハンドラ周期<sec>と同じ */


  previous_error = current_error;
  current_error = sensor_val - target_val;
  integral += current_error * dt;
  differential = (current_error - previous_error) / dt;

  p = k_p * current_error;
  i = k_i * integral;
  d = k_d * differential;

  return pwm_controller_limit(p + i + d);
}

int PIDController::pwm_controller_limit(int pid_value)
{
  static const int abs_max = 100;
  if (pid_value > abs_max)
    pid_value = abs_max;
  else if (pid_value < abs_max * -1)
    pid_value = abs_max * -1;
  return pid_value;
}