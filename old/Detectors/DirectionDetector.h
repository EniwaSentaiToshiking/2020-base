#include "Detector.h"
#include "Localization.h"
#include "RunStyle.h"
#include "Lot.h"
#include "ev3api.h"

#ifndef DIRECTIONDETECTER_H
#define DIRECTIONDETECTER_H

class DirectionDetector : public Detector
{
private:
  Localization *local;
  int threshold;
  int prev_direction;
  TurningDirection turningDirection;

public:
  DirectionDetector(int threshold, TurningDirection turningDirection);

  void init();
  /**
     * detect - 座標の条件検知
     *
     * @param  {void}      
     * @return {bool}         true 検出した, false 検出しなかった 
     */
  bool detect();
  virtual ~DirectionDetector();
};

#endif