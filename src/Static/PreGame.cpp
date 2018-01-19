//
// Created by Zakelis on 17/01/2018.
//

#include "Static/PreGame.h"
#include "Handler/GameHandler.h"

std::shared_ptr<sf::Texture>     PreGame::preGameLevel1TextTexture;
std::shared_ptr<sf::Sprite>      PreGame::preGameLevel1TextSprite;
std::shared_ptr<sf::Music>       PreGame::preGameLevel1Music;

std::shared_ptr<sf::Texture>     PreGame::preGameLevel2TextTexture;
std::shared_ptr<sf::Sprite>      PreGame::preGameLevel2TextSprite;
std::shared_ptr<sf::Music>       PreGame::preGameLevel2Music;

std::shared_ptr<sf::Texture>     PreGame::preGameLevel3TextTexture;
std::shared_ptr<sf::Sprite>      PreGame::preGameLevel3TextSprite;
std::shared_ptr<sf::Music>       PreGame::preGameLevel3Music;

std::shared_ptr<sf::Texture>     PreGame::preGameLevel4TextTexture;
std::shared_ptr<sf::Sprite>      PreGame::preGameLevel4TextSprite;
std::shared_ptr<sf::Music>       PreGame::preGameLevel4Music;

std::shared_ptr<sf::Texture>     PreGame::preGameLevel5TextTexture;
std::shared_ptr<sf::Sprite>      PreGame::preGameLevel5TextSprite;
std::shared_ptr<sf::Music>       PreGame::preGameLevel5Music;

void PreGame::startPreGameLevel1() {
    int     fadeOpacity = 0;
    bool    reverseFade = false;
    sf::Clock clock;
    sf::Time elapsed;
    while (WindowProperties::App->isOpen() && fadeOpacity != 1) {
        elapsed = clock.getElapsedTime();
        if (elapsed.asMilliseconds() > 17) {
            WindowProperties::App->display();
            clock.restart();
            sf::Event event;
            while (WindowProperties::App->pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    WindowProperties::gameState = GameState::CLOSE;
                }
            }
            if (fadeOpacity == 254) {
                reverseFade = true;
            }
            if (reverseFade) {
                fadeOpacity -= 11;
            }
            else {
                fadeOpacity += 2;
            }
            if (fadeOpacity == 50) {
                preGameLevel1Music->play();
            }
            else {
                preGameLevel1TextSprite->setColor(sf::Color(255, 255, 255, fadeOpacity));
            }
            GameHandler::Instance().getCurrentLevel()->drawAll(*WindowProperties::App);
            WindowProperties::App->draw(*preGameLevel1TextSprite);
        }
    }
    preGameLevel1Music->stop();
}

void PreGame::startPreGameLevel2() {
    int     fadeOpacity = 0;
    bool    reverseFade = false;
    sf::Clock clock;
    sf::Time elapsed;
    while (WindowProperties::App->isOpen() && fadeOpacity != 1) {
        elapsed = clock.getElapsedTime();
        if (elapsed.asMilliseconds() > 17) {
            WindowProperties::App->display();
            clock.restart();
            sf::Event event;
            while (WindowProperties::App->pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    WindowProperties::gameState = GameState::CLOSE;
                }
            }
            if (fadeOpacity == 254) {
                reverseFade = true;
            }
            if (reverseFade) {
                fadeOpacity -= 11;
            }
            else {
                fadeOpacity += 2;
            }
            if (fadeOpacity == 50) {
                preGameLevel2Music->play();
            }
            else {
                preGameLevel2TextSprite->setColor(sf::Color(255, 255, 255, fadeOpacity));
            }
            GameHandler::Instance().getCurrentLevel()->drawAll(*WindowProperties::App);
            WindowProperties::App->draw(*preGameLevel2TextSprite);
        }
    }
    preGameLevel2Music->stop();
}

void PreGame::startPreGameLevel3() {

    int     fadeOpacity = 0;
    bool    reverseFade = false;
    sf::Clock clock;
    sf::Time elapsed;
    while (WindowProperties::App->isOpen() && fadeOpacity != 1) {
        elapsed = clock.getElapsedTime();
        if (elapsed.asMilliseconds() > 17) {
            WindowProperties::App->display();
            clock.restart();
            sf::Event event;
            while (WindowProperties::App->pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    WindowProperties::gameState = GameState::CLOSE;
                }
            }
            if (fadeOpacity == 254) {
                reverseFade = true;
            }
            if (reverseFade) {
                fadeOpacity -= 11;
            }
            else {
                fadeOpacity += 2;
            }
            if (fadeOpacity == 50) {
                preGameLevel3Music->play();
            }
            else {
                preGameLevel3TextSprite->setColor(sf::Color(255, 255, 255, fadeOpacity));
            }
            GameHandler::Instance().getCurrentLevel()->drawAll(*WindowProperties::App);
            WindowProperties::App->draw(*preGameLevel3TextSprite);
        }
    }
    preGameLevel3Music->stop();
}

void PreGame::startPreGameLevel4() {

    int     fadeOpacity = 0;
    bool    reverseFade = false;
    sf::Clock clock;
    sf::Time elapsed;
    while (WindowProperties::App->isOpen() && fadeOpacity != 1) {
        elapsed = clock.getElapsedTime();
        if (elapsed.asMilliseconds() > 17) {
            WindowProperties::App->display();
            clock.restart();
            sf::Event event;
            while (WindowProperties::App->pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    WindowProperties::gameState = GameState::CLOSE;
                }
            }
            if (fadeOpacity == 254) {
                reverseFade = true;
            }
            if (reverseFade) {
                fadeOpacity -= 11;
            }
            else {
                fadeOpacity += 2;
            }
            if (fadeOpacity == 50) {
                preGameLevel4Music->play();
            }
            else {
                preGameLevel4TextSprite->setColor(sf::Color(255, 255, 255, fadeOpacity));
            }
            GameHandler::Instance().getCurrentLevel()->drawAll(*WindowProperties::App);
            WindowProperties::App->draw(*preGameLevel4TextSprite);
        }
    }
    preGameLevel4Music->stop();
}

void PreGame::startPreGameLevel5() {
    int     fadeOpacity = 0;
    bool    reverseFade = false;
    sf::Clock clock;
    sf::Time elapsed;
    while (WindowProperties::App->isOpen() && fadeOpacity != 1) {
        elapsed = clock.getElapsedTime();
        if (elapsed.asMilliseconds() > 17) {
            WindowProperties::App->display();
            clock.restart();
            sf::Event event;
            while (WindowProperties::App->pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    WindowProperties::gameState = GameState::CLOSE;
                }
            }
            if (fadeOpacity == 254) {
                reverseFade = true;
            }
            if (reverseFade) {
                fadeOpacity -= 11;
            }
            else {
                fadeOpacity += 2;
            }
            if (fadeOpacity == 50) {
                preGameLevel5Music->play();
            }
            else {
                preGameLevel5TextSprite->setColor(sf::Color(255, 255, 255, fadeOpacity));
            }
            GameHandler::Instance().getCurrentLevel()->drawAll(*WindowProperties::App);
            WindowProperties::App->draw(*preGameLevel5TextSprite);
        }
    }
    preGameLevel5Music->stop();
}

