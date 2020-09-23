#pragma once

#include "GameState.h"
#include "RunningGameState.h"
#include "PlaygroundGameState.h"
#include "DebugUtil.h"

extern int nowState;

class GameStateManager
{
public:
    GameStateManager();
    void init();
    void manageGameState();
    void terminate();

private:
    RunningGameState runningGameState;
    PlaygroundGameState playgroundGameState;
    DebugUtil debugUtil;
};