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
        runningGame.run(); // <2>
        break;
    case BLOCK_BINGO_GAME_STATE:
        break;
    case GARAGE_GAME_STATE:
        break;
    default:
        break;
    }
}

void GameStateManager::terminate()
{
    runningGame.terminate();
}