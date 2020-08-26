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

void Tracer::run()
{
  msg_f("running...", 1);
  const int m_target_color_value = 25;
  pid = new PID(2.0, 0, 0);
  float m_control_value = pidController.calc_pid_control_pwm_value(pid, colorSensor.getBrightness(), m_target_color_value, Motor::PWM_MAX); // <1>
  int m_left_pwm = pwm - m_control_value;                                                                                                   // <2>
  int m_right_pwm = pwm + m_control_value;                                                                                                  // <2>
  leftWheel.setPWM(m_left_pwm);
  rightWheel.setPWM(m_right_pwm);
  printf("sensor: %d, left_pwm: %d, right_pwm: %d\n",
         int(colorSensor.getBrightness()), m_left_pwm, m_right_pwm);
}
