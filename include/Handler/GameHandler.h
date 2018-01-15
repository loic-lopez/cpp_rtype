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

#pragma once

class GameHandler
{
private:
    static GameHandler m_instance;

    GameHandler();

    ~GameHandler();

    GameHandler &operator=(const GameHandler &)
    {
        return *this;
    }

    GameHandler(const GameHandler &)
    {}

    sf::Clock clock;
    sf::Clock inv;

    Hud hud;
    Level level;
    Player player;
    std::vector<IEntity *> bulletsEnemy;
    std::vector<IEntity *> bulletsAllied;
    std::vector<IEntity *> entities;

    sf::Time   cloque;
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
    void checkEntitiesBoxes();

    Player &getPlayer();
};

#endif //R_TYPE_GAMEHANDLER_H
