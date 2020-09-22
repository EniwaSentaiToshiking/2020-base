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
        runningGame.run();
        break;
    case BLOCK_BINGO_GAME_STATE:
        break;
    case GARAGE_GAME_STATE:
        break;
    case PLAYGROUND_GAME_STATE:
        playgroundGame.run();
        break;
    default:
        break;
    }
}

void GameStateManager::terminate()
{
    runningGame.terminate();
    playgroundGame.terminate();
}