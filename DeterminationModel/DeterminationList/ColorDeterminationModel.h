#pragma once

#include "TemplateDeterminationModel.h"
#include "ColorSensorDeviceDriver.h"

class ColorDeterminationModel : public TemplateDeterminationModel
{
    ColorSensorDeviceDriver colorSensorDeviceDriver;
public:
    void init();
    bool determine(colorid_t color);
    void terminate();
};