//
// Created by Zakelis on 09/01/2018.
//

#include "Menu.h"

Menu::Menu()
{

}

Menu::~Menu()
{

}

void Menu::initMenu(const std::string &path) {
    this->music.stop();
    bool cpt = false;
    Parsing::loadCSV(path, [&, this] (std::string const &path, int const &i) {
        if (path.substr(path.find_last_of('.') + 1) == "ogg") {
            this->music.openFromFile(path);
            this->music.setLoop(true);
            this->music.play();
        }
        else if (path.substr(path.find_last_of('.') + 1) == "png" ||
                path.substr(path.find_last_of('.') + 1) == "jpg") {
            if (!cpt) {
                float scaleX;
                float scaleY;
                backgroundTexture.loadFromFile(path);
                std::cout << path << std::endl;
                this->menuBackgroundSprite.setTexture(backgroundTexture);
                scaleX = (float) WindowProperties::WIN_WIDTH / this->menuBackgroundSprite.getGlobalBounds().width;
                scaleY = (float) WindowProperties::WIN_HEIGHT / this->menuBackgroundSprite.getGlobalBounds().height;
                this->menuBackgroundSprite.scale(scaleX, scaleY);
                this->menuBackgroundSprite.setPosition(0, 0);
                cpt = true;
            }
            else {
                if (this->buttonEffectsPaths.size() == 3) {
                    Button *newButton = new Button(this->buttonEffectsPaths);
                    std::cout << "Button correctly created." << std::endl;
                    this->menuButtons.push_back(newButton);
                    this->buttonEffectsPaths.clear();
                }
                if (this->buttonEffectsPaths.size() < 3) {
                    std::cout << path << std::endl;
                    this->buttonEffectsPaths.push_back(path);
                }
            }
        }
    });
    this->determineButtonsPosition();
}


void Menu::drawMenu(sf::RenderWindow &App)
{
    App.draw(this->menuBackgroundSprite);
    for (int x = 0; x < this->menuButtons.size(); ++x) {
        App.draw(this->menuButtons[x]->buttonShape);
    }
}

void Menu::updateMenuButtons(sf::Event &e, sf::RenderWindow &window) {
    for (int i = 0; i < this->menuButtons.size(); ++i) {
        this->menuButtons[i]->update(e, window);
    }
}

void Menu::determineButtonsPosition() {
    float firstXPos = (float)WindowProperties::WIN_WIDTH - (float)(this->menuButtons[0]->buttonShape.getSize().x * 1.25);
    float firstXPosPlayButton = firstXPos;
    float firstYPos = (float)WindowProperties::WIN_HEIGHT / 8;
    float firstYPosPlayButton = firstYPos;
    std::cout << this->menuButtons.size() << std::endl;
    for (unsigned int x = 0; x < this->menuButtons.size(); x++)
    {
        if (x != 0) {
            firstXPos += this->menuButtons[0]->buttonShape.getSize().x / 10;
            firstXPosPlayButton -= this->menuButtons[0]->buttonShape.getSize().x / 8;
            firstYPos += this->menuButtons[0]->buttonShape.getSize().y * 1.35;
            firstYPosPlayButton += this->menuButtons[0]->buttonShape.getSize().y * 1.35;
        }
        if (x == 3)
            this->menuButtons[x]->buttonShape.setPosition((sf::Vector2f(firstXPosPlayButton, firstYPosPlayButton)));
        else
            this->menuButtons[x]->buttonShape.setPosition((sf::Vector2f(firstXPos, firstYPos)));
    }
}

