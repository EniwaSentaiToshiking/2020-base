#include "PIDController.h"

PIDController::PIDController()
{
}

PIDController::~PIDController()
{
}

int PIDController::calc_pid_control_pwm_value(float k_p, float k_i, float k_d, unsigned int sensor_val, unsigned int target_val)
{
  int p, i, d;

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
  if (pid_value > absMax)
    pid_value = absMax;
  else if (pid_value < absMax * -1)
    pid_value = absMax * -1;
  return pid_value;
}