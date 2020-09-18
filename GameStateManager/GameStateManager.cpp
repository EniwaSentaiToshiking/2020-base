#include "GameStateManager.h"

GameStateManager::GameStateManager()
{
    init_f("GameStateManager");
}

void GameStateManager::manageGameState() 
{
    switch (nowState)
    {
    case SETUP_GAME_STATE:
        if (setupGame.isStarted()) {
        nowState = RUNNING_GAME_STATE;
        }
        break;
    case RUNNING_GAME_STATE:
        runningGame.run(); // <2>
        break;
    default:
        break;
    }
}

void GameStateManager::terminate()
{
    runningGame.terminate();
}