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
}

Space::~Space() {
    music.stop();
    back.flushLayers();
}

void Space::start() {
    for (int i = 0; i < (std::rand() % 5 + 5); ++i)
        ennemies.push_back(std::shared_ptr<IEntity>(new Enemy(EnemyType::BASIC_A)));
    for (int i = 0; i < (std::rand() % 4 + 1); ++i)
        ennemies.push_back(std::shared_ptr<IEntity>(new Enemy(EnemyType::BASIC_B)));
    bulletsEnemy.reserve(100000);

    // PreGame::startPreGameLevel1();

    music.play();
    this->mainLoop();
    music.stop();
}