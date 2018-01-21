//
// Created by loic lopez on 17/01/2018.
//

#include <Enemy.h>
#include <Level/Horizon.h>
#include <Static/PreGame.h>

Horizon::Horizon() : ALevel()
{
    initLvl("lvl4");
    currentGameLevel = GameState::LEVEL4;
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
                                  enemies.insert({EnemyType::BOSS_D, 1});
                                  generateEnemies(enemies);
                              });
    this->phases.emplace_back([this]() {  if (ennemies.empty()) WindowProperties::gameState = GameState::LEVEL5; });
    phaseMax = static_cast<short>(this->phases.size() - 1);
}

Horizon::~Horizon()
{

}

void Horizon::start()
{
    PreGame::startPreGameLevel4();
    // music.play();
    this->mainLoop();
    // music.stop();
}

void Horizon::enemiesGenerator(short) {

}
