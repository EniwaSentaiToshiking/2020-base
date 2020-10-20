#include "app.h" 
#include "SetupGame.h"
#include "Edge.h"
#include "GameStateManager.h"
// #include "Ev3StateManager.h"
// #include "Ev3State.h"
#include "DebugUtil.h"

using namespace ev3api;

SetupGame setupGame;
GameStateManager gameStateManager;
DebugUtil d;

int nowGameState = PLAYGROUND_GAME_STATE;
// int nowEv3State = PRE_GAME_STATE;
int edge = RIGHT_EDGE;

void setup_game_task(intptr_t exinf)
{
  d.init("Ready");
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