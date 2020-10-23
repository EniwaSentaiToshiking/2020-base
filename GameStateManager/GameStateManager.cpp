#include "GameStateManager.h"

GameStateManager::GameStateManager()
{
}

void GameStateManager::init()
{
    d.init("GameStateManager");
    runningGameState.init();
    blockBingoGameState.init();
    garageGameState.init();

    playgroundGameState.init();
}

// extern char syslogBuf[50];
void GameStateManager::manageGameState() 
{
    switch (nowGameState)
    {
    case RUNNING_GAME_STATE:
        runningGameState.run();
        if (runningGameState.isFinished())
        {
            nowGameState = BLOCK_BINGO_GAME_STATE;
            // snprintf(syslogBuf, sizeof(syslogBuf), "End RunningGameState");
            // syslog(LOG_NOTICE, syslogBuf);
        }
        break;

    case BLOCK_BINGO_GAME_STATE:
        d.led_debug(LED_ORANGE);
        blockBingoGameState.run();
        if (blockBingoGameState.isFinished())
        {
            nowGameState = GARAGE_GAME_STATE;
            // snprintf(syslogBuf, sizeof(syslogBuf), "End BlockBingoGameState");
            // syslog(LOG_NOTICE, syslogBuf);
        }
        break;

    case GARAGE_GAME_STATE:
        d.led_debug(LED_RED);
        garageGameState.run();
        if (garageGameState.isFinished())
        {
            // snprintf(syslogBuf, sizeof(syslogBuf), "End GarageGameState");
            // syslog(LOG_NOTICE, syslogBuf);
            this->terminate();
            stp_cyc(SETUP_GAME_CYC);
            stp_cyc(GAME_STATE_MANAGER_CYC);
        }
        break;

    case PLAYGROUND_GAME_STATE:
        playgroundGameState.run();
        if (playgroundGameState.isFinished())
        {
            playgroundGameState.terminate();
            stp_cyc(SETUP_GAME_CYC);
            stp_cyc(GAME_STATE_MANAGER_CYC);
        }
        break;

    default:
        break;
    }
}

void GameStateManager::terminate()
{
    runningGameState.terminate();
    blockBingoGameState.terminate();
    garageGameState.terminate();
    
    playgroundGameState.terminate();
}