#include "app.h" // <1>
// #include "GameState.h"
#include "SetupGame.h"
// #include "RunningGame.h" // <2>
#include "Clock.h" // <3>
#include "GameStateManager.h"
// #include "Straight.h"
// #include "TouchSensor.h"

using namespace ev3api;

SetupGame setupGame;
GameStateManager gameStateManager;
Clock clock; // <5>
int nowState = SETUP_GAME_STATE;

void game_state_manager_task(intptr_t exinf)
{ // <1>
  gameStateManager.manageGameState();
  ext_tsk();
}

void setup_game_task(intptr_t exinf)
{
  sta_cyc(SETUP_GAME_CYC);
  if (setupGame.isStarted())
  {
    sta_cyc(GAME_STATE_MANAGER_CYC);
  }

  if (ev3_button_is_pressed(LEFT_BUTTON))
  {
    stp_cyc(SETUP_GAME_CYC);
    stp_cyc(GAME_STATE_MANAGER_CYC);
    gameStateManager.terminate();
  }
  ext_tsk();
}

void main_task(intptr_t unused)
{                                  // <1>
  const uint32_t duration = 100;   // <2>
  sta_cyc(GAME_STATE_MANAGER_CYC); // <4>

  while (!ev3_button_is_pressed(LEFT_BUTTON))
  {                        // <1>
    clock.sleep(duration); // <2>
  }

  stp_cyc(GAME_STATE_MANAGER_CYC); // <3>
  gameStateManager.terminate();
  ext_tsk(); // <5>
}
