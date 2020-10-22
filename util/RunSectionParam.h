#pragma once

#include "BehaviorActionList.h"
#include "DeterminationActionList.h"

typedef struct
{
    DeterminationActionList determinationActionList;
    int determinationParam;
    int pwm;
    float kP;
    float kI;
    float kD;
    int targetVal;
} RunSectionParam;