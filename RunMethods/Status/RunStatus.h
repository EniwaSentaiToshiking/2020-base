#include "RunPattern.h"
#include <vector>
// #include <algorithm>
/*参考： https://cpprefjp.github.io/reference/algorithm.html*/

using namespace std;

#ifndef RUNSTATUS_H
#define RUNSTATUS_H

//これなんだろう？
struct DeleteObject
{
  template <typename T>
  void operator()(const T *ptr) const
  {
    delete ptr;
  }
};

//走行状態
enum RunState
{
  SAMPLECOUSERUN,
  COURSE_RUN,
  PARKING,
  STOP,
};

class RunStatus
{
protected:
  vector<RunPattern *> patterns; /* 高速で動作する配列で管理したいため，vectorを使っている*/
  /* 参考: https://cpprefjp.github.io/reference/vector/vector.html */
  unsigned int currentPattern = 0;
  RunState nextState;

public:
  /**
     * init - 走行前の初期設定
     *
     * @param  {void}
     * @return {void}
     */
  virtual void init() = 0;

  /**
     * run - 走行する
     *
     * @param  {void}
     * @return {bool}
     */
  virtual bool run();
  virtual void setNextState() = 0;
  virtual bool changeNextPattern();
  virtual void changeNextStatus(RunManager *manager);
  virtual ~RunStatus();
};

#endif
