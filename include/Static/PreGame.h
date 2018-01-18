//
// Created by Zakelis on 16/01/2018.
//

#ifndef R_TYPE_PREGAME_H
#define R_TYPE_PREGAME_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include <SFML/Audio/Music.hpp>
#include "static_constructor.h"
#include "WindowProperties.h"

class PreGame
{

private:
    //LEVEL 1
    static          sf::Texture     preGameLevel1BackgroundTexture;
    static          sf::Sprite      preGameLevel1BackgroundSprite;
    static          sf::Texture     preGameLevel1TextTexture;
    static          sf::Sprite      preGameLevel1TextSprite;
    static          sf::Music       preGameLevel1Music;

    //LEVEL 2
    static          sf::Texture     preGameLevel2BackgroundTexture;
    static          sf::Sprite      preGameLevel2BackgroundSprite;
    static          sf::Texture     preGameLevel2TextTexture;
    static          sf::Sprite      preGameLevel2TextSprite;
    static          sf::Music       preGameLevel2Music;

    //LEVEL 3
    static          sf::Texture     preGameLevel3BackgroundTexture;
    static          sf::Sprite      preGameLevel3BackgroundSprite;
    static          sf::Texture     preGameLevel3TextTexture;
    static          sf::Sprite      preGameLevel3TextSprite;
    static          sf::Music       preGameLevel3Music;

    //LEVEL 4
    static          sf::Texture     preGameLevel4BackgroundTexture;
    static          sf::Sprite      preGameLevel4BackgroundSprite;
    static          sf::Texture     preGameLevel4TextTexture;
    static          sf::Sprite      preGameLevel4TextSprite;
    static          sf::Music       preGameLevel4Music;

    //INV FADING VARIABLES
    static          float           baseFadeOpacityPercentageDecreasing;
    static          float           floatFadeOpacity;
    static          int             fadeOpacity;

    static void PreGameLoadForLevel1()
    {
        (void)static_constructor<&PreGame::PreGameLoadForLevel1>::c;
        preGameLevel1BackgroundTexture.loadFromFile("");
        preGameLevel1BackgroundSprite.setTexture(preGameLevel1BackgroundTexture);
        preGameLevel1TextTexture.loadFromFile("");
        preGameLevel1TextSprite.setTexture(preGameLevel1TextTexture);
        preGameLevel1Music.openFromFile("./ressources/preGame/round_1_sound.ogg");
        baseFadeOpacityPercentageDecreasing = 1.25;
        floatFadeOpacity = 255;
        fadeOpacity = 255;
    }

    static void PreGameLoadForLevel2()
    {
        (void)static_constructor<&PreGame::PreGameLoadForLevel2>::c;
        preGameLevel2BackgroundTexture.loadFromFile("");
        preGameLevel2BackgroundSprite.setTexture(preGameLevel2BackgroundTexture);
        preGameLevel2TextTexture.loadFromFile("");
        preGameLevel2TextSprite.setTexture(preGameLevel2TextTexture);
        preGameLevel2Music.openFromFile("./ressources/preGame/round_2_sound.ogg");
        baseFadeOpacityPercentageDecreasing = 1.25;
        floatFadeOpacity = 255;
        fadeOpacity = 255;
    }

    static void PreGameLoadForLevel3()
    {
        (void)static_constructor<&PreGame::PreGameLoadForLevel3>::c;
        preGameLevel3BackgroundTexture.loadFromFile("");
        preGameLevel3BackgroundSprite.setTexture(preGameLevel3BackgroundTexture);
        preGameLevel3TextTexture.loadFromFile("");
        preGameLevel3TextSprite.setTexture(preGameLevel3TextTexture);
        preGameLevel3Music.openFromFile("./ressources/preGame/round_3_sound.ogg");
        baseFadeOpacityPercentageDecreasing = 1.25;
        floatFadeOpacity = 355;
        fadeOpacity = 355;
    }

    static void PreGameLoadForLevel4()
    {
        (void)static_constructor<&PreGame::PreGameLoadForLevel4>::c;
        preGameLevel4BackgroundTexture.loadFromFile("");
        preGameLevel4BackgroundSprite.setTexture(preGameLevel4BackgroundTexture);
        preGameLevel4TextTexture.loadFromFile("");
        preGameLevel4TextSprite.setTexture(preGameLevel4TextTexture);
        preGameLevel4Music.openFromFile("./ressources/preGame/round_4_sound.ogg");
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
