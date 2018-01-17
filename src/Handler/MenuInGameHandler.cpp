//
// Created by loic lopez on 17/01/2018.
//

#include <iostream>
#include <Static/WindowProperties.h>
#include "Handler/MenuInGameHandler.h"

MenuInGameHandler::MenuInGameHandler()
{
    this->functionsHandler.emplace_back([this]() {
        //BOUTON RETRY
        WindowProperties::gameState = GameState::LEVEL1;
        std::cout << "TO LEVEL 1" << std::endl;
        this->gameOverButtons[0]->setState(0);
    });
    this->functionsHandler.emplace_back([this]() {
        //BOUTON TO MENU
        WindowProperties::gameState = GameState::MENU;
        this->music.stop();
        this->gameOverButtons[1]->setState(0);
    });
    this->functionsHandler.emplace_back([this]() {
        //BOUTON EXIT
        WindowProperties::gameState = GameState::CLOSE;
        this->music.stop();
        this->gameOverButtons[2]->setState(0);

    });
}
}

MenuInGameHandler::~MenuInGameHandler()
{

}

void MenuInGameHandler::initMenuInGameHandler(const std::string &path)
{

}

void MenuInGameHandler::drawMenuInGame(sf::RenderWindow &App)
{

}

void MenuInGameHandler::updateMenuInGame(sf::Event &e, sf::RenderWindow &window)
{

}

void MenuInGameHandler::determineButtonsPosition()
{

}
