#include "Detector.h"
#include "CourseMonitor.h"
#include "ev3api.h"

#ifndef BRACKLINEDETECTER_H
#define BRACKLINEDETECTER_H

#define WHITE 90 //白値判断基準閾値
#define BLACK 25 //黒値判断基準閾値

typedef enum
{
  DISCERN_WHITE1, /* WHITE1を見分ける */
  DISCERN_BLACK,
  DISCERN_WHITE2
} discernLine_enum;

class BlackLineDetector : public Detector
{
private:
  CourseMonitor *courseMonitor; /* courseやろがい！*/
  int threshold;
  discernLine_enum discernLine_state = DISCERN_WHITE1;

public:
  BlackLineDetector(int threshold);

  void init();
  /**
     * detect - 黒ラインの条件検知
     *
     * @param  {void}
     * @return {bool}         true 検出した, false 検出しなかった
     */
  bool detect();
  virtual ~BlackLineDetector();
};

#endif
