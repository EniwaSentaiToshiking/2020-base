#include <typeinfo>
#include "LineTrace.h"
#include "Straight.h"
#include "Turning.h"
#include "Spin.h"
#include "Clothoid.h"
#include "DetectType.h"
#include "RunCommander.h"
#include "ArmCommander.h"
#include "TailCommander.h"

#define _USE_MATH_DEFINES
#include <math.h>

#ifndef RUNPATTERN_H
#define RUNPATTERN_H

enum Pattern
{
    LINE_TRACE,
    STRAIGHT,
    TURNING,
    SPIN,
    BRAKE,
    CLOTHOID, // クロソイド曲線 (緩和曲線だったら車輪の制御に使われている？？)
    ARM, // アーム
};

class RunPattern
{

private:
    RunCommander *runCommander;
    ArmCommander *armCommander;
    TailCommander *tailCommander;
    RunStyle *runStyle;
    Detector *detector;
    Pattern pattern;
    DetectType detectType;
    PID *pid;
    int speed = 0;
    int arm = 0;
    float threshold = 0;
    Lot *nextLot;
    int brightness = 20;
    Edge edge = LEFT;
    TurningDirection direction = DIRECTION_LEFT;

    bool isInitializeDetector = false;

    void createRunStyle();
    void createDetector();

public:
    //ライントレース or 直進走行
    RunPattern(Pattern pattern, int speed, DetectType type, float threshold, float p = 0.0, float i = 0.0, float d = 0.0, int brightness = 60, Edge edge = LEFT);
    //コース走行
    RunPattern(Pattern pattern, int speed, Lot *threshold, float p = 0.0, float i = 0.0, float d = 0.0, int brightness = 60);
    //旋回走行
    RunPattern(Pattern pattern, int speed, DetectType type, float threshold, TurningDirection direction);
    //アームのみ移動
    RunPattern(Pattern Pattern, int arm, int threshold); //threshold???

    void init();

    /**
     * run - 走行する
     *
     * @param  {void}
     * @return {bool}
     */
    bool run();
    virtual ~RunPattern();
};

#endif