#ifndef COURCEMONITOR_H
#define COURCEMONITOR_H

#include "ColorSensorDriver.h"

using namespace ev3api;

class CourseMonitor
{

private:
  ColorSensorDriver *colorSensor;

  void getRawColor();

  int getColorRed();
  int getColorGreen();
  int getColorBlue();

public:
  CourseMonitor();
  int getCurrentBrightness();
  /**
     * getColorNumber - RGBを測定する 
     *
     * @param  {void}
     * @return {colorid_t}      
     */
  colorid_t getColorNumber();
  virtual ~CourseMonitor();
};

#endif
