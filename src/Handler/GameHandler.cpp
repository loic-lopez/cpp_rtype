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
}

GameHandler &GameHandler::Instance()
{
    return m_instance;
}

void GameHandler::start()
{
    std::unique_ptr<Player> player = std::unique_ptr<Player>(new Player());
    this->player = player.get();

    std::unique_ptr<ALevel> level2 = std::unique_ptr<ALevel>(new Level2());
    this->level1 = level2.get();

    this->level1->start();
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
