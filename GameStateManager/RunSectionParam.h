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

// line trace behavior pwm 20, section change determin distance 400mm.
RunSectionParam{LINE_TRAICE, DISTANCE, 400, 20, 2.0, 0.03, 0.2, 18, NONE_L_R, NONE_F_B};

// line trace behavior pwm 20, section change determin color yellow.
RunSectionParam{LINE_TRAICE, COLOR, COLOR_YELLOW, 20, 2.0, 0.03, 0.2, 18, NONE_L_R, NONE_F_B};

// spin turn left behavior pwm 20, section change determin 180 degree.
RunSectionParam{SPIN_TURN, SPIN_TURN_ANGLE, DEGREE180, 20, 0, 0, 0, 0, LEFTWARD, NONE_F_B};

// spin turn right behavior pwm 20, section change determin 45 degree.
RunSectionParam{SPIN_TURN, SPIN_TURN_ANGLE, DEGREE45, 20, 0, 0, 0, 0, RIGHTWARD, NONE_F_B};

// straight forward behavior pwm 50 section change determin distance 250mm
RunSectionParam{STRAIGHT, DISTANCE, 250, 50, 0, 0, 0, 0, NONE_L_R, FORWARD};

// straight backward behavior pwm 60 section change determin distance 300mm
RunSectionParam{STRAIGHT, DISTANCE, 300, 60, 0, 0, 0, 0, NONE_L_R, BACKWARD};

// stop behavior section change determin stop determination
// if use distance, you set param distance 0mm
RunSectionParam{STOP, STOP_DETERMINATION, 0, 0, 0, 0, 0, 0, NONE_L_R, NONE_F_B};

*/

