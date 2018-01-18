//
// Created by loic lopez on 16/01/2018.
//

#ifndef R_TYPE_ALEVEL_H
#define R_TYPE_ALEVEL_H

#include <SFML/Graphics.hpp>
#include <Player.h>
#include <HUD.h>
#include <Bg.h>
#include <memory>
#include <cmath>

class ALevel
{
private:
    virtual void enemiesGenerator();

protected:
    Player *player;
    Hud &hud;
    Bg back;

    sf::Time invulnerabilityTime;
    sf::Music music;
    sf::Clock clock;
    sf::Clock inv;
    sf::Keyboard keyboard;

    std::vector<std::shared_ptr<IEntity>> bulletsEnemy;
    std::vector<std::shared_ptr<IEntity>> bulletsAllied;
    std::vector<std::shared_ptr<IEntity>> ennemies;

    float baseSoundAttenuationOnDeathPercentageDecreasing;
    float soundAttenuationOnDeath;
    bool isGameLost;
    short phase;
    bool changePhase;
    short phaseMax;
    GameState currentGameLevel;

    std::vector<std::function<void()>> phases;

    virtual void controller();

    virtual void XboxController();

    virtual void updateAlliedBullet();

    virtual void updateEntities();

    virtual void checkEntitiesBoxes();

    virtual void initLvl(const std::string &path);

    virtual void drawLvl(sf::RenderWindow &App);

    virtual void pollEvent(sf::Event &event);

    virtual void mainLoop();//std::function<void()>);

    virtual void generateEnemies(EnemyType, int, EnemyType, int);

public:

    ALevel();

    virtual ~ALevel();

    virtual void start() = 0;

    virtual void addBullet(IEntity *);

    virtual void drawAll(sf::RenderWindow &App);
};


#endif //R_TYPE_ALEVEL_H
