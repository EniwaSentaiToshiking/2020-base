#pragma once

#include "TemplateDeterminationModel.h"
#include "ColorSensorDeviceDriver.h"

class ColorDeterminationModel : public TemplateDeterminationModel
{
    ColorSensorDeviceDriver colorSensorDeviceDriver;
public:
    bool determine(colorid_t color);
};