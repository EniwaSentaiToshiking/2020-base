#include "RunningGameState.h"

RunningGameState::RunningGameState() : leftWheel(PORT_C), rightWheel(PORT_B),
                   colorSensor(PORT_3)
{
}

void RunningGameState::init()
{
  debugUtil.init("RunningGameState");
}

void RunningGameState::run()
{
  debugUtil.lcd_msg_debug("running...", 1);
  const int m_target_color_value = 18;
  float m_control_value = pidController.calc_pid_control_pwm_value(2.0, 0.03, 0.2, colorSensor.getBrightness(), m_target_color_value);
  int m_left_pwm = pwm - m_control_value;                                                                                             
  int m_right_pwm = pwm + m_control_value;                                                                                            
  leftWheel.setPWM(m_left_pwm);
  rightWheel.setPWM(m_right_pwm);
}

bool RunningGameState::isChanged()
{
  if (colorSensor.getColorNumber() == COLOR_BLUE)
  {
    return true;
  }
  return false;
}

void RunningGameState::terminate()
{
  debugUtil.lcd_msg_debug("Stopped.", 1);
  leftWheel.stop();
  rightWheel.stop();
  debugUtil.led_debug(LED_RED);
}

