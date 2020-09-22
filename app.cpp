#include "app.h" 
#include "SetupGame.h"
#include "Clock.h" 
#include "GameStateManager.h"

using namespace ev3api;

SetupGame setupGame;
GameStateManager gameStateManager;
Clock clock;
int nowState = RUNNING_GAME_STATE;

void game_state_manager_task(intptr_t exinf)
{
  gameStateManager.manageGameState();
  ext_tsk();
}

void setup_game_task(intptr_t exinf)
{
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