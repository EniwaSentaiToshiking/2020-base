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
    // debugUtil.lcd_msg_debug("Ready", 1);
    if (touchSensor.isPressed())
    {
            return true;
    }
    return false;
}

void SetupGame::terminate()
{
}