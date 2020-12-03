#include "Detector.h"
#include "GrayLineDetector.h"
#include "PointDetector.h"
#include "DistanceDetector.h"
#include "DirectionDetector.h"
#include "AdaptiveDirectionDetector.h"
#include "ColorDetector.h"
#include "BlackLineDetector.h"
#include "BrightnessDetector.h"
#include "ClockDetector.h"

#ifndef DETECTTYPE_H
#define DETECTTYPE_H

enum DetectType
{
    POINT,
    GRAYLINE, /*2018は灰色の線だったけど2019年は青色の線になりました*/
    DISTANCE,
    DIRECTION,
    ADAPTIVEDIRECTION,
    COLOR,
    BLACKLINE,
    BRIGHTNESS,
    CLOCK,
};

#endif