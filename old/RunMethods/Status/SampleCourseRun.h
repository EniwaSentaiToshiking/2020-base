#ifndef SAMPLECOURSERUN_H
#define SAMPLECOURSERUN_H

#include "RunStatus.h"
#include "Course.h"

class SampleCourseRun : public RunStatus
{
private:
    Course course;
    vector<Lot *> lots;

    void createCourseL();
    void createCourseR();

public:
    SampleCourseRun(Course course);
    void init();
    void setNextState();
    virtual ~SampleCourseRun();
};
#endif