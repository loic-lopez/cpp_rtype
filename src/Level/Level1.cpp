//
// Created by Pierre on 03/12/2017.
//

#include <Parsing.h>
#include <Enemy.h>
#include "Level/Level1.h"

Level1::Level1() : ALevel() {
    initLvl("lvl1");
}

Level1::~Level1() {
    music.stop();
    back.flushLayers();
}

void Level1::start() {
    sf::Event Event;
    sf::Time elapsed;

    for (int i = 0; i < (std::rand() % 10 + 10); ++i) {
        entities.push_back(new Enemy(EnemyType::BASIC_A));
        entities.push_back(new Enemy(EnemyType::BASIC_A));
    }
    bulletsEnemy.reserve(100000);

    music.play();
    while (WindowProperties::App->isOpen() && WindowProperties::gameState == GameState::LEVEL1) {
        elapsed = clock.getElapsedTime();
        invulnerabilityTime = inv.getElapsedTime();
        if (elapsed.asMilliseconds() > 17) {
            clock.restart();
            if (player.getHp() != 0) {
                if (player.getGameMovementMode() == ControlType::KEYBOARD)
                    controller();
                else if (player.getGameMovementMode() == ControlType::XBOXCONTROLLER)
                    XboxController();
            } else {
                this->isGameLost = true;
                this->fadeOpacity = this->fadeOpacity + 1;
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