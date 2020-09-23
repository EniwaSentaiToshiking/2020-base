#pragma once

#include "GameState.h"
#include "RunningGameState.h"
#include "PlaygroundGameState.h"

extern int nowState;

class GameStateManager
{
public:
    GameStateManager();
    void manageGameState();
    void terminate();

private:
    RunningGameState runningGameState;
    PlaygroundGameState playgroundGameState;
};