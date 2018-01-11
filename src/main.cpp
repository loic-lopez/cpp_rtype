#include <Controller.h>
#include <GameEngine.h>
#include "Game.h"

unsigned int WindowProperties::WIN_HEIGHT;
unsigned int WindowProperties::WIN_WIDTH;

int main()
{
    GameEngine &gameEngine = GameEngine::Instance();
    Game &game = Game::Instance();
    //Game game;

    gameEngine.start();
    game.start();
}