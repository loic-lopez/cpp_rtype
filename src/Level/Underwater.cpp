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
}

Underwater::~Underwater() {
    music.stop();
    back.flushLayers();
}

void Underwater::start() {
/*
    for (int i = 0; i < (std::rand() % 5 + 5); ++i)
        ennemies.push_back(std::shared_ptr<IEntity>(new Enemy(EnemyType::BASIC_A)));
    for (int i = 0; i < (std::rand() % 4 + 1); ++i)
        ennemies.push_back(std::shared_ptr<IEntity>(new Enemy(EnemyType::BASIC_B)));
*/
    ennemies.push_back(std::shared_ptr<IEntity>(new Enemy(EnemyType::BOSS_A)));
    bulletsEnemy.reserve(100000);

    music.play();
    this->mainLoop();
    music.stop();
}