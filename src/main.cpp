#include <Controller.h>
#include "MenuCore.hpp"

unsigned int WindowProperties::WIN_HEIGHT;
unsigned int WindowProperties::WIN_WIDTH;
GameState WindowProperties::gameState;
sf::RenderWindow *WindowProperties::App;

int main()
{
    MenuCore &game = MenuCore::Instance();
    //Game game;

    game.start();
    delete WindowProperties::App;
}