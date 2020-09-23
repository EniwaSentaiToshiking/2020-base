#include "SetupGame.h"

SetupGame::SetupGame() : touchSensor(PORT_4)
{
}

void SetupGame::init()
{
    init_f("SetupGame");
}

bool SetupGame::isStarted()
{
    if (touchSensor.isPressed()) {
            return true;
    }
    return false;
}

void SetupGame::terminate()
{
}