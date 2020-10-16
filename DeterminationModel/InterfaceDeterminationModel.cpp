#include "InterfaceDeterminationModel.h"

// bool InterfaceDeterminationModel::selectTouch()
// {
//     return touchDeterminationModel.determine();
// }

bool InterfaceDeterminationModel::selectColor(colorid_t color)
{
    return colorDeterminationModel.determine(color);
}