//
// Created by loic lopez on 17/01/2018.
//

#include <iostream>
#include <Static/WindowProperties.h>
#include <Parsing.h>
#include "Handler/MenuInGameHandler.h"

MenuInGameHandler::MenuInGameHandler()
{
    this->functionsHandler.emplace_back([this]()
                                        {
                                            //BOUTON RESUME
                                            WindowProperties::gameState = this->previousGameState;
                                            this->menuInGameButtons[0]->setState(0);
                                        });
    this->functionsHandler.emplace_back([this]()
                                        {
                                            //BOUTON TO MENU
                                            WindowProperties::gameState = GameState::MENU;
                                            this->menuInGameButtons[1]->setState(0);
                                        });
    this->functionsHandler.emplace_back([this]()
                                        {
                                            //BOUTON EXIT
                                            WindowProperties::gameState = GameState::CLOSE;
                                            this->menuInGameButtons[2]->setState(0);
                                        });
}

MenuInGameHandler::~MenuInGameHandler()
{

}

void MenuInGameHandler::initMenuInGameHandler(const std::string &path)
{
    Parsing::loadCSV(path, [&, this] (std::string const &path, int const &i)
    {
        if (path.substr(path.find_last_of('.') + 1) == "png" ||
            path.substr(path.find_last_of('.') + 1) == "jpg")
        {
            this->textTexture.loadFromFile(path);
            this->textSprite.setTexture(this->textTexture);
            this->textSprite.setPosition(
                    WindowProperties::WIN_WIDTH / 2 - (this->textSprite.getGlobalBounds().width / 2),
                    WindowProperties::WIN_HEIGHT / 4);
        }
        if (this->buttonEffectsPaths.size() < 3)
        {
            this->buttonEffectsPaths.push_back(path);
            if (this->buttonEffectsPaths.size() == 3)
            {
                this->menuInGameButtons.emplace_back(new Button(this->buttonEffectsPaths));
                this->buttonEffectsPaths.clear();
            }
        }
    }
    );
    this->determineButtonsPosition();
    for (int j = 0; j < menuInGameButtons.size(); j++)
        this->menuInGameButtons.at(j)->onClick = this->functionsHandler.at(j);
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

void MenuInGameHandler::setPreviousGameState(GameState previousGameState)
{
    MenuInGameHandler::previousGameState = previousGameState;
}
