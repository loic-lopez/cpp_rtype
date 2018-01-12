#include <Core/GameCore.h>

unsigned int WindowProperties::WIN_HEIGHT;
unsigned int WindowProperties::WIN_WIDTH;
GameState WindowProperties::gameState;
sf::RenderWindow *WindowProperties::App;

int main()
{
    GameCore &game = GameCore::Instance();

    game.start();
    delete WindowProperties::App;
}