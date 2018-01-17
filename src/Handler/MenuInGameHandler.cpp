//
// Created by loic lopez on 17/01/2018.
//

#include <iostream>
#include <Static/WindowProperties.h>
#include <Parsing.h>
#include <Core/MenuInGameCore.h>
#include "Handler/MenuInGameHandler.h"

MenuInGameHandler::MenuInGameHandler()
{
    this->functionsHandler.emplace_back([this]()
                                        {
                                            //BOUTON RESUME
                                            WindowProperties::gameState = MenuInGameCore::Instance().getPreviousGameState();
                                            this->menuInGameButtons[0]->setState(0);
                                        });
    this->functionsHandler.emplace_back([this]()
                                        {
                                            //BOUTON SOUND

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
    Parsing::loadCSV(path, [&, this](std::string const &path, int const &i)
                     {
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
    for (auto &menuInGameButton : this->menuInGameButtons)
    {
        App.draw(menuInGameButton->buttonShape);
    }
}

void MenuInGameHandler::updateMenuInGame(sf::Event &e, sf::RenderWindow &window)
{
    for (auto &menuInGameButton : this->menuInGameButtons)
    {
        menuInGameButton->update(e, window);
    }
}

void MenuInGameHandler::determineButtonsPosition()
{
    float posY;
    int i = 0;

    for (auto &menuInGameButton : this->menuInGameButtons)
    {
        posY = (WindowProperties::WIN_HEIGHT - menuInGameButton->getDimensions().y) -
               (menuInGameButton->getDimensions().y * i);
        float posX = (WindowProperties::WIN_WIDTH / 2) - (menuInGameButton->getDimensions().x / 2);
        menuInGameButton->buttonShape.setPosition(sf::Vector2f(posX, posY));
        i++;
    }
}
