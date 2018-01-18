//
// Created by Zakelis on 17/01/2018.
//

#include "Static/PreGame.h"
#include "Handler/GameHandler.h"

//LEVEL 1
std::shared_ptr<sf::Texture>     PreGame::preGameLevel1TextTexture;
std::shared_ptr<sf::Sprite>      PreGame::preGameLevel1TextSprite;
std::shared_ptr<sf::Music>       PreGame::preGameLevel1Music;

//LEVEL 2
sf::Texture     PreGame::preGameLevel2TextTexture;
sf::Sprite      PreGame::preGameLevel2TextSprite;
std::shared_ptr<sf::Music>       PreGame::preGameLevel2Music;

//LEVEL 3
sf::Texture     PreGame::preGameLevel3TextTexture;
sf::Sprite      PreGame::preGameLevel3TextSprite;
std::shared_ptr<sf::Music>       PreGame::preGameLevel3Music;

//LEVEL 4
sf::Texture     PreGame::preGameLevel4TextTexture;
sf::Sprite      PreGame::preGameLevel4TextSprite;
std::shared_ptr<sf::Music>       PreGame::preGameLevel4Music;

//FADING VARIABLES

void PreGame::startPreGameLevel1() {
    int     fadeOpacity = 0;
    bool    reverseFade = false;
    bool    fadeDone = false;
    sf::Clock clock;
    sf::Time elapsed;
    while (WindowProperties::App->isOpen() && fadeOpacity != 1) {
        elapsed = clock.getElapsedTime();
        if (elapsed.asMilliseconds() > 17) {
            clock.restart();
            sf::Event event;
            while (WindowProperties::App->pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    WindowProperties::gameState = GameState::CLOSE;
            }
            if (fadeOpacity == 254)
                reverseFade = true;
            if (reverseFade)
                fadeOpacity -= 11;
            else
                fadeOpacity += 2;
            if (fadeOpacity == 50) {
               preGameLevel1Music->play();
            }
            else {
                preGameLevel1TextSprite->setColor(sf::Color(255, 255, 255, fadeOpacity));
            }
            GameHandler::Instance().getCurrentLevel()->drawAll(*WindowProperties::App);
            WindowProperties::App->draw(*preGameLevel1TextSprite);
            WindowProperties::App->display();
        }
    }
    preGameLevel1Music->stop();
}

void PreGame::startPreGameLevel2() {
    float baseFadeOpacityPercentageDecreasing = 1.25;
    float floatFadeOpacity = 255;
    int fadeOpacity = 255;
    sf::Clock clock;
    sf::Time elapsed;
    preGameLevel1Music->play();
    while (WindowProperties::App->isOpen()) {
        elapsed = clock.getElapsedTime();
        if (elapsed.asMilliseconds() > 17) {
            clock.restart();
            sf::Event event;
            while (WindowProperties::App->pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    WindowProperties::gameState = GameState::CLOSE;
            }
            floatFadeOpacity -= baseFadeOpacityPercentageDecreasing;
            fadeOpacity = int(std::round(floatFadeOpacity));
            if (fadeOpacity <= 0)
                WindowProperties::gameState = GameState::LEVEL2;
            else {
                preGameLevel2TextSprite.setColor(sf::Color(255, 255, 255, fadeOpacity));
            }
            WindowProperties::App->draw(preGameLevel2TextSprite);
            WindowProperties::App->display();
        }
    }
    preGameLevel1Music->stop();
}

void PreGame::startPreGameLevel3() {
    float baseFadeOpacityPercentageDecreasing = 1.25;
    float floatFadeOpacity = 255;
    int fadeOpacity = 255;
    sf::Clock clock;
    sf::Time elapsed;
    preGameLevel1Music->play();
    while (WindowProperties::App->isOpen()) {
        elapsed = clock.getElapsedTime();
        if (elapsed.asMilliseconds() > 17) {
            clock.restart();
            sf::Event event;
            while (WindowProperties::App->pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    WindowProperties::gameState = GameState::CLOSE;
            }
            floatFadeOpacity -= baseFadeOpacityPercentageDecreasing;
            fadeOpacity = int(std::round(floatFadeOpacity));
            if (fadeOpacity <= 0)
                WindowProperties::gameState = GameState::LEVEL3;
            else {
                preGameLevel3TextSprite.setColor(sf::Color(255, 255, 255, fadeOpacity));
            }
            WindowProperties::App->draw(preGameLevel3TextSprite);
            WindowProperties::App->display();
        }
    }
    preGameLevel1Music->stop();
}

void PreGame::startPreGameLevel4() {
    float baseFadeOpacityPercentageDecreasing = 1.25;
    float floatFadeOpacity = 255;
    int fadeOpacity = 255;
    sf::Clock clock;
    sf::Time elapsed;
    preGameLevel1Music->play();
    while (WindowProperties::App->isOpen()) {
        elapsed = clock.getElapsedTime();
        if (elapsed.asMilliseconds() > 17) {
            clock.restart();
            sf::Event event;
            while (WindowProperties::App->pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    WindowProperties::gameState = GameState::CLOSE;
            }
            floatFadeOpacity -= baseFadeOpacityPercentageDecreasing;
            fadeOpacity = int(std::round(floatFadeOpacity));
            if (fadeOpacity <= 0)
                WindowProperties::gameState = GameState::LEVEL4;
            else {
                preGameLevel4TextSprite.setColor(sf::Color(255, 255, 255, fadeOpacity));
            }
            WindowProperties::App->draw(preGameLevel4TextSprite);
            WindowProperties::App->display();
        }
    }
    preGameLevel1Music->stop();
}

