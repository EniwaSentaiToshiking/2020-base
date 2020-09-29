#include "PlaygroundGameState.h"

PlaygroundGameState::PlaygroundGameState()
{
}

void PlaygroundGameState::init()
{
  debugUtil.init("PlaygroundGameState");
  file = fopen("/color_log.csv", "a");
  if (file == NULL)
  {
    debugUtil.lcd_msg_debug("error: cannot open file", 2);
    exit(1);
  }
  fprintf(file, "H,S,V,getcolornum")
}

void PlaygroundGameState::run()
{
  // debugUtil.lcd_num_debug(colorSensor.getColorNumber(), 2);
  // debugUtil.lcd_num_debug(colorSensor.getBrightness(), 1);
  fprintf(file, "%d, %d,%d,\n", colorDeviceDriver.getBrightness());
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
  fclose(file);
}
