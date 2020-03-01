#include "Detector.h"
#include "CourseMonitor.h"
#include "ev3api.h"

#ifndef BRIGHTNESSDETECTER_H
#define BRIGHTNESSDETECTER_H

class BrightnessDetector : public Detector
{
  private:
    CourseMonitor *courseMonitor;
    int threshold;

  public:
    BrightnessDetector(int threshold);

    void init();
    /**
     * detect - 色の条件検知
     *
     * @param  {void}      
     * @return {bool}         true 検出した, false 検出しなかった 
     */
    bool detect();
    virtual ~BrightnessDetector();
};

#endif