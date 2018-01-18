//
// Created by loic lopez on 17/01/2018.
//

#include <Enemy.h>
#include <Level/Horizon.h>

Horizon::Horizon() : ALevel()
{
    initLvl("lvl4");
    currentGameLevel = GameState::LEVEL4;
    this->phases.emplace_back([this]() { generateEnemies(EnemyType::BASIC_A, 4, EnemyType::NONE, 0); });
    this->phases.emplace_back([this]() { generateEnemies(EnemyType::BASIC_A, 6, EnemyType::NONE, 0); });
    this->phases.emplace_back([this]() { generateEnemies(EnemyType::BASIC_A, 4, EnemyType::BASIC_B, 2); });
    this->phases.emplace_back([this]() {  generateEnemies(EnemyType::BOSS_A, 1, EnemyType::NONE, 0); });
    this->phases.emplace_back([this]() {  if (ennemies.empty()) WindowProperties::gameState = GameState::LEVEL5; });
    phaseMax = static_cast<short>(this->phases.size() - 1);
}

Horizon::~Horizon()
{

}

void Horizon::start()
{

    // music.play();
    this->mainLoop();
    // music.stop();
}

void Horizon::enemiesGenerator(short) {

}
