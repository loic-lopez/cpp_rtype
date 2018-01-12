//
// Created by loic lopez on 12/01/2018.
//

#ifndef R_TYPE_GAMECORE_H
#define R_TYPE_GAMECORE_H

#include <Handler/GameHandler.h>
#include "WindowProperties.h"
#include "MenuCore.hpp"

class GameCore
{
private:
    static GameCore m_instance;
    MenuCore    &menuCore;
    GameHandler &gameHandler;

public:
    GameCore();
    ~GameCore();
    void start();
    static GameCore &Instance();
};

#endif //R_TYPE_GAMECORE_H
