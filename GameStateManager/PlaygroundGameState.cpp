#include "PlaygroundGameState.h"

PlaygroundGameState::PlaygroundGameState()
{
}

void PlaygroundGameState::init()
{
  debugUtil.init("PlaygroundGameState");
}

void PlaygroundGameState::run()
{
  debugUtil.lcd_num_debug(colorSensor.getColorNumber(), 2);
  // debugUtil.lcd_num_debug(colorSensor.getBrightness(), 3);
}

bool PlaygroundGameState::isChanged()
{
  if (colorSensor.getColorNumber() == COLOR_BLUE)
  {
    return true;
  }
  return false;
}

void PlaygroundGameState::terminate()
{
  debugUtil.lcd_msg_debug("Stopped.", 1);
  debugUtil.led_debug(LED_RED);
}
