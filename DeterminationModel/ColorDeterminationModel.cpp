#include "ColorDeterminationModel.h"

bool ColorDeterminationModel::determine(colorid_t color)
{
    if (colorSensorDeviceDriver.getColorNumber() == color)
    {
        return true;
    }
    return false;
}