#include "PIDController.h"

PIDController::PIDController()
{
}

PIDController::~PIDController()
{
}

int PIDController::calc_pid_control_pwm_value(PID *pid, unsigned int sensor_val, unsigned int target_val, int absMax)
{
  // absMax = (Motor::PWM_MAX) = 100
  float KP, KI, KD;

  KP = pid->k_p;
  KI = pid->k_i;
  KD = pid->k_d;

  previous_diff = current_diff;
  current_diff = sensor_val - target_val;
  integral += (current_diff + previous_diff) / 2.0 * DELTA_T;

  int _p = KP * current_diff;
  int _i = KI * integral;
  int _d = KD * (current_diff - previous_diff) / DELTA_T;

  int pid_control_pwm_value = _p + _i + _d;

  return pwm_controller_limit(pid_control_pwm_value, absMax);
}

int PIDController::pwm_controller_limit(int pid_value, int absMax)
{
  if (pid_value > absMax)
    pid_value = absMax;
  else if (pid_value < absMax * -1)
    pid_value = absMax * -1;
  return pid_value;
}