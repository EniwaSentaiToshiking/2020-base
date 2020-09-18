#pragma once

#include "TouchSensor.h"
#include "util.h"
using namespace ev3api;

class SetupGame
{
public:
    SetupGame();
    void init();
    bool isStarted();
private:
    TouchSensor touchSensor;
};
