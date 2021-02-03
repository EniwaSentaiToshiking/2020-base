/*
 * Created on Wed Feb 03 2021
 *
 * Copyright (c) 2021 Kazuki Hamaguchi
 */
#pragma once

#include "TemplateDeterminationModel.h"
#include "ColorSensorDeviceDriver.h"


class ColorCircleDeterminationModel : public TemplateDeterminationModel
{
    ColorSensorDeviceDriver colorSensorDeviceDriver;
public:
    void init();
    bool determine();
    void terminate();

private:
 colorid_t colorCircle;
};