#include "app.h" 
#include "SetupGame.h"
#include "GameStateManager.h"

using namespace ev3api;

SetupGame setupGame;
GameStateManager gameStateManager;

int nowState = PLAYGROUND_GAME_STATE;
void setup_game_task(intptr_t exinf)
{
  if (setupGame.isStarted())
  {
    gameStateManager.init();
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

void game_state_manager_task(intptr_t exinf)
{
  gameStateManager.manageGameState();
  ext_tsk();
}