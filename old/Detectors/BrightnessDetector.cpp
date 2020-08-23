#include "BrightnessDetector.h"

BrightnessDetector::BrightnessDetector(int threshold)
{
    courseMonitor = new CourseMonitor();
    this->threshold = threshold;
}

BrightnessDetector::~BrightnessDetector()
{
    delete courseMonitor;
}

void BrightnessDetector::init()
{
}

bool BrightnessDetector::detect()
{
    int currentBrightness = courseMonitor->getCurrentBrightness();
    if (currentBrightness == threshold)
        return true;
    if (threshold - 3 <= currentBrightness && currentBrightness <= threshold + 3)
        return true;
    return false;
}