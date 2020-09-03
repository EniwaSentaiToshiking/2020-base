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
    /* turn: 目標値と取得したカラーセンサの輝度値の誤差をPID制御で修正した値*/
    int turn = pidController->getTurn(this->pid, this->courseMonitor->getCurrentBrightness(), this->targetBrightness, 100);

    /*turnに-1を掛けると車輪の操作量が真逆になるため目標のエッジが逆になる*/
    if (this->edge == RIGHT)
        turn = turn * -1;

    return turn;
}

/* ブロックビンゴの細かい軌道修正には使えるかも*/
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