//
// Created by loic lopez on 12/01/2018.
//

#include <Handler/GameHandler.h>

GameHandler GameHandler::m_instance = GameHandler();

/************************************************* CONSTRUCTOR DESTRUCTOR *************************************************/
GameHandler::GameHandler()
{
    hud.initHud("hud");
}

GameHandler::GameHandler(const GameHandler &obj)
{

}

GameHandler& GameHandler::operator=(const GameHandler &obj)
{
    return *this;
}

GameHandler::~GameHandler()
{
    //level.setMusicStatus("stop");
    delete level1;
}

GameHandler &GameHandler::Instance()
{
    return m_instance;
}

void GameHandler::start()
{
    player = new Player();
    level1 = new Level1();

    level1->start();

    delete player;
    delete level1;
}

Player *GameHandler::getPlayer()
{
    return this->player;
}

Hud & GameHandler::getHud()
{
    return hud;
}

ALevel *GameHandler::getCurrentLevel()
{
    switch (WindowProperties::gameState)
    {
        case GameState::LEVEL1:
            return this->level1;
        case GameState::LEVEL2:
            break;
        default:
            break;
    }
    return nullptr;
}
