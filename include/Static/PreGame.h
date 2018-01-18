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
    static          sf::Texture     preGameLevel1TextTexture;
    static          sf::Sprite      preGameLevel1TextSprite;
    static          std::shared_ptr<sf::Music>       preGameLevel1Music;

    //LEVEL 2
    static          sf::Texture     preGameLevel2TextTexture;
    static          sf::Sprite      preGameLevel2TextSprite;
    static          std::shared_ptr<sf::Music>      preGameLevel2Music;

    //LEVEL 3
    static          sf::Texture     preGameLevel3TextTexture;
    static          sf::Sprite      preGameLevel3TextSprite;
    static          std::shared_ptr<sf::Music>      preGameLevel3Music;

    //LEVEL 4
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

        preGameLevel1TextTexture.loadFromFile("./ressources/preGame/round_1_text.png");
        preGameLevel1TextSprite.setTexture(preGameLevel1TextTexture);
        preGameLevel1TextSprite.setPosition((WindowProperties::WIN_WIDTH / 2) - (preGameLevel1TextSprite.getGlobalBounds().width / 2),
                                                  (WindowProperties::WIN_HEIGHT / 2) - (preGameLevel1TextSprite.getGlobalBounds().height / 2));
        preGameLevel1Music = std::shared_ptr<sf::Music>(new sf::Music());
        preGameLevel1Music->openFromFile("./ressources/preGame/round_1_sound.ogg");
        baseFadeOpacityPercentageDecreasing = 1.25;
        floatFadeOpacity = 255;
        fadeOpacity = 255;
    }

    static void PreGameLoadForLevel2()
    {
        (void)static_constructor<&PreGame::PreGameLoadForLevel2>::c;

        preGameLevel2Music = std::shared_ptr<sf::Music>(new sf::Music());
        preGameLevel2Music->openFromFile("./ressources/preGame/round_2_sound.ogg");
        baseFadeOpacityPercentageDecreasing = 1.25;
        floatFadeOpacity = 255;
        fadeOpacity = 255;
    }

    static void PreGameLoadForLevel3()
    {
        (void)static_constructor<&PreGame::PreGameLoadForLevel3>::c;

        preGameLevel3Music = std::shared_ptr<sf::Music>(new sf::Music());
        preGameLevel3Music->openFromFile("./ressources/preGame/round_3_sound.ogg");
        baseFadeOpacityPercentageDecreasing = 1.25;
        floatFadeOpacity = 355;
        fadeOpacity = 355;
    }

    static void PreGameLoadForLevel4()
    {
        (void)static_constructor<&PreGame::PreGameLoadForLevel4>::c;

        preGameLevel4Music = std::shared_ptr<sf::Music>(new sf::Music());
        preGameLevel4Music->openFromFile("./ressources/preGame/round_4_sound.ogg");
        baseFadeOpacityPercentageDecreasing = 1.25;
        floatFadeOpacity = 455;
        fadeOpacity = 455;
    }


public:

    static void startPreGameLevel1();
    static void startPreGameLevel2();
    static void startPreGameLevel3();
    static void startPreGameLevel4();
};

#endif //R_TYPE_PREGAME_H
