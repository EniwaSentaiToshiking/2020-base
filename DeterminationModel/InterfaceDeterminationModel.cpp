#include "InterfaceDeterminationModel.h"

// bool InterfaceDeterminationModel::selectTouch()
// {
//     return touchDeterminationModel.determine();
// }

void InterfaceDeterminationModel::init()
{
    colorDeterminationModel.init();
    distanceDeterminationModel.init();
    spinTurnAngleDeterminationModel.init();
}


bool InterfaceDeterminationModel::selectColor(colorid_t color)
{
    return colorDeterminationModel.determine(color);
}

bool InterfaceDeterminationModel::selectDistance(float distance)
{
    return distanceDeterminationModel.determine(distance);
}

bool InterfaceDeterminationModel::selectAngle(SpinTurnAngleList spinTurnAngletance)
{
    return distanceDeterminationModel.determine(spinTurnAngletance);
}

void InterfaceDeterminationModel::terminate()
{
    colorDeterminationModel.terminate();
    distanceDeterminationModel.terminate();
    spinTurnAngleDeterminationModel.terminate();
}