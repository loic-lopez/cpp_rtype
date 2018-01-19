//
// Created by Zakelis on 16/01/2018.
//

#ifndef R_TYPE_PREGAME_H
#define R_TYPE_PREGAME_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include <SFML/Audio/Music.hpp>
#include <memory>
#include "static_constructor.h"
#include "WindowProperties.h"

class PreGame {

private:
    static std::shared_ptr<sf::Texture> preGameLevel1TextTexture;
    static std::shared_ptr<sf::Sprite> preGameLevel1TextSprite;
    static std::shared_ptr<sf::Music> preGameLevel1Music;

    static std::shared_ptr<sf::Texture> preGameLevel2TextTexture;
    static std::shared_ptr<sf::Sprite> preGameLevel2TextSprite;
    static std::shared_ptr<sf::Music> preGameLevel2Music;

    static std::shared_ptr<sf::Texture> preGameLevel3TextTexture;
    static std::shared_ptr<sf::Sprite> preGameLevel3TextSprite;
    static std::shared_ptr<sf::Music> preGameLevel3Music;

    static std::shared_ptr<sf::Texture> preGameLevel4TextTexture;
    static std::shared_ptr<sf::Sprite> preGameLevel4TextSprite;
    static std::shared_ptr<sf::Music> preGameLevel4Music;

    static std::shared_ptr<sf::Texture> preGameLevel5TextTexture;
    static std::shared_ptr<sf::Sprite> preGameLevel5TextSprite;
    static std::shared_ptr<sf::Music> preGameLevel5Music;


    static void PreGameLoadForLevel1() {
        (void) static_constructor<&PreGame::PreGameLoadForLevel1>::c;
        preGameLevel1TextTexture = std::shared_ptr<sf::Texture>(new sf::Texture());
        preGameLevel1TextTexture->loadFromFile("./ressources/preGame/round_1_text.png");
        preGameLevel1TextSprite = std::shared_ptr<sf::Sprite>(new sf::Sprite());
        preGameLevel1TextSprite->setTexture(*preGameLevel1TextTexture);
        preGameLevel1TextSprite->setPosition(
                (WindowProperties::WIN_WIDTH / 2) - (preGameLevel1TextSprite->getGlobalBounds().width / 2),
                (WindowProperties::WIN_HEIGHT / 2) - (preGameLevel1TextSprite->getGlobalBounds().height / 2));
        preGameLevel1Music = std::shared_ptr<sf::Music>(new sf::Music());
        preGameLevel1Music->openFromFile("./ressources/preGame/round_1_sound.ogg");
    }

    static void PreGameLoadForLevel2() {
        (void) static_constructor<&PreGame::PreGameLoadForLevel2>::c;
        preGameLevel2TextTexture = std::shared_ptr<sf::Texture>(new sf::Texture());
        preGameLevel2TextTexture->loadFromFile("./ressources/preGame/round_2_text.png");
        preGameLevel2TextSprite = std::shared_ptr<sf::Sprite>(new sf::Sprite());
        preGameLevel2TextSprite->setTexture(*preGameLevel2TextTexture);
        preGameLevel2TextSprite->setPosition(
                (WindowProperties::WIN_WIDTH / 2) - (preGameLevel2TextSprite->getGlobalBounds().width / 2),
                (WindowProperties::WIN_HEIGHT / 2) - (preGameLevel2TextSprite->getGlobalBounds().height / 2));
        preGameLevel2Music = std::shared_ptr<sf::Music>(new sf::Music());
        preGameLevel2Music->openFromFile("./ressources/preGame/round_2_sound.ogg");
    }

    static void PreGameLoadForLevel3() {
        (void) static_constructor<&PreGame::PreGameLoadForLevel3>::c;
        preGameLevel3TextTexture = std::shared_ptr<sf::Texture>(new sf::Texture());
        preGameLevel3TextTexture->loadFromFile("./ressources/preGame/round_3_text.png");
        preGameLevel3TextSprite = std::shared_ptr<sf::Sprite>(new sf::Sprite());
        preGameLevel3TextSprite->setTexture(*preGameLevel3TextTexture);
        preGameLevel3TextSprite->setPosition(
                (WindowProperties::WIN_WIDTH / 2) - (preGameLevel3TextSprite->getGlobalBounds().width / 2),
                (WindowProperties::WIN_HEIGHT / 2) - (preGameLevel3TextSprite->getGlobalBounds().height / 2));
        preGameLevel3Music = std::shared_ptr<sf::Music>(new sf::Music());
        preGameLevel3Music->openFromFile("./ressources/preGame/round_3_sound.ogg");
    }

    static void PreGameLoadForLevel4() {
        (void) static_constructor<&PreGame::PreGameLoadForLevel4>::c;
        preGameLevel4TextTexture = std::shared_ptr<sf::Texture>(new sf::Texture());
        preGameLevel4TextTexture->loadFromFile("./ressources/preGame/round_4_text.png");
        preGameLevel4TextSprite = std::shared_ptr<sf::Sprite>(new sf::Sprite());
        preGameLevel4TextSprite->setTexture(*preGameLevel4TextTexture);
        preGameLevel4TextSprite->setPosition(
                (WindowProperties::WIN_WIDTH / 2) - (preGameLevel4TextSprite->getGlobalBounds().width / 2),
                (WindowProperties::WIN_HEIGHT / 2) - (preGameLevel4TextSprite->getGlobalBounds().height / 2));
        preGameLevel4Music = std::shared_ptr<sf::Music>(new sf::Music());
        preGameLevel4Music->openFromFile("./ressources/preGame/round_4_sound.ogg");
    }

    static void PreGameLoadForLevel5() {
        (void) static_constructor<&PreGame::PreGameLoadForLevel5>::c;
        preGameLevel5TextTexture = std::shared_ptr<sf::Texture>(new sf::Texture());
        preGameLevel5TextTexture->loadFromFile("./ressources/preGame/round_5_text.png");
        preGameLevel5TextSprite = std::shared_ptr<sf::Sprite>(new sf::Sprite());
        preGameLevel5TextSprite->setTexture(*preGameLevel5TextTexture);
        preGameLevel5TextSprite->setPosition(
                (WindowProperties::WIN_WIDTH / 2) - (preGameLevel5TextSprite->getGlobalBounds().width / 2),
                (WindowProperties::WIN_HEIGHT / 2) - (preGameLevel5TextSprite->getGlobalBounds().height / 2));
        preGameLevel5Music = std::shared_ptr<sf::Music>(new sf::Music());
        preGameLevel5Music->openFromFile("./ressources/preGame/round_5_sound.ogg");
    }

public:

    static void startPreGameLevel1();
    static void startPreGameLevel2();
    static void startPreGameLevel3();
    static void startPreGameLevel4();
    static void startPreGameLevel5();
};

#endif //R_TYPE_PREGAME_H
