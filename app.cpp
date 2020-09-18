#include "app.h" // <1>
#include "GameState.h"
#include "SetupGame.h"
#include "RunningGame.h" // <2>
#include "Clock.h"  // <3>
#include "Straight.h"
#include "TouchSensor.h"

using namespace ev3api;

SetupGame setupGame;
RunningGame runningGame; // <4>
Clock clock;    // <5>

int nowState = SETUP_GAME_STATE;
void game_states_manager_task(intptr_t exinf) 
{ // <1>
  switch (nowState)
  {
  case SETUP_GAME_STATE:
    if (setupGame.isStarted()) {
      nowState = RUNNING_GAME_STATE;
    }
    break;
  case RUNNING_GAME_STATE:
    runningGame.run(); // <2>
    break;
  default:
    break;
  }
  ext_tsk();
}


void main_task(intptr_t unused) { // <1>
  const uint32_t duration = 100; // <2>
  

  runningGame.init(); // <3>
  sta_cyc(GAME_STATES_MANAGER_CYC); // <4>

  while (!ev3_button_is_pressed(LEFT_BUTTON)) { // <1>
      clock.sleep(duration);   // <2>
  }

  stp_cyc(GAME_STATES_MANAGER_CYC); // <3>
  runningGame.terminate();
  ext_tsk(); // <5>
}

