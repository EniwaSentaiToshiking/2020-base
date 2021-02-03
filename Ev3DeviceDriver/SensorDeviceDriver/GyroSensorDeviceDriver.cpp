/*
 * Created on Wed Feb 03 2021
 *
 * Copyright (c) 2021 Kazuki Hamaguchi
 */
#include "GyroSensorDeviceDriver.h"

GyroSensorDeviceDriver::GyroSensorDeviceDriver():gyroSensor(PORT_1)
{
}

void GyroSensorDeviceDriver::init()
{

}

void GyroSensorDeviceDriver::resetAngle()
{
    gyroSensor.reset();
}

int GyroSensorDeviceDriver::getAngle()
{
    return gyroSensor.getAngle();
}

void GyroSensorDeviceDriver::terminate()
{
    
}

GyroSensorDeviceDriver::~GyroSensorDeviceDriver()
{

}