#include <Core/GameCore.h>

unsigned int WindowProperties::WIN_HEIGHT;
unsigned int WindowProperties::WIN_WIDTH;
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