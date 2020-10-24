#include "InterfaceDeterminationModel.h"

void InterfaceDeterminationModel::init()
{
    colorDeterminationModel.init();
    distanceDeterminationModel.init();
    spinTurnAngleDeterminationModel.init();
    waitTimeDterminationModel.init();
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
        
    case WAIT_TIME:
        return waitTimeDterminationModel.determine((uint64_t)currentRunSectionParam.determinationParam);
        break;

    case COLOR_CIRCLE:
        return colorCircleDeterminationModel.determine();
        break;

    case STOP_DETERMINATION:
        return true;
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
    waitTimeDterminationModel.terminate();
}