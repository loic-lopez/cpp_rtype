//
// Created by Zakelis on 09/01/2018.
//

#include "MenuHandler.h"

MenuHandler::MenuHandler()
{
    this->functionsHandler.emplace_back([] () {
    // BOUTON TITRE, AUCUNE ACTION LORSQUE CLIC
    });

    this->functionsHandler.emplace_back([] () {
    // BOUTON OPTION
    });
    this->functionsHandler.emplace_back([] () {
    // BOUTON CREDITS
    });
    this->functionsHandler.emplace_back([] () {
        //BOUTON JOUER
        WindowProperties::gameState = GameState::GAME;
    });
}

MenuHandler::~MenuHandler()
{
    this->music.stop();
}

void MenuHandler::initMenu(const std::string &path) {
    this->music.stop();
    bool parsedBackgroundTexture = false;
    Parsing::loadCSV(path, [&, this] (std::string const &path, int const &i) {
        if (path.substr(path.find_last_of('.') + 1) == "ogg") {
            this->music.openFromFile(path);
            this->music.setLoop(true);
            this->music.play();
        }
        else if (path.substr(path.find_last_of('.') + 1) == "png" ||
                path.substr(path.find_last_of('.') + 1) == "jpg") {
            if (!parsedBackgroundTexture) {
                float scaleX;
                float scaleY;
                this->backgroundTexture.loadFromFile(path);
                this->menuBackgroundSprite.setTexture(this->backgroundTexture);
                scaleX = (float) WindowProperties::WIN_WIDTH / this->menuBackgroundSprite.getGlobalBounds().width;
                scaleY = (float) WindowProperties::WIN_HEIGHT / this->menuBackgroundSprite.getGlobalBounds().height;
                this->menuBackgroundSprite.scale(scaleX, scaleY);
                this->menuBackgroundSprite.setPosition(0, 0);
                parsedBackgroundTexture = true;
            }
            else {
                if (this->buttonEffectsPaths.size() < 3) {
                    std::cout << path << std::endl;
                    this->buttonEffectsPaths.push_back(path);
                    if (this->buttonEffectsPaths.size() == 3) {
                        std::cout << "Button number " << this->menuButtons.size() << " is beeing created." << std::endl;
                        Button *newButton = new Button(this->buttonEffectsPaths);
                        std::cout << "Button number " << this->menuButtons.size() << " correctly created." << std::endl;
                        this->menuButtons.push_back(newButton);
                        this->buttonEffectsPaths.clear();
                    }
                }
            }
        }

        for (int j = 0; j < menuButtons.size(); ++j)
            this->menuButtons.at(j)->onClick = this->functionsHandler.at(j);
    });
    this->determineButtonsPosition();

}


void MenuHandler::drawMenu(sf::RenderWindow &App)
{
    App.draw(this->menuBackgroundSprite);
    for (auto &menuButton : this->menuButtons) {
        App.draw(menuButton->buttonShape);
    }
}

void MenuHandler::updateMenu(sf::Event &e, sf::RenderWindow &window) {
    for (auto &menuButton : this->menuButtons) {
        menuButton->update(e, window);
    }
}

void MenuHandler::determineButtonsPosition() {
    float firstXPos = (float)WindowProperties::WIN_WIDTH - (float)(this->menuButtons[0]->buttonShape.getSize().x * 1.25);
    float firstXPosPlayButton = firstXPos;
    float firstYPos = (float)WindowProperties::WIN_HEIGHT / 8;
    float firstYPosPlayButton = firstYPos;
    std::cout << this->menuButtons.size() << std::endl;
    for (unsigned int x = 0; x < this->menuButtons.size(); x++)
    {
        if (x != 0) {
            firstXPos += this->menuButtons[x-1]->buttonShape.getSize().x / 10;
            firstXPosPlayButton -= this->menuButtons[x-1]->buttonShape.getSize().x / 8;
            firstYPos += this->menuButtons[x-1]->buttonShape.getSize().y * 1.25;
            firstYPosPlayButton += this->menuButtons[x-1]->buttonShape.getSize().y * 1.35;
        }
        if (x == 3)
            this->menuButtons[x]->buttonShape.setPosition((sf::Vector2f(firstXPosPlayButton, firstYPosPlayButton)));
        else
            this->menuButtons[x]->buttonShape.setPosition((sf::Vector2f(firstXPos, firstYPos)));
    }
}

