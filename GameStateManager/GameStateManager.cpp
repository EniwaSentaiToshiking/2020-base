#include "GameStateManager.h"

GameStateManager::GameStateManager()
{
    init_f("GameStateManager");
}

void GameStateManager::manageGameState() 
{
    switch (nowState)
    {
    case RUNNING_GAME_STATE:
        runningGameState.run();
        break;
    case BLOCK_BINGO_GAME_STATE:
        break;
    case GARAGE_GAME_STATE:
        break;
    case PLAYGROUND_GAME_STATE:
        playgroundGameState.run();
        break;
    default:
        break;
    }
}

void GameStateManager::terminate()
{
    runningGameState.terminate();
    playgroundGameState.terminate();
}