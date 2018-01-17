//
// Created by Loic Dupil on 17/01/2018.
//

#include <Parsing.h>
#include <Enemy.h>
#include <cmath>
#include "Level/Level2.h"

Level2::Level2() : ALevel()
{
    initLvl("lvl2");
}

Level2::~Level2()
{
    music.stop();
    back.flushLayers();
}

void    Level2::start()
{
    sf::Event Event;
    sf::Time elapsed;

    for (int i = 0; i < (std::rand() % 5 + 5); ++i)
        entities.push_back(std::shared_ptr<IEntity>(new Enemy(EnemyType::BASIC_A)));
    for (int i = 0; i < (std::rand() % 4 + 1); ++i)
        entities.push_back(std::shared_ptr<IEntity>(new Enemy(EnemyType::BASIC_B)));
    bulletsEnemy.reserve(100000);

    music.play();
    while (WindowProperties::App->isOpen() && WindowProperties::gameState == GameState::LEVEL2) {
        elapsed = clock.getElapsedTime();
        invulnerabilityTime = inv.getElapsedTime();
        if (elapsed.asMilliseconds() > 17) {
            clock.restart();
            if (player->getHp() != 0) {
                if (player->getGameMovementMode() == ControlType::KEYBOARD)
                    controller();
                else if (player->getGameMovementMode() == ControlType::XBOXCONTROLLER)
                    XboxController();
            } else {
                this->isGameLost = true;
                this->soundAttenuationOnDeath -= this->baseSoundAttenuationOnDeathPercentageDecreasing;
                this->music.setVolume(this->soundAttenuationOnDeath);
                this->floatFadeOpacity += this->baseFadeOpacityPercentageIncreasing;
                this->fadeOpacity = int(std::round(this->floatFadeOpacity));
                if (this->fadeOpacity >= 255)
                    WindowProperties::gameState = GameState::GAMEOVER;
                else
                    this->transitionToGameOverScreenSprite.setColor(sf::Color(255, 255, 255, this->fadeOpacity));
            }
            updateEntities();
            updateAlliedBullet();
            checkEntitiesBoxes();
            drawAll(*WindowProperties::App);
            pollEvent(Event);
            WindowProperties::App->display();
        }
    }
    music.stop();
}