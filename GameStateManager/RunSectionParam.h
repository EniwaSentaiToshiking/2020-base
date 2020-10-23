#pragma once

#include "BehaviorList.h"
#include "DeterminationList.h"
#include "SpinTurnLeftOrRight.h"
#include "StraightForwardOrBackward.h"


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
    StraightForwardOrBackward straightForwardOrBackward;
} RunSectionParam;

/* 
Example RunSectionParam setting

behavior, determination, determinationParam, pwm, kP, kI, kD, targetVal, spinTurnLeftOrRight, straightForwardOrBackward

line trace behavior state change determin distance 400mm.
RunSectionParam{LINE_TRAICE, DISTANCE, 400, 20, 2.0, 0.03, 0.2, 18, NONE, NONE};

line trace behavior state change determin color yellow.
RunSectionParam{LINE_TRAICE, COLOR, COLOR_YELLOW, 20, 2.0, 0.03, 0.2, 18, NONE, NONE};

spin turn left behavior state change determin 180 degree.
RunSectionParam{SPIN_TURN, SPIN_TURN_ANGLE, DEGREE180, 20, 0, 0, 0, 0, LEFTWARD, NONE};

spin turn right behavior state change determin 45 degree.
RunSectionParam{SPIN_TURN, SPIN_TURN_ANGLE, DEGREE45, 20, 0, 0, 0, 0, RIGHTWARD, NONE};

*/
