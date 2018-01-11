//
// Created by Loic Dupil on 11/01/2018.
//

#include "GameEngine.h"

GameEngine GameEngine::m_Instance = GameEngine::GameEngine();

GameEngine::GameEngine() : gameEngineThread([] () { GameEngine::Instance().run(); })
{

}


GameEngine::~GameEngine()
{

}


void GameEngine::run()
{
  std::cerr << "coucou" << std::endl;
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
  m_Instance.gameEngineThread.launch();
}

GameEngine &GameEngine::Instance()
{
  return m_Instance;
}
