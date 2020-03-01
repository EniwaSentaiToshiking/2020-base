#include "Detector.h"
#include "CourseMonitor.h"
#include "ev3api.h"

#ifndef COLORDETECTER_H
#define COLORDETECTER_H


#define color_buffer_max 50

class ColorDetector : public Detector
{
  private:
    CourseMonitor *courseMonitor;
    int threshold;
    int color_count = 0;
    int color_buffer_num = 0;
    int color_buffer[color_buffer_max];

  public:
    ColorDetector(int threshold);

    void init();
    /**
     * detect - 色の条件検知
     *
     * @param  {void}
     * @return {bool}         true 検出した, false 検出しなかった
     */
    bool detect();
    virtual ~ColorDetector();
};

#endif
