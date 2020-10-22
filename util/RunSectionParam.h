#pragma once


typedef struct
{
    float distance;
    int pwm;
    float kP;
    float kI;
    float kD;
    int targetVal;
} RunSectionParam;