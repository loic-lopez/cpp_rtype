//
// Created by Zakelis on 16/01/2018.
//

#ifndef R_TYPE_GAMEOVERSCREEN_H
#define R_TYPE_GAMEOVERSCREEN_H

#include <SFML/Audio/Music.hpp>
#include <iostream>
#include "Static/WindowProperties.h"
#include "Handler/GameOverScreenHandler.h"

class GameOverScreenCore
{
private:
    GameState                   previousGameState;
public:
    GameState getPreviousGameState() const;

    void setPreviousGameState(GameState previousGameState);

private:
    static GameOverScreenCore   m_instance;
    GameOverScreenHandler       gameOverScreen;
public:
    GameOverScreenHandler &getGameOverScreen();

private:

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
