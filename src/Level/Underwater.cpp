//
// Created by Pierre on 03/12/2017.
//

#include <Parsing.h>
#include <Enemy.h>
#include <cmath>
#include <Static/PreGame.h>
#include <Handler/GameHandler.h>
#include "Level/Underwater.h"

Underwater::Underwater() : ALevel() {
    initLvl("lvl5");
    currentGameLevel = GameState::LEVEL5;
   /* this->phases.emplace_back([this]()
                              {
                                  std::map<EnemyType , int >enemies;
                                  enemies.insert({EnemyType::BASIC_A, 4});
                                  generateEnemies(enemies);
                              });
    this->phases.emplace_back([this]()
                              {
                                  std::map<EnemyType , int >enemies;
                                  enemies.insert({EnemyType::BASIC_A, 6});
                                  generateEnemies(enemies);
                              });
    this->phases.emplace_back([this]()
                              {
                                  std::map<EnemyType , int >enemies;
                                  enemies.insert({EnemyType::BASIC_A, 4});
                                  enemies.insert({EnemyType::BASIC_B, 2});
                                  generateEnemies(enemies);
                              });*/
    this->phases.emplace_back([this]()
                              {
                                  std::map<EnemyType , int >enemies;
                                  enemies.insert({EnemyType::BOSS_E, 1});
                                  generateEnemies(enemies);
                              });
    this->phases.emplace_back([this]() {  if (ennemies.empty()) GameHandler::Instance().getCurrentLevel()->setWin(true); });
    phaseMax = static_cast<short>(this->phases.size() - 1);
}

Underwater::~Underwater() {
    music.stop();
    back.flushLayers();
}

void Underwater::start()
{
    PreGame::startPreGameLevel5();

    music.play();
    this->mainLoop();//enemiesGenerator);
    music.stop();
}