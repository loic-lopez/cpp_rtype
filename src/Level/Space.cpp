//
// Created by Pierre on 03/12/2017.
//

#include <Parsing.h>
#include <Enemy.h>
#include <cmath>
//#include <Static/PreGame.h>
#include "Level/Space.h"

Space::Space() : ALevel() {
    initLvl("lvl1");
    currentGameLevel = GameState::LEVEL1;

    this->phases.emplace_back([this]() { generateEnemies(EnemyType::BASIC_A, 4, EnemyType::NONE, 0); });
    this->phases.emplace_back([this]() { generateEnemies(EnemyType::BASIC_A, 6, EnemyType::NONE, 0); });
    this->phases.emplace_back([this]() { generateEnemies(EnemyType::BASIC_A, 4, EnemyType::BASIC_B, 2); });
    this->phases.emplace_back([this]() {  generateEnemies(EnemyType::BOSS_A, 1, EnemyType::NONE, 0); });
    this->phases.emplace_back([this]() {  if (ennemies.empty()) WindowProperties::gameState = GameState::LEVEL2; });
}

Space::~Space() {
    music.stop();
    back.flushLayers();
}

void Space::start()
{
    bulletsEnemy.reserve(100000);

    // PreGame::startPreGameLevel1();

    music.play();
    this->mainLoop();//enemiesGenerator);
    music.stop();
}
