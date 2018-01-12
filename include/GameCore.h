//
// Created by loic lopez on 12/01/2018.
//

#ifndef R_TYPE_GAMECORE_H
#define R_TYPE_GAMECORE_H

#include "WindowProperties.h"
#include "MenuCore.hpp"

class GameCore
{
private:
    static GameCore m_instance;
    MenuCore    &menuCore;


public:
    GameCore();
    ~GameCore();
    void start();
    static GameCore &Instance();
};

#endif //R_TYPE_GAMECORE_H
