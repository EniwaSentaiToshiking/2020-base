#include "DistanceDetector.h"

DistanceDetector::DistanceDetector(int threshold)
{
    local = new Localization();
    this->threshold = threshold;
}

DistanceDetector::~DistanceDetector()
{
    delete local;
}

void DistanceDetector::init()
{
    local->update();
    prev_distance = local->getCurrentDistance();
}

bool DistanceDetector::detect()
{
    local->update();
    if (abs(local->getCurrentDistance() - prev_distance) >= threshold)
        return true;
    return false;
}