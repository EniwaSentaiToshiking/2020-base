#pragma once

#include "GameState.h"
#include "SetupGame.h"
#include "RunningGame.h"

extern int nowState;

class GameStateManager
{
public:
    GameStateManager();
    void manageGameState();
    void terminate();

private:
    SetupGame setupGame;
    RunningGame runningGame;
};