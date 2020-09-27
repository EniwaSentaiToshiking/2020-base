#pragma once

#include "ColorSensor.h"
using namespace ev3api;

class ColorDeviceDriver
{
public:
    ColorDeviceDriver();
    void getRawColor();
    int getRawColorRed();
    int getRawColorGreen();
    int getRawColorBule();

private:
    rgb_raw_t rgb;
    ColorSensor colorSensor;
};