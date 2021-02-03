/*
 * Created on Wed Feb 03 2021
 *
 * Copyright (c) 2021 Kazuki Hamaguchi
 */
#include "SetupGame.h"

SetupGame::SetupGame() : touchSensor(PORT_4)
{
}

void SetupGame::init()
{
    debugUtil.init("SetupGame");
}

bool SetupGame::isStarted()
{
    if (touchSensor.isPressed())
    {
        return true;
    }
    return false;
}

void SetupGame::terminate()
{
}