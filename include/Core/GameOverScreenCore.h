//
// Created by Zakelis on 16/01/2018.
//

#ifndef R_TYPE_GAMEOVERSCREEN_H
#define R_TYPE_GAMEOVERSCREEN_H

#include <SFML/Audio/Music.hpp>
#include <iostream>
#include "WindowProperties.h"
#include "Handler/GameOverScreenHandler.h"

class GameOverScreenCore
{
private:
    static GameOverScreenCore   m_instance;
    sf::Clock                   clock;
    GameOverScreenHandler       gameOverScreen;

    void EventHandler(sf::Event &event);
    GameOverScreenCore();
    ~GameOverScreenCore();
    GameOverScreenCore &operator=(const GameOverScreenCore&)
    {
        return *this;
    }
    GameOverScreenCore(const GameOverScreenCore&)
    {
    }

public:
    static GameOverScreenCore &Instance();
    void start();
};

#endif //R_TYPE_GAMEOVERSCREEN_H
