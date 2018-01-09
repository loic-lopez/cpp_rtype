//
// Created by Eric on 30/11/2017.
//

#ifndef RTYPE_GAME_H
#define RTYPE_GAME_H

#include <iostream>
#include <thread>
#include <SFML/Graphics.hpp>
#include "Enum.h"
#include "Player.h"
#include "Level.h"
#include "Enemy.h"
#include "WindowProperties.h"

class Game {
private:
    static Game m_instance;
    Game();
    ~Game();
    Game& operator= (const Game&){}
    Game (const Game&){}
    //Orientation orientation;
    GameState gameState;
    sf::Clock clock;

    Level level;
    Player play;
    std::vector<IEntity *> bulletsEnemy;
    std::vector<IEntity *> bulletsAllied;
    std::vector<IEntity *> entities;

    sf::Mutex mutex;
public:
    static Game& Instance();
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


#endif //RTYPE_GAME_H
