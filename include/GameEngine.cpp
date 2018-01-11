//
// Created by Loic Dupil on 11/01/2018.
//

#include "GameEngine.h"

GameEngine GameEngine::m_Instance = GameEngine::GameEngine();

GameEngine::GameEngine()
{

}


GameEngine::~GameEngine()
{

}


void GameEngine::run()
{

}


void GameEngine::addThing()
{

}

void GameEngine::checkHitBoxes()
{

}


GameEngine::Thing::Thing()
{

}

void GameEngine::start()
{
    //thread(&GameEngine::run);

  std::function<void ()> func = std::bind([] () {});
  std::thread thread(func);

}