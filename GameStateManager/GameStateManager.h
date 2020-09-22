#pragma once

#include "GameState.h"
#include "RunningGame.h"
#include "PlaygroundGame.h"

extern int nowState;

class GameStateManager
{
public:
    GameStateManager();
    void manageGameState();
    void terminate();

private:
    RunningGame runningGame;
    PlaygroundGame playgroundGame;
};