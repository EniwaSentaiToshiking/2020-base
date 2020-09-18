#include "RunningGame.h"

RunningGame::RunningGame() : leftWheel(PORT_C), rightWheel(PORT_B),
                   colorSensor(PORT_3)
{
}

void RunningGame::init()
{
  init_f("RunningGame");
}

void RunningGame::terminate()
{
  msg_f("Stopped.", 1);
  leftWheel.stop();
  rightWheel.stop();
}

void RunningGame::run()
{
  msg_f("running...", 1);
  const int m_target_color_value = 18;
  float m_control_value = pidController.calc_pid_control_pwm_value(2.0, 0.03, 0.2, colorSensor.getBrightness(), m_target_color_value); // <1>
  int m_left_pwm = pwm - m_control_value;                                                                                              // <2>
  int m_right_pwm = pwm + m_control_value;                                                                                             // <2>
  leftWheel.setPWM(m_left_pwm);
  rightWheel.setPWM(m_right_pwm);
}
