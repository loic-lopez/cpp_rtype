//
// Created by Zakelis on 17/01/2018.
//

#include "Static/PreGame.h"

//LEVEL 1
sf::Texture     PreGame::preGameLevel1BackgroundTexture;
sf::Sprite      PreGame::preGameLevel1BackgroundSprite;
sf::Music       PreGame::preGameLevel1Music;

//LEVEL 2
sf::Texture     PreGame::preGameLevel2BackgroundTexture;
sf::Sprite      PreGame::preGameLevel2BackgroundSprite;
sf::Music       PreGame::preGameLevel2Music;

void            PreGame::startPreGameLevel1()
{
    sf::Clock clock;
    this->preGameLevel1Music.play();
    while (WindowProperties::App->isOpen() && WindowProperties::gameState == GameState::PREGAME_LEVEL1)
    {
        sf::Event event;
        while (WindowProperties::App->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                WindowProperties::gameState = GameState::CLOSE;
        }
        WindowProperties::App->display();

    }
    this->preGameLevel1Music.stop();
    WindowProperties::gameState = GameState::LEVEL1;
}