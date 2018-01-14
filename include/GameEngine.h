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
#include "Entity.h"
#include "Enum.h"

class GameEngine
{
    struct Thing {
        Entity          *obj;
        sf::FloatRect   hitBox;
        Side            side;
        Textures        type;
        Thing();
    };

    std::vector<Thing *>  Entities;
    static GameEngine   m_Instance;
    sf::Thread          *gameEngineThread;
    bool                active;

public:
    static GameEngine   &Instance();
    GameEngine();
    ~GameEngine();

    static void ThreadRun();
    std::vector<Thing *>      getEntities();
    void                    fillEntities(Entity *, Side, Textures);

    void addThing();
    void checkHitBoxes();
    void start();
    int  checkPlayerBoxe(GameEngine::Thing *player, GameEngine::Thing *obstacles);
    void stopThread();
};


#endif //R_TYPE_GAMEENGINE_H
