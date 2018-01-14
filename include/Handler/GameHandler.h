//
// Created by loic lopez on 12/01/2018.
//

#ifndef R_TYPE_GAMEHANDLER_H
#define R_TYPE_GAMEHANDLER_H

#include <iostream>
#include <thread>
#include <SFML/Graphics.hpp>
#include "Enum.h"
#include "Player.h"
#include "Level.h"
#include "Enemy.h"
#include "WindowProperties.h"
#include "HUD.h"
#include "GameEngine.h"

class GameHandler
{
    GameEngine  &gameEngine;

private:
    static GameHandler m_instance;

    GameHandler();

    ~GameHandler();

    GameHandler &operator=(const GameHandler &)
    {}

    GameHandler(const GameHandler &) : gameEngine(GameEngine::Instance())
    {}

    //Orientation orientation;
    GameState gameState;
    sf::Clock clock;

    Hud hud;
    Level level;
    Player play;
    std::vector<IEntity *> bulletsEnemy;
    std::vector<IEntity *> bulletsAllied;
    std::vector<IEntity *> entities;

    sf::Mutex mutex;
public:
    static GameHandler &Instance();

    void start();

    void controller();

    void XboxController();

    void changeOrientation(Orientation orientation);

    void drawAll(sf::RenderWindow &App);

    void updateAlliedBullet();

    void updateEntities();

    void lock();

    void unlock();

    void addBullet(IEntity *);
};

#endif //R_TYPE_GAMEHANDLER_H
