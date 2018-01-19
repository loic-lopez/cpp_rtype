//
// Created by loic lopez on 17/01/2018.
//

#include <Enemy.h>
#include <Level/SpaceCemetery.h>
#include <Static/PreGame.h>

SpaceCemetery::SpaceCemetery() : ALevel()
{
    initLvl("lvl3");
    currentGameLevel = GameState::LEVEL3;
    this->phases.emplace_back([this]() { generateEnemies(EnemyType::BASIC_A, 4, EnemyType::NONE, 0); });
    this->phases.emplace_back([this]() { generateEnemies(EnemyType::BASIC_A, 6, EnemyType::NONE, 0); });
    this->phases.emplace_back([this]() { generateEnemies(EnemyType::BASIC_A, 4, EnemyType::BASIC_B, 2); });
    this->phases.emplace_back([this]() {  generateEnemies(EnemyType::BOSS_A, 1, EnemyType::NONE, 0); });
    this->phases.emplace_back([this]() {  if (ennemies.empty()) WindowProperties::gameState = GameState::LEVEL4; });
    phaseMax = static_cast<short>(this->phases.size() - 1);
}

SpaceCemetery::~SpaceCemetery()
{

}

void SpaceCemetery::start()
{
    PreGame::startPreGameLevel3();
   // music.play();
    this->mainLoop();
   // music.stop();
}