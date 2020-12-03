#include "LineTrace.h"

LineTrace::LineTrace(PID *pid, int targetBrightness, Edge edge)
{
    courseMonitor = new CourseMonitor();
    this->pid = pid;
    this->targetBrightness = targetBrightness;
    this->edge = edge;
}

LineTrace::~LineTrace()
{
    delete courseMonitor;
}

int LineTrace::getTurnValue()
{
    int turn = pidController->getTurn(this->pid, this->courseMonitor->getCurrentBrightness(), this->targetBrightness, 100);

    if (this->edge == RIGHT)
        turn = turn * -1;

    return turn;
}

int LineTrace::getTurnValueByOnOFF()
{

    int turn = 0;

    if (this->courseMonitor->getCurrentBrightness() >= this->targetBrightness)
    {
        turn = 30;
    }
    else
    {
        turn = -30;
    }

    return turn;
}