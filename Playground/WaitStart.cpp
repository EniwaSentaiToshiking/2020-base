#include "WaitStart.h"

WaitStart::WaitStart() : touchSensor(PORT_4)
{
}

WaitStart::~WaitStart()
{
}

bool WaitStart::isStarted()
{
    if (touchSensor.isPressed()) {
            return true;
    }
    return false;
}