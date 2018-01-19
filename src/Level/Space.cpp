//
// Created by Pierre on 03/12/2017.
//

#include <Parsing.h>
#include <Enemy.h>
#include <Static/PreGame.h>
#include "Level/Space.h"

Space::Space() : ALevel()
{
    initLvl("lvl1");
    currentGameLevel = GameState::LEVEL1;

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
                                  enemies.insert({EnemyType::BOSS_A, 1});
                                  generateEnemies(enemies);
                              });
    this->phases.emplace_back([this]()
                              { if (ennemies.empty()) WindowProperties::gameState = GameState::LEVEL2; });
    phaseMax = static_cast<short>(this->phases.size() - 1);
}

Space::~Space()
{
    music.stop();
    back.flushLayers();
}

void Space::start()
{
    PreGame::startPreGameLevel1();

    music.play();
    this->mainLoop();
    music.stop();
}