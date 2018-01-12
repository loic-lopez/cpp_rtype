//
// Created by Loic Dupil on 11/01/2018.
//

#include "GameEngine.h"

GameEngine GameEngine::m_Instance = GameEngine::GameEngine();

GameEngine::GameEngine() : gameEngineThread([] () { GameEngine::Instance().ThreadRun(); }){

}

GameEngine::~GameEngine()
{

}

void GameEngine::ThreadRun()
{
  GameEngine::Thing *player;
  GameEngine::Thing *enemy;
  while ()
  for (size_t i = 0; i < m_Instance.Entities.size(); i++)
  {
    if (m_Instance.Entities[i].type == Textures::REIMU)
      player = m_Instance.Entities[i];
    if (m_Instance.Entities[i].type == Textures::ENEMY1)
      enemy = m_Instance.Entities[i];
  }
  for (size_t i = 0; i < m_Instance.Entities.size(); i++)
  {
    if (m_Instance.Entities[i].type != Textures::REIMU && m_Instance.Entities[i].type != Textures::REIMU_BULLETS_A)
      if (m_Instance.checkPlayerBoxe(player, m_Instance.Entities[i]) == -1)
        return;
    if (m_Instance.Entities[i].type == Textures::REIMU || m_Instance.Entities[i].type == Textures::REIMU_BULLETS_A)
      if (m_Instance.checkPlayerBoxe(enemy, m_Instance.Entities[i]) == -1)
        return;
  }
}

void GameEngine::checkHitBoxes()
{

}

GameEngine::Thing::Thing()
{

}

void GameEngine::start()
{
  this->gameEngineThread.launch();
}

GameEngine &GameEngine::Instance()
{
  return m_Instance;
}

void  GameEngine::fillEntities(Entity *obj, Side side, Textures type)
{
  GameEngine::Thing *entity = new GameEngine::Thing();
  entity->obj = obj;
  entity->hitBox = obj->getBounds();
  entity->side = side;
  entity->type = type;

  this->Entities.push_back(entity);
}

std::vector<GameEngine::Thing *> GameEngine::getEntities()
{
  return std::vector<GameEngine::Thing *>();
}

int   GameEngine::checkPlayerBoxe(GameEngine::Thing *player, GameEngine::Thing *obstacles)
{
  float _x = obstacles->obj->getPos().x - obstacles->hitBox.left;
  float _y = obstacles->obj->getPos().y - obstacles->hitBox.top;
  float x = obstacles->obj->getPos().x + obstacles->hitBox.width;
  float y = obstacles->obj->getPos().y + obstacles->hitBox.height;
  if (player->hitBox.contains(_x, _y) || player->hitBox.contains(_x, y)
      || player->hitBox.contains(x, _y) || player->hitBox.contains(x, y))
    return -1;
  else
    return 0;
}