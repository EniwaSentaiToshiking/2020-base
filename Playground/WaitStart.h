#pragma once

#include "TouchSensor.h"
using namespace ev3api;

class WaitStart
{
public:
    WaitStart();
    bool isStarted();
    virtual ~WaitStart();
private:
    TouchSensor touchSensor;
};
