#include "PlaygroundGameState.h"

PlaygroundGameState::PlaygroundGameState()
{
  this->init();
}

void PlaygroundGameState::init()
{
  d.init("PlaygroundGameState");
}

void PlaygroundGameState::run()
{
  // const int m_target_color_value = 18;
  // float m_control_value = pidCalculator.calc_pid_control_pwm_value(2.0, 0.03, 0.2, colorSensorDeviceDriver.getBrightness(), m_target_color_value);
  // int m_left_pwm = pwm - m_control_value;
  // int m_right_pwm = pwm + m_control_value;
  // wheelDeviceDriver.setLeftPWM(m_left_pwm);
  // wheelDeviceDriver.setRightPWM(m_right_pwm);
  interfaceBehaviorModel.selectLineTrace(70, 2.0f, 0.03f, 0.2f, 18);
}

bool PlaygroundGameState::isFinished()
{
  // return interfaceDeterminationModel.selectDistance(600.0);
  return interfaceDeterminationModel.selectColor(COLOR_YELLOW);
}

void PlaygroundGameState::terminate()
{
  d.lcd_msg_debug("Stopped.", 1);
  d.led_debug(LED_RED);
  interfaceBehaviorModel.selectLineTrace(0,0,0,0,0);
}
