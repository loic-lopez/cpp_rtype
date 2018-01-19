//
// Created by loic lopez on 12/01/2018.
//

#include <Handler/GameHandler.h>

GameHandler GameHandler::m_instance = GameHandler();

/************************************************* CONSTRUCTOR DESTRUCTOR *************************************************/
GameHandler::GameHandler()
{
    hud.initHud("HUD");
}

GameHandler::GameHandler(const GameHandler &obj)
{
    hud = obj.hud;
}

GameHandler& GameHandler::operator=(const GameHandler &obj)
{
    hud = obj.hud;
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
    scoreSave = 0;

    WindowProperties::App->setMouseCursorVisible(false);
    while (WindowProperties::gameState == GameState::LEVEL1)
        this->startLevel1();
    while (WindowProperties::gameState == GameState::LEVEL2)
        this->startLevel2();
    while (WindowProperties::gameState == GameState::LEVEL3)
        this->startLevel3();
    while (WindowProperties::gameState == GameState::LEVEL4)
        this->startLevel4();
    while (WindowProperties::gameState == GameState::LEVEL5)
        this->startLevel5();
    WindowProperties::App->setMouseCursorVisible(true);
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
            return this->level2;
        case GameState::LEVEL3:
            return this->level3;
        case GameState::LEVEL4:
            return this->level4;
        case GameState::LEVEL5:
            return this->level5;
        default:
            break;
    }
    return nullptr;
}

ALevel *GameHandler::getCurrentLevel(GameState currentLevel)
{
    switch (currentLevel)
    {
        case GameState::LEVEL1:
            return this->level1;
        case GameState::LEVEL2:
            return this->level2;
        case GameState::LEVEL3:
            return this->level3;
        case GameState::LEVEL4:
            return this->level4;
        case GameState::LEVEL5:
            return this->level5;
        default:
            break;
    }
    return nullptr;
}

void GameHandler::startLevel1()
{
    std::unique_ptr<ALevel> level1 = std::unique_ptr<ALevel>(new Space());
    this->level1 = level1.get();
    this->level1->start();
}

void GameHandler::startLevel2()
{
    std::unique_ptr<ALevel> level2 = std::unique_ptr<ALevel>(new DeepSpace());
    this->level2 = level2.get();
    this->level2->start();
}

void GameHandler::startLevel3()
{
    std::unique_ptr<ALevel> level3 = std::unique_ptr<ALevel>(new SpaceCemetery());
    this->level3 = level3.get();
    this->level3->start();
}

void GameHandler::startLevel4()
{
    std::unique_ptr<ALevel> level4 = std::unique_ptr<ALevel>(new Horizon());
    this->level4 = level4.get();
    this->level4->start();
}

void GameHandler::startLevel5()
{
    std::unique_ptr<ALevel> level5 = std::unique_ptr<ALevel>(new Underwater());
    this->level5 = level5.get();
    this->level5->start();
}

void GameHandler::resetGameToRetry()
{
    hud.resetHud();
}
