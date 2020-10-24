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