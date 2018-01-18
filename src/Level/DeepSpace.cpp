//
// Created by Loic Dupil on 17/01/2018.
//

#include <Parsing.h>
#include <Enemy.h>
#include <cmath>
#include "Level/DeepSpace.h"

DeepSpace::DeepSpace() : ALevel()
{
    initLvl("lvl2");
    currentGameLevel = GameState::LEVEL2;
}

DeepSpace::~DeepSpace()
{
    music.stop();
    back.flushLayers();
}

void    DeepSpace::start()
{
    for (int i = 0; i < (std::rand() % 5 + 5); ++i)
        ennemies.push_back(std::shared_ptr<IEntity>(new Enemy(EnemyType::BASIC_A)));
    for (int i = 0; i < (std::rand() % 4 + 1); ++i)
        ennemies.push_back(std::shared_ptr<IEntity>(new Enemy(EnemyType::BASIC_B)));

    music.play();
    music.stop();
}

void DeepSpace::enemiesGenerator(short) {

}
