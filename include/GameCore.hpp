//
// Created by Eric on 30/11/2017.
//

#ifndef RTYPE_GameCore_H
#define RTYPE_GameCore_H

#include <iostream>
#include <thread>
#include <SFML/Graphics.hpp>
#include "Enum.h"
#include "Player.h"
#include "Level.h"
#include "Enemy.h"
#include "WindowProperties.h"
#include "HUD.h"
#include "Menu.h"
#include "Button.h"

class GameCore
{
private:
    static GameCore m_instance;

    GameCore();

    ~GameCore();

    GameCore &operator=(const GameCore &)
    {}

    GameCore(const GameCore &)
    {}

    //Orientation orientation;
    GameState GameState;
    sf::Clock clock;

    Hud hud;
    Level level;
    Menu menu;
    Player play;
    std::vector<IEntity *> bulletsEnemy;
    std::vector<IEntity *> bulletsAllied;
    std::vector<IEntity *> entities;

    sf::Mutex mutex;
public:
    static GameCore &Instance();

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


#endif //RTYPE_GameCore_H
