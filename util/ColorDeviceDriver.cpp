#include "ColorDeviceDriver.h"

ColorDeviceDriver::ColorDeviceDriver() : colorSensor(PORT_3)
{
}

void ColorDeviceDriver::getRawColor()
{
    colorSensor.getRawColor(rgb);
}

int ColorDeviceDriver::getRawColorRed()
{
    return rgb.r;
}

int ColorDeviceDriver::getRawColorGreen()
{
    return rgb.g;
}

int ColorDeviceDriver::getRawColorBule()
{
    return rgb.b;
}