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
#include "Level/Level1.h"
#include "Enemy.h"
#include "WindowProperties.h"
#include "HUD.h"

#pragma once

class GameHandler
{
private:
    static GameHandler m_instance;
    Player *player;
    Hud hud;
    ALevel *level1;

public:
    GameHandler();
    GameHandler(const GameHandler &);
    GameHandler &operator=(const GameHandler &);
    ~GameHandler();

    static GameHandler &Instance();

    void start();
    Player *getPlayer();
    Hud &getHud();
    ALevel *getCurrentLevel();
};

#endif //R_TYPE_GAMEHANDLER_H
