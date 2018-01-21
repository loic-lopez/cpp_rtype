//
// Created by Loic Dupil on 17/01/2018.
//

#include <Parsing.h>
#include <Enemy.h>
#include <cmath>
#include <Static/PreGame.h>
#include "Level/DeepSpace.h"

DeepSpace::DeepSpace() : ALevel()
{
    initLvl("lvl2");
    currentGameLevel = GameState::LEVEL2;
    this->phases.emplace_back([this]()
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
                              });
    this->phases.emplace_back([this]()
                              {
                                  std::map<EnemyType , int >enemies;
                                  enemies.insert({EnemyType::BOSS_B, 1});
                                  generateEnemies(enemies);
                              });
    this->phases.emplace_back([this]() {  if (ennemies.empty()) WindowProperties::gameState = GameState::LEVEL3; });
    phaseMax = static_cast<short>(this->phases.size() - 1);
}

DeepSpace::~DeepSpace()
{
    music.stop();
    back.flushLayers();
}

void    DeepSpace::start()
{
    PreGame::startPreGameLevel2();

    music.play();
    mainLoop();
    music.stop();
}