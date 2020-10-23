#include "InterfaceDeterminationModel.h"

void InterfaceDeterminationModel::init()
{
    colorDeterminationModel.init();
    distanceDeterminationModel.init();
    spinTurnAngleDeterminationModel.init();
}

bool InterfaceDeterminationModel::determine(RunSectionParam currentRunSectionParam)
{
    switch (currentRunSectionParam.determination)
    {
    case COLOR:
        return colorDeterminationModel.determine((colorid_t)currentRunSectionParam.determinationParam);
        break;

    case DISTANCE:
        return distanceDeterminationModel.determine(currentRunSectionParam.determinationParam);
        break;

    case SPIN_TURN_ANGLE:
        return spinTurnAngleDeterminationModel.determine((SpinTurnAngleList)currentRunSectionParam.determinationParam);
        break;
    default:
        return false;
        break;
    }
}

void InterfaceDeterminationModel::terminate()
{
    colorDeterminationModel.terminate();
    distanceDeterminationModel.terminate();
    spinTurnAngleDeterminationModel.terminate();
}