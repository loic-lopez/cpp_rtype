//
// Created by Zakelis on 22/01/2018.
//

#include <Handler/OptionsHandler.h>

OptionsHandler::OptionsHandler() {
    this->functionsHandler.emplace_back([this]() {
        // BOUTON TITRE, AUCUNE ACTION LORSQUE CLIC
        this->optionsButtons[0]->setState(0);
    });

    this->functionsHandler.emplace_back([this]() {
        // BOUTON HARMLESS
        WindowProperties::difficulty = Difficulty::HARMLESS;
        WindowProperties::MAX_PLAYER_HP = 5;
        this->optionsButtons[1]->setState(0);
    });
    this->functionsHandler.emplace_back([this]() {
        // BOUTON SADISTIC
        WindowProperties::difficulty = Difficulty::SADISTIC;
        WindowProperties::MAX_PLAYER_HP = 4;
        this->optionsButtons[2]->setState(0);
    });
    this->functionsHandler.emplace_back([this]() {
        //BOUTON MERCILESS
        WindowProperties::difficulty = Difficulty::MERCILESS;
        WindowProperties::MAX_PLAYER_HP = 3;
        this->optionsButtons[3]->setState(0);
    });
    this->functionsHandler.emplace_back([this]() {
        //BOUTON EXIT
        WindowProperties::gameState = GameState::MENU;
        this->optionsButtons[4]->setState(0);
    });
}

OptionsHandler::~OptionsHandler() {
}

void OptionsHandler::initOptions(const std::string &path) {
    bool parsedBackgroundTexture = false;
    Parsing::loadCSV(path, [&, this](std::string const &path, int const &i) {
        if (path.substr(path.find_last_of('.') + 1) == "png" ||
                   path.substr(path.find_last_of('.') + 1) == "jpg") {
            if (!parsedBackgroundTexture) {
                float scaleX;
                float scaleY;
                this->backgroundTexture.loadFromFile(path);
                this->optionsBackgroundSprite.setTexture(this->backgroundTexture);
                scaleX = (float) WindowProperties::WIN_WIDTH / this->optionsBackgroundSprite.getGlobalBounds().width;
                scaleY = (float) WindowProperties::WIN_HEIGHT / this->optionsBackgroundSprite.getGlobalBounds().height;
                this->optionsBackgroundSprite.scale(scaleX, scaleY);
                this->optionsBackgroundSprite.setPosition(0, 0);
                parsedBackgroundTexture = true;
            } else {
                if (this->buttonEffectsPaths.size() < 3) {
                    this->buttonEffectsPaths.push_back(path);
                    if (this->buttonEffectsPaths.size() == 3) {
                        this->optionsButtons.emplace_back(new Button(this->buttonEffectsPaths));
                        this->buttonEffectsPaths.clear();
                    }
                }
            }
        }

    });
    this->determineButtonsPosition();
    for (int j = 0; j < optionsButtons.size(); j++)
        this->optionsButtons.at(j)->onClick = this->functionsHandler.at(j);
}


void OptionsHandler::drawOptions(sf::RenderWindow &App) {
    App.draw(this->optionsBackgroundSprite);
    for (auto &menuButton : this->optionsButtons) {
        App.draw(menuButton->buttonShape);
    }
}

void OptionsHandler::updateOptions(sf::Event &e, sf::RenderWindow &window) {
    for (auto &menuButton : this->optionsButtons) {
        menuButton->update(e, window);
    }
}

void OptionsHandler::determineButtonsPosition() {
    float firstYPos = (float) WindowProperties::WIN_HEIGHT / 8;
    for (unsigned int x = 0; x < this->optionsButtons.size(); x++) {
        if (x == 4)
            this->optionsButtons[x]->buttonShape.setPosition((sf::Vector2f
                    (0, (float) WindowProperties::WIN_HEIGHT - this->optionsButtons[x]->buttonShape.getSize().y)));
        else
        {
            this->optionsButtons[x]->buttonShape.setPosition(WindowProperties::WIN_WIDTH / 2 - (this->optionsButtons[x]->buttonShape.getSize().x / 2), firstYPos);
            firstYPos += this->optionsButtons[x]->buttonShape.getSize().y * 1.25f;
        }
    }
}

void OptionsHandler::stopMusic() {
}

void OptionsHandler::startMusic() {
}