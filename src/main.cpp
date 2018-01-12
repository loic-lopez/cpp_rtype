#include <Controller.h>
#include "Game.h"

unsigned int WindowProperties::WIN_HEIGHT;
unsigned int WindowProperties::WIN_WIDTH;

int main()
{
    Game &game = Game::Instance();
    //Game game;

    game.start();
}