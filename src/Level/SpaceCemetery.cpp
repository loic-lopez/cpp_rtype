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
    if (WindowProperties::difficulty == Difficulty::HARMLESS)
    {
        this->phases.emplace_back([this]() {
            std::map<EnemyType, int> enemies;
            enemies.insert({EnemyType::BASIC_A, 4});
            generateEnemies(enemies);
        });
        this->phases.emplace_back([this]() {
            std::map<EnemyType, int> enemies;
            enemies.insert({EnemyType::BASIC_A, 6});
            generateEnemies(enemies);
        });
        this->phases.emplace_back([this]() {
            std::map<EnemyType, int> enemies;
            enemies.insert({EnemyType::BASIC_A, 4});
            enemies.insert({EnemyType::BASIC_B, 2});
            generateEnemies(enemies);
        });
        this->phases.emplace_back([this]() {
            std::map<EnemyType, int> enemies;
            enemies.insert({EnemyType::BOSS_C, 1});
            generateEnemies(enemies);
        });
    }
    else if (WindowProperties::difficulty == Difficulty::SADISTIC)
    {
        this->phases.emplace_back([this]() {
            std::map<EnemyType, int> enemies;
            enemies.insert({EnemyType::BASIC_A, 5});
            generateEnemies(enemies);
        });
        this->phases.emplace_back([this]() {
            std::map<EnemyType, int> enemies;
            enemies.insert({EnemyType::BASIC_A, 7});
            generateEnemies(enemies);
        });
        this->phases.emplace_back([this]() {
            std::map<EnemyType, int> enemies;
            enemies.insert({EnemyType::BASIC_A, 4});
            enemies.insert({EnemyType::BASIC_B, 3});
            generateEnemies(enemies);
        });
        this->phases.emplace_back([this]() {
            std::map<EnemyType, int> enemies;
            enemies.insert({EnemyType::BOSS_C, 1});
            generateEnemies(enemies);
        });
    }
    else
    {
        this->phases.emplace_back([this]() {
            std::map<EnemyType, int> enemies;
            enemies.insert({EnemyType::BASIC_A, 6});
            generateEnemies(enemies);
        });
        this->phases.emplace_back([this]() {
            std::map<EnemyType, int> enemies;
            enemies.insert({EnemyType::BASIC_A, 8});
            generateEnemies(enemies);
        });
        this->phases.emplace_back([this]() {
            std::map<EnemyType, int> enemies;
            enemies.insert({EnemyType::BASIC_A, 4});
            enemies.insert({EnemyType::BASIC_B, 4});
            generateEnemies(enemies);
        });
        this->phases.emplace_back([this]() {
            std::map<EnemyType, int> enemies;
            enemies.insert({EnemyType::BASIC_B, 2});
            enemies.insert({EnemyType::BOSS_C, 1});
            generateEnemies(enemies);
        });
    }
    this->phases.emplace_back([this]() {  if (ennemies.empty()) WindowProperties::gameState = GameState::LEVEL4; });
    phaseMax = static_cast<short>(this->phases.size() - 1);
}

SpaceCemetery::~SpaceCemetery()
{

}

void SpaceCemetery::start()
{
    PreGame::startPreGameLevel3();

    music.play();
    this->mainLoop();
    music.stop();
}