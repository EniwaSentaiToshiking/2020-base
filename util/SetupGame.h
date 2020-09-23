#pragma once

#include "TouchSensor.h"
#include "DebugUtil.h"
using namespace ev3api;

class SetupGame
{
public:
    SetupGame();
    void init();
    bool isStarted();
    void terminate();

private:
    TouchSensor touchSensor;
    DebugUtil debugUtil;
};
