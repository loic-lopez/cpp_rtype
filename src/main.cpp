#include <Controller.h>
#include "Game.h"

unsigned int WindowProperties::WIN_HEIGHT;
unsigned int WindowProperties::WIN_WIDTH;
thor::ColorGradient WindowProperties::particleColorGradientMenu;

int main()
{
    std::cout << "test" << std::endl;
    std::cout << "test" << std::endl;
    Game &game = Game::Instance();
    //Game game;

    game.start();
}