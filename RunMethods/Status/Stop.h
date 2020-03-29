#ifndef STOP_H
#define STOP_H

#include "RunStatus.h"

class Stop : public RunStatus
{
private:
public:
  Stop();
  void init(){};
  void setNextState(){};
  virtual ~Stop(){};
};
#endif