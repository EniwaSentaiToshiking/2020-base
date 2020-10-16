#pragma once

#include "GameState.h"
#include "RunningGameState.h"
#include "BlockBingoGameState.h"
#include "PlaygroundGameState.h"
#include "DebugUtil.h"

extern int nowGameState;

class GameStateManager
{
    RunningGameState runningGameState;
    PlaygroundGameState playgroundGameState;
    BlockBingoGameState blockBingoGameState;
    DebugUtil debugUtil;

public:
    GameStateManager();
    void init();
    void manageGameState();
    void terminate();
};