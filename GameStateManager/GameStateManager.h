#include "GameState.h"
#include "SetupGame.h"
#include "RunningGame.h"

class GameStateManager
{
public:
    GameStateManager();
    void manageGameState();
    void terminate();

private:
    int nowState = SETUP_GAME_STATE;
    SetupGame setupGame;
    RunningGame runningGame;
};