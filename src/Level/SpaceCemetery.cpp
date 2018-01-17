//
// Created by loic lopez on 17/01/2018.
//

#include <Enemy.h>
#include <Level/SpaceCemetery.h>

SpaceCemetery::SpaceCemetery() : ALevel()
{
    initLvl("lvl3");
    currentGameLevel = GameState::LEVEL3;
}

SpaceCemetery::~SpaceCemetery()
{

}

void SpaceCemetery::start()
{
    for (int i = 0; i < (std::rand() % 5 + 5); ++i)
        ennemies.push_back(std::shared_ptr<IEntity>(new Enemy(EnemyType::BASIC_A)));
    for (int i = 0; i < (std::rand() % 4 + 1); ++i)
        ennemies.push_back(std::shared_ptr<IEntity>(new Enemy(EnemyType::BASIC_B)));

    bulletsEnemy.reserve(100000);

   // music.play();
    this->mainLoop();
   // music.stop();
}
