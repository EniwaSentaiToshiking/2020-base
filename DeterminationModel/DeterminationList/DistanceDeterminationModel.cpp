#include "DistanceDeterminationModel.h"

void DistanceDeterminationModel::init()
{
    wheelDeviceDriver.init();
}


bool DistanceDeterminationModel::determine(float distance)
{
    if (wheelDeviceDriver.getDistance() >= distance) {
        return true;
    }
    return false;
}

void DistanceDeterminationModel::terminate()
{
    wheelDeviceDriver.resetDistance();
}