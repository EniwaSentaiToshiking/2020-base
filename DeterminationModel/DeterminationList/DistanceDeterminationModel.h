/*
 * Created on Wed Feb 03 2021
 *
 * Copyright (c) 2021 Kazuki Hamaguchi
 */
#pragma once

#include "TemplateDeterminationModel.h"
#include "WheelDeviceDriver.h"

class DistanceDeterminationModel : public TemplateDeterminationModel
{
    WheelDeviceDriver wheelDeviceDriver;

public:
    void init();
    bool determine(float distance);
    void terminate();
};