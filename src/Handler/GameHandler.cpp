//
// Created by loic lopez on 12/01/2018.
//

#include <Handler/GameHandler.h>

GameHandler GameHandler::m_instance = GameHandler();

/************************************************* CONSTRUCTOR DESTRUCTOR *************************************************/
GameHandler::GameHandler() : level1(Level())
{
    hud.initHud("hud");
}

GameHandler::~GameHandler()
{
    //level.setMusicStatus("stop");
}

GameHandler &GameHandler::Instance()
{
    return m_instance;
}

void GameHandler::start()
{
    level1.start();
}

Player &GameHandler::getPlayer() const
{
    return this->player;
}

Hud & GameHandler::getHud() const
{
    return hud;
}

ALevel &GameHandler::getCurrentLevel()
{
    switch (WindowProperties::gameState)
    {
        case GameState::LEVEL1:
            return level1;
        case GameState::LEVEL2:
            break;
        default:
            break;
    }
}
