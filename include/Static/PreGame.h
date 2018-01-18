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

class PreGame
{

private:
    //LEVEL 1
    static          std::shared_ptr<sf::Texture>     preGameLevel1BackgroundTexture;
    static          std::shared_ptr<sf::Sprite>      preGameLevel1BackgroundSprite;
    static          std::shared_ptr<sf::Texture>     preGameLevel1TextTexture;
    static          std::shared_ptr<sf::Sprite>      preGameLevel1TextSprite;
    static          std::shared_ptr<sf::Music>       preGameLevel1Music;

    //LEVEL 2
    static          sf::Texture     preGameLevel2BackgroundTexture;
    static          sf::Sprite      preGameLevel2BackgroundSprite;
    static          sf::Texture     preGameLevel2TextTexture;
    static          sf::Sprite      preGameLevel2TextSprite;
    static          std::shared_ptr<sf::Music>      preGameLevel2Music;

    //LEVEL 3
    static          sf::Texture     preGameLevel3BackgroundTexture;
    static          sf::Sprite      preGameLevel3BackgroundSprite;
    static          sf::Texture     preGameLevel3TextTexture;
    static          sf::Sprite      preGameLevel3TextSprite;
    static          std::shared_ptr<sf::Music>      preGameLevel3Music;

    //LEVEL 4
    static          sf::Texture     preGameLevel4BackgroundTexture;
    static          sf::Sprite      preGameLevel4BackgroundSprite;
    static          sf::Texture     preGameLevel4TextTexture;
    static          sf::Sprite      preGameLevel4TextSprite;
    static          std::shared_ptr<sf::Music>      preGameLevel4Music;

    //INV FADING VARIABLES
    static          float           baseFadeOpacityPercentageDecreasing;
    static          float           floatFadeOpacity;
    static          int             fadeOpacity;

    static void PreGameLoadForLevel1()
    {
        (void)static_constructor<&PreGame::PreGameLoadForLevel1>::c;
        preGameLevel1BackgroundTexture = std::shared_ptr<sf::Texture>(new sf::Texture());
        preGameLevel1BackgroundSprite = std::shared_ptr<sf::Sprite>(new sf::Sprite());
        preGameLevel1TextTexture = std::shared_ptr<sf::Texture>(new sf::Texture());
        preGameLevel1TextSprite = std::shared_ptr<sf::Sprite>(new sf::Sprite());
        preGameLevel1Music = std::shared_ptr<sf::Music>(new sf::Music());
        preGameLevel1BackgroundTexture->loadFromFile("./ressources/lvl1/lvl1-1.png");
        preGameLevel1BackgroundSprite->setTexture(*preGameLevel1BackgroundTexture);
        float scaleX = (float) WindowProperties::WIN_WIDTH / preGameLevel1BackgroundSprite->getGlobalBounds().width;
        float scaleY = (float) WindowProperties::WIN_HEIGHT / preGameLevel1BackgroundSprite->getGlobalBounds().height;
        preGameLevel1BackgroundSprite->scale(scaleX, scaleY);
        preGameLevel1BackgroundSprite->setRotation(90);
        preGameLevel1BackgroundSprite->setPosition(0, 0);
        preGameLevel1TextTexture->loadFromFile("./ressources/preGame/round_1_text.png");
        preGameLevel1TextSprite->setTexture(*preGameLevel1TextTexture);
        preGameLevel1BackgroundSprite->setPosition((WindowProperties::WIN_WIDTH / 2) - (preGameLevel1BackgroundSprite->getGlobalBounds().width / 2),
                                                  (WindowProperties::WIN_HEIGHT / 2) - (preGameLevel1BackgroundSprite->getGlobalBounds().height / 2));
        preGameLevel1Music->openFromFile("./ressources/preGame/round_1_sound.ogg");
        baseFadeOpacityPercentageDecreasing = 1.25;
        floatFadeOpacity = 255;
        fadeOpacity = 255;
    }

    static void PreGameLoadForLevel2()
    {
        (void)static_constructor<&PreGame::PreGameLoadForLevel2>::c;
        preGameLevel2BackgroundTexture.loadFromFile("./ressources/lvl2/lvl2-1.png");
        preGameLevel2BackgroundSprite.setTexture(preGameLevel2BackgroundTexture);
        preGameLevel2TextTexture.loadFromFile("./ressources/preGame/round_2_text.png");
        preGameLevel2TextSprite.setTexture(preGameLevel2TextTexture);
        preGameLevel2Music = std::shared_ptr<sf::Music>(new sf::Music());
        preGameLevel2Music->openFromFile("./ressources/preGame/round_2_sound.ogg");
        baseFadeOpacityPercentageDecreasing = 1.25;
        floatFadeOpacity = 255;
        fadeOpacity = 255;
    }

    static void PreGameLoadForLevel3()
    {
        (void)static_constructor<&PreGame::PreGameLoadForLevel3>::c;
        preGameLevel3BackgroundTexture.loadFromFile("./ressources/lvl3/lvl3-bg.png");
        preGameLevel3BackgroundSprite.setTexture(preGameLevel3BackgroundTexture);
        preGameLevel3TextTexture.loadFromFile("./ressources/preGame/round_3_text.png");
        preGameLevel3TextSprite.setTexture(preGameLevel3TextTexture);
        preGameLevel3Music = std::shared_ptr<sf::Music>(new sf::Music());
        preGameLevel3Music->openFromFile("./ressources/preGame/round_3_sound.ogg");
        baseFadeOpacityPercentageDecreasing = 1.25;
        floatFadeOpacity = 255;
        fadeOpacity = 255;
    }

    static void PreGameLoadForLevel4()
    {
        (void)static_constructor<&PreGame::PreGameLoadForLevel4>::c;
        preGameLevel4BackgroundTexture.loadFromFile("./ressources/lvl4/lvl4-bg.png");
        preGameLevel4BackgroundSprite.setTexture(preGameLevel4BackgroundTexture);
        preGameLevel4TextTexture.loadFromFile("./ressources/preGame/round_4_text.png");
        preGameLevel4TextSprite.setTexture(preGameLevel4TextTexture);
        preGameLevel4Music = std::shared_ptr<sf::Music>(new sf::Music());
        preGameLevel4Music->openFromFile("./ressources/preGame/round_4_sound.ogg");
        baseFadeOpacityPercentageDecreasing = 1.25;
        floatFadeOpacity = 255;
        fadeOpacity = 255;
    }


public:

    static void startPreGameLevel1();
    static void startPreGameLevel2();
    static void startPreGameLevel3();
    static void startPreGameLevel4();
};

#endif //R_TYPE_PREGAME_H
