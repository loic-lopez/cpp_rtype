//
// Created by Zakelis on 16/01/2018.
//

#ifndef R_TYPE_WINSCREEN_H
#define R_TYPE_WINSCREEN_H

#include <SFML/Audio/Music.hpp>
#include <iostream>
#include "Static/WindowProperties.h"
#include "Handler/WinScreenHandler.h"

class WinScreenCore
{
private:
    GameState                   previousGameState;
public:
    GameState getPreviousGameState() const;

    void setPreviousGameState(GameState previousGameState);

private:
    static WinScreenCore   m_instance;
    WinScreenHandler       winScreen;
public:
    WinScreenHandler &getWinScreen();

private:

    void EventHandler(sf::Event &event);
    WinScreenCore();
    ~WinScreenCore();
    WinScreenCore &operator=(const WinScreenCore&)
    {
        return *this;
    }
    WinScreenCore(const WinScreenCore&)
    {
    }

public:
    static WinScreenCore &Instance();
    void start();
};

#endif //R_TYPE_WINSCREEN_H
