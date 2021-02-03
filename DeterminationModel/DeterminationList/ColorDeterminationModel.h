/*
 * Created on Wed Feb 03 2021
 *
 * Copyright (c) 2021 Kazuki Hamaguchi
 */
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