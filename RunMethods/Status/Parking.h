#ifndef PARKING_H
#define PARKING_H

#include "RunStatus.h"
#include "Course.h"

class Parking : public RunStatus
{
private:
  Course course;

  void createCourseL();
  void createCourseR();

public:
  Parking(Course course);
  void init();
  void setNextState();
  virtual ~Parking();
};
#endif