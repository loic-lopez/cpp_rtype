//
// Created by Zakelis on 22/01/2018.
//

#include <Handler/CreditsHandler.h>

CreditsHandler::CreditsHandler() {
    this->functionsHandler.emplace_back([this]() {
        // BOUTON TITRE, AUCUNE ACTION LORSQUE CLIC
        this->CreditsButtons[0]->setState(0);
    });
    this->functionsHandler.emplace_back([this]() {
        this->CreditsButtons[1]->setState(0);
    });
    this->functionsHandler.emplace_back([this]() {
        this->CreditsButtons[2]->setState(0);
    });
    this->functionsHandler.emplace_back([this]() {
        WindowProperties::gameState = GameState::MENU;
        this->CreditsButtons[3]->setState(0);
    });
}

CreditsHandler::~CreditsHandler() {
}

void CreditsHandler::initCredits(const std::string &path) {
    bool parsedBackgroundTexture = false;
    Parsing::loadCSV(path, [&, this](std::string const &path, int const &i) {
        if (path.substr(path.find_last_of('.') + 1) == "png" ||
                   path.substr(path.find_last_of('.') + 1) == "jpg") {
            if (!parsedBackgroundTexture) {
                float scaleX;
                float scaleY;
                this->backgroundTexture.loadFromFile(path);
                this->CreditsBackgroundSprite.setTexture(this->backgroundTexture);
                scaleX = (float) WindowProperties::WIN_WIDTH / this->CreditsBackgroundSprite.getGlobalBounds().width;
                scaleY = (float) WindowProperties::WIN_HEIGHT / this->CreditsBackgroundSprite.getGlobalBounds().height;
                this->CreditsBackgroundSprite.scale(scaleX, scaleY);
                this->CreditsBackgroundSprite.setPosition(0, 0);
                parsedBackgroundTexture = true;
            } else {
                if (this->buttonEffectsPaths.size() < 3) {
                    this->buttonEffectsPaths.push_back(path);
                    if (this->buttonEffectsPaths.size() == 3) {
                        this->CreditsButtons.emplace_back(new Button(this->buttonEffectsPaths));
                        this->buttonEffectsPaths.clear();
                    }
                }
            }
        }

    });
    this->determineButtonsPosition();
    for (int j = 0; j < CreditsButtons.size(); j++)
        this->CreditsButtons.at(j)->onClick = this->functionsHandler.at(j);
}


void CreditsHandler::drawCredits(sf::RenderWindow &App) {
    App.draw(this->CreditsBackgroundSprite);
    for (auto &menuButton : this->CreditsButtons) {
        App.draw(menuButton->buttonShape);
    }
}

void CreditsHandler::updateCredits(sf::Event &e, sf::RenderWindow &window) {
    for (auto &menuButton : this->CreditsButtons) {
        menuButton->update(e, window);
    }
}

void CreditsHandler::determineButtonsPosition() {
    float firstYPos = (float) WindowProperties::WIN_HEIGHT / 8;
    for (unsigned int x = 0; x < this->CreditsButtons.size(); x++) {
        if (x == 3)
            this->CreditsButtons[x]->buttonShape.setPosition((sf::Vector2f
                    (0, (float) WindowProperties::WIN_HEIGHT - this->CreditsButtons[x]->buttonShape.getSize().y)));
        else
        {
            this->CreditsButtons[x]->buttonShape.setPosition(WindowProperties::WIN_WIDTH / 2 - (this->CreditsButtons[x]->buttonShape.getSize().x / 2), firstYPos);
            firstYPos += this->CreditsButtons[x]->buttonShape.getSize().y * 1.25f;
        }
    }
}

void CreditsHandler::stopMusic() {
}

void CreditsHandler::startMusic() {
}