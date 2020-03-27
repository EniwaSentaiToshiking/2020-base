#include "Detector.h"
#include "Localization.h"
#include "Lot.h"
#include "ev3api.h"
#include "Logger.h"

#ifndef POINTDETECTER_H
#define POINTDETECTER_H

class PointDetector : public Detector
{
  private:
    Localization *local;
    Lot *threshold;

    //Logger *loggerX;
    //Logger *loggerY;

  public:
    PointDetector(Lot *threshold);

    /**
     * detect - 座標の条件検知
     *
     * @param  {void}      
     * @return {bool}         true 検出した, false 検出しなかった 
     */
    bool detect();
    void init();
    virtual ~PointDetector();
};

#endif