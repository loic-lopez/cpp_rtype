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

    std::unique_ptr<ALevel> level1 = std::unique_ptr<ALevel>(new Space());
    std::unique_ptr<ALevel> level3 = std::unique_ptr<ALevel>(new SpaceCemetery());
    std::unique_ptr<ALevel> level4 = std::unique_ptr<ALevel>(new Horizon());

    this->level1 = level1.get();
    this->level3 = level3.get();
    this->level4 = level4.get();

    this->level1->start();
    this->level3->start();
    this->level4->start();
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
        case GameState::LEVEL3:
            return this->level3;
        case GameState::LEVEL4:
            return this->level4;
        default:
            break;
    }
    return nullptr;
}
