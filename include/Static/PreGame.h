//
// Created by Zakelis on 16/01/2018.
//

#ifndef R_TYPE_PREGAME_H
#define R_TYPE_PREGAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include "static_constructor.h"
#include "WindowProperties.h"

class PreGame
{
public:

    //LEVEL 1
    static          sf::Texture     preGameLevel1BackgroundTexture;
    static          sf::Sprite      preGameLevel1BackgroundSprite;
    static          sf::Music       preGameLevel1Music;

    //LEVEL 2
    static          sf::Texture     preGameLevel2BackgroundTexture;
    static          sf::Sprite      preGameLevel2BackgroundSprite;
    static          sf::Music       preGameLevel2Music;

    static void PreGameLoadForLevel1()
    {
        (void)static_constructor<&PreGame::PreGameLoadForLevel1>::c;
        preGameLevel1BackgroundTexture.loadFromFile("");
        preGameLevel1BackgroundSprite.setTexture(preGameLevel1BackgroundTexture);
        preGameLevel1Music.openFromFile("");
        preGameLevel1Music.setLoop(true);
    }

    static void PreGameLoadForLevel2()
    {
        (void)static_constructor<&PreGame::PreGameLoadForLevel2>::c;
        preGameLevel2BackgroundTexture.loadFromFile("");
        preGameLevel2BackgroundSprite.setTexture(preGameLevel2BackgroundTexture);
        preGameLevel2Music.openFromFile("");
        preGameLevel2Music.setLoop(true);
    }

    static void startPreGameLevel1();
};

#endif //R_TYPE_PREGAME_H
