#pragma once

#include "BehaviorList.h"
#include "DeterminationList.h"
#include "SpinTurnLeftOrRight.h"

typedef struct
{
    BehaviorList behavior;
    DeterminationList determination;
    int determinationParam;
    int pwm;
    float kP;
    float kI;
    float kD;
    int targetVal;
    SpinTurnLeftOrRight spinTurnLeftOrRight;
} RunSectionParam;