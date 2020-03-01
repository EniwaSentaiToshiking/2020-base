#include "ClockDetector.h"

ClockDetector::ClockDetector(int threshold)
{
    clock = new Clock();
    this->threshold = threshold;
}

ClockDetector::~ClockDetector()
{
    delete clock;
}

void ClockDetector::init(){
    prev_clock = clock->now();
}

bool ClockDetector::detect()
{
    if(clock->now() - prev_clock >= threshold) return true;
    return false;
}