#include "PointDetector.h"

PointDetector::PointDetector(Lot *threshold)
{
    local = new Localization();
    this->threshold = threshold;
    //loggerX = new Logger("point_x.txt");
    //loggerY = new Logger("point_y.txt");
}

PointDetector::~PointDetector()
{
    delete local;
}

void PointDetector::init(){}

bool PointDetector::detect()
{
    local->update();

    //loggerX -> logging(local->point_x);
    //loggerY -> logging(local->point_y);

    if (local->point_x > threshold->x0 && local->point_x < threshold->x1)
    {
        if (local->point_y > threshold->y0 && local->point_y < threshold->y1)
        {
            ev3_speaker_play_tone(480, 100);
            return true;
        }
    }
    return false;
}