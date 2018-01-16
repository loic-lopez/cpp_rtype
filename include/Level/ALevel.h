//
// Created by loic lopez on 16/01/2018.
//

#ifndef R_TYPE_ALEVEL_H
#define R_TYPE_ALEVEL_H

#include <SFML/Graphics.hpp>
#include <Player.h>
#include <HUD.h>
#include <Bg.h>

class ALevel
{
protected:
    Player &player;
    Hud    &hud;
    Bg back;

    sf::Time   invulnerabilityTime;
    sf::Music music;
    sf::Clock clock;
    sf::Clock inv;
    sf::Keyboard keyboard;

    std::vector<IEntity *> bulletsEnemy;
    std::vector<IEntity *> bulletsAllied;
    std::vector<IEntity *> entities;

    sf::Texture     transitionToGameOverScreenTexture;
    sf::Sprite      transitionToGameOverScreenSprite;
    int             fadeOpacity;
    bool            isGameLost;

    virtual void controller();
    virtual void XboxController();

    virtual void drawAll(sf::RenderWindow &App);
    virtual void updateAlliedBullet();
    virtual void updateEntities();

    virtual void checkEntitiesBoxes();

    virtual void initLvl(const std::string &path);
    virtual void drawLvl(sf::RenderWindow &App);
    virtual void pollEvent(sf::Event &event);

public:
    ALevel();

    virtual ~ALevel();

    virtual void start() = 0;
    virtual void addBullet(IEntity *);
};


#endif //R_TYPE_ALEVEL_H
