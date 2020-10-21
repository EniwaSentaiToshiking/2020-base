#include "InterfaceDeterminationModel.h"

// bool InterfaceDeterminationModel::selectTouch()
// {
//     return touchDeterminationModel.determine();
// }

void InterfaceDeterminationModel::init()
{
    colorDeterminationModel.init();
    distanceDeterminationModel.init();
}


bool InterfaceDeterminationModel::selectColor(colorid_t color)
{
    return colorDeterminationModel.determine(color);
}

bool InterfaceDeterminationModel::selectDistance(float distance)
{
    return distanceDeterminationModel.determine(distance);
}

void InterfaceDeterminationModel::terminate()
{
    colorDeterminationModel.terminate();
    distanceDeterminationModel.terminate();
}