#include "Detecter.h"
#include "GrayLineDetecter.h"
#include "PointDetecter.h"
#include "DistanceDetecter.h"
#include "DirectionDetecter.h"
#include "AdaptiveDirectionDetecter.h"
#include "ColorDetecter.h"
#include "BlackLineDetecter.h"
#include "BrightnessDetecter.h"
#include "ClockDetecter.h"

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