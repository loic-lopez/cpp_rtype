//
// Created by loic lopez on 12/01/2018.
//

#include <GameCore.h>

GameCore GameCore::m_instance = GameCore();

GameCore::GameCore() : menuCore(MenuCore::Instance())
{

}

GameCore::~GameCore()
{

}

void GameCore::start()
{
    // TODO: ADD SPLASHSCREEN
    while (WindowProperties::App->isOpen() && WindowProperties::gameState != GameState::CLOSE)
    {
        this->menuCore.start();
        // TODO: ADD GAME
    }
    WindowProperties::App->close();
}

GameCore &GameCore::Instance()
{
    return m_instance;
}
