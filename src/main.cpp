#include <Core/GameCore.h>
#include "PowerUp.h"

unsigned int WindowProperties::WIN_HEIGHT;
unsigned int WindowProperties::WIN_WIDTH;
unsigned int WindowProperties::MAX_PLAYER_HP;
GameState WindowProperties::gameState;
sf::RenderWindow *WindowProperties::App;
Orientation WindowProperties::orientation;

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    GameCore &game = GameCore::Instance();

    game.start();
    delete WindowProperties::App;
}