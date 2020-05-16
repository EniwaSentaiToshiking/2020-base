#include "SampleCourseRun.h"

SampleCourseRun::SampleCourseRun(Course course)
{
    this->course = course;

    if (this->course == L)
    {
        createCourseL();
    }
    else if (this->course == R)
    {
        createCourseR();
    }

    setNextState();
}

SampleCourseRun::~SampleCourseRun()
{
    for_each(lots.begin(), lots.end(), DeleteObject());
    lots.clear();
    ev3_speaker_play_tone(480, 100);
}

void SampleCourseRun::init()
{
}

void SampleCourseRun::setNextState()
{
    if (this->course == L)
    {
        nextState = STOP;
    }
    else if (this->course == R)
    {
        nextState = STOP;
    }
}

// coruseの距離は1000 1050くらいで調整
void SampleCourseRun::createCourseL()
{
    patterns.push_back(new RunPattern(LINE_TRACE, 50, BLACKLINE, 40, LEFT));
}

void SampleCourseRun::createCourseR()
{
    patterns.push_back(new RunPattern(LINE_TRACE, 50, BLACKLINE, 40, LEFT));
}