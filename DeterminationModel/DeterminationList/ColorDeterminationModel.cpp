/*
 * Created on Wed Feb 03 2021
 *
 * Copyright (c) 2021 Kazuki Hamaguchi
 */
#include "ColorDeterminationModel.h"

void ColorDeterminationModel::init()
{
    colorSensorDeviceDriver.init();
}

bool ColorDeterminationModel::determine(colorid_t color)
{
    if (colorSensorDeviceDriver.getColorNumber() == color)
    {
        return true;
    }
    return false;
}

void ColorDeterminationModel::terminate()
{
    colorSensorDeviceDriver.terminate();
}