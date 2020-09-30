#include "PlaygroundGameState.h"

PlaygroundGameState::PlaygroundGameState()
{
}

void PlaygroundGameState::init()
{
  debugUtil.init("PlaygroundGameState");
  colorSensorDeviceDriver.init();
}

void PlaygroundGameState::run()
{
  // debugUtil.lcd_num_debug(colorDeviceDriver.getBrightness(), 1);
  // debugUtil.lcd_num_debug(colorDeviceDriver.getColorNumber(), 2);
}

bool PlaygroundGameState::isChanged()
{
  if (colorSensorDeviceDriver.getColorNumber() == COLOR_BLUE)
  {
    return true;
  }
  return false;
}

void PlaygroundGameState::terminate()
{
  debugUtil.lcd_msg_debug("Stopped.", 1);
  debugUtil.led_debug(LED_RED);
  colorSensorDeviceDriver.terminate();
}
