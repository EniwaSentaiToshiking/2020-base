#include "CourseRun.h"
#include "Parking.h"
#include "Stop.h"
#include "SampleCourseRun.h"

#ifndef RUNMANAGER_H
#define RUNMANAGER_H


enum AllGameState
{
  SETUP_GAME_STATE,
  RUNNING_GAME_STATE,
  BLOCK_BINGO_GAME_STATE,
  GARAGE_GAME_STATE,
};

class RunManager
{

private:
    Course course;
    AllGameState state = SETUP_GAME_STATE;
    RunStatus *status;

public:
    RunManager(Course course);

    /**
     * init - 走行前の初期設定
     *
     * @param  {void}
     * @return {void}
     */
    void init();

    /**
     * run - 走行する
     *
     * @param  {void}
     * @return {void}
     */
    void run();
    void change_state(RunState state);
    void changeNextStatus(RunManager *manager);
    virtual ~RunManager();
};

#endif
