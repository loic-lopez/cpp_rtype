//
// Created by Pierre on 03/12/2017.
//

#include <Parsing.h>
#include <Enemy.h>
#include <cmath>
#include "Level/Underwater.h"

Underwater::Underwater() : ALevel() {
    initLvl("lvl5");
    currentGameLevel = GameState::LEVEL5;
    this->phases.emplace_back([this]() { generateEnemies(EnemyType::BASIC_A, 4, EnemyType::NONE, 0); });
    this->phases.emplace_back([this]() { generateEnemies(EnemyType::BASIC_A, 6, EnemyType::NONE, 0); });
    this->phases.emplace_back([this]() { generateEnemies(EnemyType::BASIC_A, 4, EnemyType::BASIC_B, 2); });
    this->phases.emplace_back([this]() {  generateEnemies(EnemyType::BOSS_A, 1, EnemyType::NONE, 0); });
    this->phases.emplace_back([this]() {  if (ennemies.empty()) WindowProperties::gameState = GameState::MENU; });
    phaseMax = static_cast<short>(this->phases.size() - 1);
}

Underwater::~Underwater() {
    music.stop();
    back.flushLayers();
}

void Underwater::start()
{
    music.play();
    this->mainLoop();//enemiesGenerator);
    music.stop();
}