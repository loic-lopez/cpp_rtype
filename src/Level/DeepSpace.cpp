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
    this->phases.emplace_back([this]() { generateEnemies(EnemyType::BASIC_A, 4, EnemyType::NONE, 0); });
    this->phases.emplace_back([this]() { generateEnemies(EnemyType::BASIC_A, 6, EnemyType::NONE, 0); });
    this->phases.emplace_back([this]() { generateEnemies(EnemyType::BASIC_A, 4, EnemyType::BASIC_B, 2); });
    this->phases.emplace_back([this]() {  generateEnemies(EnemyType::BOSS_A, 1, EnemyType::NONE, 0); });
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