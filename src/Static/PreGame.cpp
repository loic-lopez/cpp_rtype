//
// Created by Zakelis on 17/01/2018.
//

#include "Static/PreGame.h"

//LEVEL 1
sf::Texture     PreGame::preGameLevel1BackgroundTexture;
sf::Sprite      PreGame::preGameLevel1BackgroundSprite;
sf::Texture     preGameLevel1TextTexture;
sf::Sprite      preGameLevel1TextSprite;
sf::Music       PreGame::preGameLevel1Music;

//LEVEL 2
sf::Texture     PreGame::preGameLevel2BackgroundTexture;
sf::Sprite      PreGame::preGameLevel2BackgroundSprite;
sf::Texture     preGameLevel2TextTexture;
sf::Sprite      preGameLevel2TextSprite;
sf::Music       PreGame::preGameLevel2Music;

//LEVEL 3
sf::Texture     PreGame::preGameLevel3BackgroundTexture;
sf::Sprite      PreGame::preGameLevel3BackgroundSprite;
sf::Texture     preGameLevel3TextTexture;
sf::Sprite      preGameLevel3TextSprite;
sf::Music       PreGame::preGameLevel3Music;

//LEVEL 4
sf::Texture     PreGame::preGameLevel4BackgroundTexture;
sf::Sprite      PreGame::preGameLevel4BackgroundSprite;
sf::Texture     preGameLevel4TextTexture;
sf::Sprite      preGameLevel4TextSprite;
sf::Music       PreGame::preGameLevel4Music;

//FADING VARIABLES
float           baseFadeOpacityPercentageDecreasing;
float           floatFadeOpacity;
int             fadeOpacity;

void            PreGame::startPreGameLevel1()
{
    sf::Clock clock;
    preGameLevel1Music.play();
    while (WindowProperties::App->isOpen() && WindowProperties::gameState == GameState::PREGAME_LEVEL1)
    {
        sf::Event event;
        while (WindowProperties::App->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                WindowProperties::gameState = GameState::CLOSE;
        }
        floatFadeOpacity -= baseFadeOpacityPercentageDecreasing;
        fadeOpacity = int(std::round(floatFadeOpacity));
        if (fadeOpacity <= 0)
            WindowProperties::gameState = GameState::LEVEL1;
        else {
            preGameLevel1BackgroundSprite.setColor(sf::Color(255, 255, 255, fadeOpacity));
            preGameLevel1TextSprite.setColor(sf::Color(255, 255, 255, fadeOpacity));
        }
        WindowProperties::App->draw(preGameLevel1BackgroundSprite);
        WindowProperties::App->draw(preGameLevel1TextSprite);
        WindowProperties::App->display();

    }
    preGameLevel1Music.stop();
}

void PreGame::startPreGameLevel2() {
    sf::Clock clock;
    preGameLevel1Music.play();
    while (WindowProperties::App->isOpen() && WindowProperties::gameState == GameState::PREGAME_LEVEL2)
    {
        sf::Event event;
        while (WindowProperties::App->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                WindowProperties::gameState = GameState::CLOSE;
        }
        floatFadeOpacity -= baseFadeOpacityPercentageDecreasing;
        fadeOpacity = int(std::round(floatFadeOpacity));
        if (fadeOpacity <= 0)
            WindowProperties::gameState = GameState::LEVEL2;
        else {
            preGameLevel1BackgroundSprite.setColor(sf::Color(255, 255, 255, fadeOpacity));
            preGameLevel1TextSprite.setColor(sf::Color(255, 255, 255, fadeOpacity));
        }
        WindowProperties::App->draw(preGameLevel1BackgroundSprite);
        WindowProperties::App->draw(preGameLevel1TextSprite);
        WindowProperties::App->display();

    }
    preGameLevel1Music.stop();
}

void PreGame::startPreGameLevel3() {
    sf::Clock clock;
    preGameLevel1Music.play();
    while (WindowProperties::App->isOpen() && WindowProperties::gameState == GameState::PREGAME_LEVEL3)
    {
        sf::Event event;
        while (WindowProperties::App->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                WindowProperties::gameState = GameState::CLOSE;
        }
        floatFadeOpacity -= baseFadeOpacityPercentageDecreasing;
        fadeOpacity = int(std::round(floatFadeOpacity));
        if (fadeOpacity <= 0)
            WindowProperties::gameState = GameState::LEVEL3;
        else {
            preGameLevel1BackgroundSprite.setColor(sf::Color(255, 255, 255, fadeOpacity));
            preGameLevel1TextSprite.setColor(sf::Color(255, 255, 255, fadeOpacity));
        }
        WindowProperties::App->draw(preGameLevel1BackgroundSprite);
        WindowProperties::App->draw(preGameLevel1TextSprite);
        WindowProperties::App->display();

    }
    preGameLevel1Music.stop();
}

void PreGame::startPreGameLevel4() {
    sf::Clock clock;
    preGameLevel1Music.play();
    while (WindowProperties::App->isOpen() && WindowProperties::gameState == GameState::PREGAME_LEVEL4)
    {
        sf::Event event;
        while (WindowProperties::App->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                WindowProperties::gameState = GameState::CLOSE;
        }
        floatFadeOpacity -= baseFadeOpacityPercentageDecreasing;
        fadeOpacity = int(std::round(floatFadeOpacity));
        if (fadeOpacity <= 0)
            WindowProperties::gameState = GameState::LEVEL4;
        else {
            preGameLevel1BackgroundSprite.setColor(sf::Color(255, 255, 255, fadeOpacity));
            preGameLevel1TextSprite.setColor(sf::Color(255, 255, 255, fadeOpacity));
        }
        WindowProperties::App->draw(preGameLevel1BackgroundSprite);
        WindowProperties::App->draw(preGameLevel1TextSprite);
        WindowProperties::App->display();

    }
    preGameLevel1Music.stop();
}

