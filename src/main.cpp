#include <Controller.h>
#include "GameCore.hpp"

unsigned int WindowProperties::WIN_HEIGHT;
unsigned int WindowProperties::WIN_WIDTH;
GameState WindowProperties::gameState;

int main()
{
    GameCore &game = GameCore::Instance();
    //Game game;

    game.start();
}