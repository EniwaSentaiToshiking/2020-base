/*
 * Created on Wed Feb 03 2021
 *
 * Copyright (c) 2021 Kazuki Hamaguchi
 */

#include "ArmDeviceDriver.h"


ArmDeviceDriver::ArmDeviceDriver() : armMotor(PORT_A)
{

    // file = fopen("logging_spin_turn_distance.csv", "w");
    // fprintf(file, "Distance,difL,curL,preL,difR,curR,preR\n");
    // fprintf(file, "dis,\n");
}

void ArmDeviceDriver::init()
{
    this->rotateDefault();
    this->resetArmAngle();
}

void ArmDeviceDriver::resetArmAngle()
{
    armMotor.reset();
}

void ArmDeviceDriver::setPWM(int armPWM)
{
    armMotor.setPWM(armPWM);
}


void ArmDeviceDriver::rotate(int32_t angle) 
{
    float armPWM = (float)(angle - armMotor.getCount()) * KP; /* 比例制御 */
    /* PWM出力飽和処理 */
    if (armPWM > PWM_ABS_MAX)
    {
        armPWM = PWM_ABS_MAX;
    }
    else if (armPWM < -PWM_ABS_MAX)
    {
        armPWM = -PWM_ABS_MAX;
    }

    armMotor.setPWM(armPWM);
}

void ArmDeviceDriver::rotateDefault()
{
    this->rotate(DEFAULT_ANGLE);
}

void ArmDeviceDriver::terminate()
{
    this->rotateDefault();
    this->resetArmAngle();
}

ArmDeviceDriver::~ArmDeviceDriver()
{
    this->terminate();
    // fclose(file);
}