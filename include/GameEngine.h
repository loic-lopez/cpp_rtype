//
// Created by Loic Dupil on 11/01/2018.
//

#ifndef R_TYPE_GAMEENGINE_H
#define R_TYPE_GAMEENGINE_H

#include <WindowProperties.h>
#include <iostream>
#include <string>
#include <fstream>
#include <thread>
#include "Game.h"
#include "Entity.h"
#include "Enum.h"

class GameEngine
{
    struct Thing {
        sf::FloatRect   hitBox;
        Side            side;
        Textures        type;
        Thing();
    };

    std::vector<Thing>  Entities;
    static GameEngine   m_Instance;
    std::thread         GameEngineThread;

public:
    static GameEngine   &Instance();
    GameEngine();
    ~GameEngine();

    static void run();

    void addThing();
    void checkHitBoxes();
    void start();
};


#endif //R_TYPE_GAMEENGINE_H
