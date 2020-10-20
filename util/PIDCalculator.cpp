#include "PIDCalculator.h"

PIDCalculator::PIDCalculator()
{
}

void PIDCalculator::init()
{
  previous_error = 0;
	current_error = 0;
	integral = 0;
	differential = 0;
}

int PIDCalculator::calcPID(float k_p, float k_i, float k_d, int sensor_val, int target_val)
{
  int p, i, d;

  previous_error = current_error;
  current_error = sensor_val - target_val;
  integral += current_error * dt;
  differential = (current_error - previous_error) / dt;

  p = k_p * current_error;
  i = k_i * integral;
  d = k_d * differential;

  return pwmLimit(p + i + d);
}

int PIDCalculator::pwmLimit(int pidValue)
{
  if (pidValue > absMax)
    pidValue = absMax;
  else if (pidValue < absMax * -1)
    pidValue = absMax * -1;
  return pidValue;
}

void PIDCalculator::terminate()
{
}