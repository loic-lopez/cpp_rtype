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
#include "Level/Space.h"
#include "Level/DeepSpace.h"
#include "Level/SpaceCemetery.h"
#include "Level/Horizon.h"
#include "Level/Underwater.h"
#include "Enemy.h"
#include "Static/WindowProperties.h"
#include "HUD.h"

#pragma once

class GameHandler
{
private:
    static GameHandler m_instance;
    Player *player;
    Hud hud;

private:
    ALevel *level1;
    ALevel *level2;
    ALevel *level3;
    ALevel *level4;
    ALevel *level5;
    void    startLevel1();
    void    startLevel2();
    void    startLevel3();
    void    startLevel4();
    void    startLevel5();

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
    ALevel *getCurrentLevel(GameState currentLevel);
};

#endif //R_TYPE_GAMEHANDLER_H
