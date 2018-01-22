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
        // BOUTON OPTION
        this->optionsButtons[1]->setState(0);
    });
    this->functionsHandler.emplace_back([this]() {
        // BOUTON CREDITS
        this->optionsButtons[2]->setState(0);
    });
    this->functionsHandler.emplace_back([this]() {
        //BOUTON JOUER
        WindowProperties::gameState = GameState::LEVEL1;
        this->music.stop();
        this->optionsButtons[3]->setState(0);
    });
    this->functionsHandler.emplace_back([this]() {
        //BOUTON EXIT
        WindowProperties::gameState = GameState::CLOSE;
        this->music.stop();
        this->optionsButtons[4]->setState(0);
    });
}

OptionsHandler::~OptionsHandler() {
    this->music.stop();
}

void OptionsHandler::initOptions(const std::string &path) {
    this->music.stop();
    bool parsedBackgroundTexture = false;
    Parsing::loadCSV(path, [&, this](std::string const &path, int const &i) {
        if (path.substr(path.find_last_of('.') + 1) == "ogg") {
            this->music.openFromFile(path);
            this->music.setLoop(true);
        } else if (path.substr(path.find_last_of('.') + 1) == "png" ||
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
    float firstXPos =
            (float) WindowProperties::WIN_WIDTH - (float) (this->optionsButtons[0]->buttonShape.getSize().x * 1.25);
    float firstYPos = (float) WindowProperties::WIN_HEIGHT / 8;
    for (unsigned int x = 0; x < this->optionsButtons.size(); x++) {
        if (x == 4)
            this->optionsButtons[x]->buttonShape.setPosition((sf::Vector2f
                    (0, (float) WindowProperties::WIN_HEIGHT - this->optionsButtons[x]->buttonShape.getSize().y)));
        else
            this->optionsButtons[x]->buttonShape.setPosition((sf::Vector2f(firstXPos, firstYPos)));
    }
}

void OptionsHandler::stopMusic() {
    this->music.stop();
}

void OptionsHandler::startMusic() {
    this->music.play();
}