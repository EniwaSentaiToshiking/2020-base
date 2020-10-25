#include "RunStatus.h"
#include "RunManager.h"

RunStatus::~RunStatus()
{
    for_each(patterns.begin(), patterns.end(), DeleteObject());
    patterns.clear();
}

bool RunStatus::run()
{
    bool isFinishPattern = patterns[currentPattern]->run();
    if (isFinishPattern)
    {
        bool isFinishStatus = changeNextPattern();
        if (isFinishStatus)
            return true;
    }
    return false;
}

bool RunStatus::changeNextPattern()
{
    // RunPatternが全て正しく動作しきったら 次のstateに移す
    if (patterns.empty())
    {
        currentPattern++;
        ev3_speaker_play_tone(480, 100);
    }
    else
    {
        return true;
    }
    return false;
}

void RunStatus::changeNextStatus(RunManager *manager)
{
    manager->changeStatus(this->nextState);
}