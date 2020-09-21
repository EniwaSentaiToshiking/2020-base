#pragma once

#include "GameState.h"
#include "RunningGame.h"

extern int nowState;

class GameStateManager
{
public:
    GameStateManager();
    void manageGameState();
    void terminate();

private:
    RunningGame runningGame;
};