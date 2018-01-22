//
// Created by loic lopez on 12/01/2018.
//

#ifndef R_TYPE_GAMECORE_H
#define R_TYPE_GAMECORE_H

#include <Handler/GameHandler.h>
#include "Static/WindowProperties.h"
#include "MenuCore.hpp"
#include "SplashScreen.h"
#include "GameOverScreenCore.h"
#include "MenuInGameCore.h"
#include "WinScreenCore.h"

class GameCore
{
private:
    static GameCore m_instance;
    MenuCore    &menuCore;
    GameHandler &gameHandler;
    SplashScreen &splashScreen;
    WinScreenCore   &winScreenCore;

public:
    WinScreenCore &getWinScreenCore() const;

public:
    GameOverScreenCore &getGameOverScreen();

private:
    GameOverScreenCore &gameOverScreen;
    MenuInGameCore &menuInGameCore;
public:
    MenuInGameCore &getMenuInGameCore();

public:
    GameCore();
    ~GameCore();
    void start();
    static GameCore &Instance();
};

#endif //R_TYPE_GAMECORE_H
