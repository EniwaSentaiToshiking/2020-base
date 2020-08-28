#include "Tracer.h"

Tracer::Tracer() : leftWheel(PORT_C), rightWheel(PORT_B),
                   colorSensor(PORT_3)
{
}

void Tracer::init()
{
  init_f("Tracer");
}

void Tracer::terminate()
{
  msg_f("Stopped.", 1);
  leftWheel.stop();
  rightWheel.stop();
}

float Tracer::calc_proportional_control_pwm_value()
{
  const float k_p = 2.0;               // <1>
  const int m_target_color_value = 10; // <2>
  const int bias = 0;

  int m_diff = colorSensor.getBrightness() - m_target_color_value; // <3>
  return (k_p * m_diff + bias);                                    // <4>
}

float Tracer::calc_pid_control_pwm_value()
{
  const float k_p = 2.0;              // <1>
  const float k_i = 0.0;
  const float k_d = 0.0;
  const float dt = 0.001; /* TRACER_TASKのハンドラ周期<sec>と同じ */
  const int m_target_color_value = 20; // <2>
  const int bias = 0;
  int p, i, d;

  previous_error = current_error;
  current_error = colorSensor.getBrightness() - m_target_color_value; // <3>
  integral += current_error * dt;

  // PIDの計算
  p = k_p * current_error;
  i = k_i * integral;
  d = k_d * (current_error - previous_error) / dt;

  // printf("p, %d, i, %d, d, %d\n",p, i, d);

  return (pwm_controller_limit(p + i + d + bias, Motor::PWM_MAX));                                    // <4>
}

int Tracer::pwm_controller_limit(int pid_value, int absMax)
{
  if (pid_value > absMax)
    pid_value = absMax;
  else if (pid_value < absMax * -1)
    pid_value = absMax * -1;
  return pid_value;
}

void Tracer::run()
{
  msg_f("running...", 1);
  float m_control_value = calc_pid_control_pwm_value();                                                                                     // <1>
  int m_left_pwm = pwm - m_control_value;                                                                                                   // <2>
  int m_right_pwm = pwm + m_control_value;                                                                                                  // <2>
  leftWheel.setPWM(m_left_pwm);
  rightWheel.setPWM(m_right_pwm);
  // printf("sensor, %d, left_pwm, %d, right_pwm, %d\n",
  //        int(colorSensor.getBrightness()), m_left_pwm, m_right_pwm);
}
