/*
 * Created on Wed Feb 03 2021
 *
 * Copyright (c) 2021 Kazuki Hamaguchi
 */
#pragma once

#include "Ev3State.h"
#include "PreGameState.h"
#include "InGameState.h"
#include "EndGameState.h"
#include "DebugUtil.h"

extern int nowEv3State;

class GameStateManager
{

public:
    Ev3StateManager();
    void init();
    void manageGameState();
    void terminate();
};