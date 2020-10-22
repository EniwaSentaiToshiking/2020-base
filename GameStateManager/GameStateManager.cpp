#include "GameStateManager.h"

GameStateManager::GameStateManager()
{
}

void GameStateManager::init()
{
    d.init("GameStateManager");
    runningGameState.init();
    blockBingoGameState.init();
    playgroundGameState.init();
}

void GameStateManager::manageGameState() 
{
    switch (nowGameState)
    {
    case RUNNING_GAME_STATE:
        runningGameState.run();
        if (runningGameState.isFinished())
        {
            runningGameState.terminate();
            nowGameState = BLOCK_BINGO_GAME_STATE;
        }
        break;
    case BLOCK_BINGO_GAME_STATE:
        d.led_debug(LED_ORANGE);
        blockBingoGameState.run();
        if (blockBingoGameState.isChanged())
        {
            blockBingoGameState.terminate();
            nowGameState = GARAGE_GAME_STATE;
        }
        break;
    case GARAGE_GAME_STATE:
        d.led_debug(LED_RED);
        break;
    case PLAYGROUND_GAME_STATE:
        if (playgroundGameState.isFinished())
        {
            playgroundGameState.terminate();
            stp_cyc(SETUP_GAME_CYC);
            stp_cyc(GAME_STATE_MANAGER_CYC);
        } else {
            playgroundGameState.run();
        }
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