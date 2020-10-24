#include "ColorCircleDeterminationModel.h"

void ColorCircleDeterminationModel::init()
{
    colorSensorDeviceDriver.init();
}

bool ColorCircleDeterminationModel::determine()
{
    colorCircle = colorSensorDeviceDriver.getColorNumber(); 
    bool isRed = (colorCircle == COLOR_RED);
    bool isYellow = (colorCircle == COLOR_YELLOW);
    bool isBule = (colorCircle == COLOR_BLUE);
    bool isGreen = (colorCircle == COLOR_GREEN);
    return (isRed | isYellow | isBule | isGreen) ? true : false;
}

void ColorCircleDeterminationModel::terminate()
{
    colorSensorDeviceDriver.terminate();
}