#include "Detector.h"
#include "Localization.h"
#include "Lot.h"
#include "ev3api.h"
#include <cstdlib>

#ifndef DISTANCEDETECTER_H
#define DISTANCEDETECTER_H

class DistanceDetector : public Detector
{
private:
  Localization *local;
  int threshold;
  int prev_distance;

public:
  DistanceDetector(int threshold);

  void init();
  /**
     * detect - 座標の条件検知
     *
     * @param  {void}      
     * @return {bool}         true 検出した, false 検出しなかった 
     */
  bool detect();
  virtual ~DistanceDetector();
};

#endif