#pragma once

#include "InterfaceBehaviorModel.h"
#include "InterfaceDeterminationModel.h"

typedef struct 
{
    InterfaceBehaviorModel behavior;
    InterfaceDeterminationModel determination;
}BehaviorDetermination;