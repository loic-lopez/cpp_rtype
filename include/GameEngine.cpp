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

  sf::Thread([] () {
      std::cerr << "coucou" << std::endl;
  }).launch();

}

GameEngine &GameEngine::Instance()
{
  return m_Instance;
}
