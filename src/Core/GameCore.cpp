//
// Created by loic lopez on 12/01/2018.
//

#include <Core/GameCore.h>

GameCore GameCore::m_instance = GameCore();

GameCore::GameCore() : menuCore(MenuCore::Instance()),
                       gameHandler(GameHandler::Instance()),
                       splashScreen(SplashScreen::Instance())
{

}

GameCore::~GameCore()
{

}

void GameCore::start()
{
    // TODO: ADD SPLASHSCREEN
    this->splashScreen.start();
    while (WindowProperties::App->isOpen() && WindowProperties::gameState != GameState::CLOSE)
    {
        this->menuCore.start();
        this->gameHandler.start();
        // TODO: ADD GAME
    }
    WindowProperties::App->close();
}

GameCore &GameCore::Instance()
{
    return m_instance;
}
