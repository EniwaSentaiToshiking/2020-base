#include "RunPattern.h"

RunPattern::RunPattern(Pattern pattern, int speed, DetectType type, float threshold, float p, float i, float d, int brightness, Edge edge)
{
    this->pattern = pattern;
    this->speed = speed;
    this->detectType = type;
    this->threshold = threshold;
    this->brightness = brightness;
    this->edge = edge;
    pid = new PID(p, i, d);
    init();
}

RunPattern::RunPattern(Pattern pattern, int speed, Lot *threshold, float p, float i, float d, int brightness)
{
    this->pattern = pattern;
    this->speed = speed;
    this->detectType = POINT;
    this->nextLot = threshold;
    this->brightness = brightness;
    pid = new PID(p, i, d);
    init();
}

RunPattern::RunPattern(Pattern pattern, int speed, DetectType type, float threshold, TurningDirection direction)
{
    this->pattern = pattern;

    if (this->pattern == SPIN)
    {
        this->speed = abs(speed);
    }
    else
    {
        this->speed = speed;
    }
    this->detectType = type;
    this->threshold = threshold;
    this->direction = direction;
    init();
}

RunPattern::RunPattern(Pattern pattern, int arm, int threshold)
{
    this->pattern = pattern;
    this->speed = 0;
    this->arm = arm;
    this->detectType = CLOCK;
    this->threshold = threshold;
    init();
}

void RunPattern::init()
{
    runCommander = new RunCommander();
    armCommander = new ArmCommander();
    tailCommander = new TailCommander();
    createRunStyle();
    createDetector();
}

RunPattern::~RunPattern()
{
    delete runCommander;
    delete armCommander;
    delete tailCommander;
    delete runStyle;
    delete detector;
    delete nextLot;
}

void RunPattern::createRunStyle()
{
    switch (this->pattern)
    {
    case LINE_TRACE:
        runStyle = new LineTrace(this->pid, this->brightness, this->edge);
        break;
    case STRAIGHT:
        runStyle = new Straight(this->speed);
        break;
    case TURNING:
        runStyle = new Turning(this->direction, this->speed);
        break;
    case SPIN:
        runStyle = new Spin(this->direction, this->speed);
        break;
    case CLOTHOID:
        runStyle = new Clothoid(this->direction, this->speed);
        break;
    case BRAKE:
        runStyle = new Straight(this->speed);
        break;
    case ARM:
        runStyle = new Straight(this->speed);
        break;
    }
}

void RunPattern::createDetector()
{
    switch (this->detectType)
    {
    case POINT:
        this->detector = new PointDetector(this->nextLot);
        break;
    case GRAYLINE:
        this->detector = new GrayLineDetector(this->threshold);
        break;
    case DISTANCE:
        this->detector = new DistanceDetector(this->threshold);
        break;
    case DIRECTION:
        this->detector = new DirectionDetector(this->threshold, this->direction);
        break;
    case ADAPTIVEDIRECTION:
        this->detector = new AdaptiveDirectionDetector(this->threshold);
        break;
    case COLOR:
        this->detector = new ColorDetector(this->threshold);
        break;
    case BLACKLINE:
        this->detector = new BlackLineDetector(this->threshold);
        break;
    case BRIGHTNESS:
        this->detector = new BrightnessDetector(this->threshold);
        break;
    case CLOCK:
        this->detector = new ClockDetector(this->threshold);
        break;
    }
}

bool RunPattern::run()
{
    if (!isInitializeDetector)
    {
        runStyle->init();
        detector->init();
        isInitializeDetector = true;
    }

    int turn = runStyle->getTurnValue();
    tailCommander->rotateDefault();

    if (this->pattern == BRAKE)
    {
        runCommander->steerStop();
        armCommander->rotateDefault();
    }
    else if (this->pattern == ARM)
    {
        if (this->arm == 0)
        {
            armCommander->rotateDefault();
        }
        else
        {
            armCommander->rotate(this->arm);
        }
    }
    else
    {
        runCommander->steer(this->speed, turn);
        armCommander->rotateDefault();
    }

    if (detector->detect())
        return true;

    return false;
}