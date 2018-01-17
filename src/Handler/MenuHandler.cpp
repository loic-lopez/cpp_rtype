//
// Created by Zakelis on 09/01/2018.
//


#include <Handler/MenuHandler.h>

MenuHandler::MenuHandler() {
    this->functionsHandler.emplace_back([this]() {
        // BOUTON TITRE, AUCUNE ACTION LORSQUE CLIC
        this->menuButtons[0]->setState(0);
    });

    this->functionsHandler.emplace_back([this]() {
        // BOUTON OPTION
        this->menuButtons[1]->setState(0);
    });
    this->functionsHandler.emplace_back([this]() {
        // BOUTON CREDITS
        this->menuButtons[2]->setState(0);
    });
    this->functionsHandler.emplace_back([this]() {
        //BOUTON JOUER
        WindowProperties::gameState = GameState::LEVEL1;
        this->music.stop();
        this->menuButtons[3]->setState(0);
    });
    this->functionsHandler.emplace_back([this]() {
        //BOUTON EXIT
        WindowProperties::gameState = GameState::CLOSE;
        this->music.stop();
        this->menuButtons[4]->setState(0);
    });
}

MenuHandler::~MenuHandler() {
    this->music.stop();
}

void MenuHandler::initMenu(const std::string &path) {
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
                this->menuBackgroundSprite.setTexture(this->backgroundTexture);
                scaleX = (float) WindowProperties::WIN_WIDTH / this->menuBackgroundSprite.getGlobalBounds().width;
                scaleY = (float) WindowProperties::WIN_HEIGHT / this->menuBackgroundSprite.getGlobalBounds().height;
                this->menuBackgroundSprite.scale(scaleX, scaleY);
                this->menuBackgroundSprite.setPosition(0, 0);
                parsedBackgroundTexture = true;
            } else {
                if (this->buttonEffectsPaths.size() < 3) {
                    this->buttonEffectsPaths.push_back(path);
                    if (this->buttonEffectsPaths.size() == 3) {
                        this->menuButtons.emplace_back(new Button(this->buttonEffectsPaths));
                        this->buttonEffectsPaths.clear();
                    }
                }
            }
        }

    });
    this->determineButtonsPosition();
    for (int j = 0; j < menuButtons.size(); j++)
        this->menuButtons.at(j)->onClick = this->functionsHandler.at(j);
}


void MenuHandler::drawMenu(sf::RenderWindow &App) {
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
    float firstXPos =
            (float) WindowProperties::WIN_WIDTH - (float) (this->menuButtons[0]->buttonShape.getSize().x * 1.25);
    float firstXPosPlayButton = firstXPos;
    float firstYPos = (float) WindowProperties::WIN_HEIGHT / 8;
    float firstYPosPlayButton = firstYPos;
    for (unsigned int x = 0; x < this->menuButtons.size(); x++) {
        if (x != 0) {
            firstXPos += this->menuButtons[x - 1]->buttonShape.getSize().x / 10;
            firstXPosPlayButton -= this->menuButtons[x - 1]->buttonShape.getSize().x / 8;
            firstYPos += this->menuButtons[x - 1]->buttonShape.getSize().y * 1.25;
            firstYPosPlayButton += this->menuButtons[x - 1]->buttonShape.getSize().y * 1.25;
        }
        if (x == 3)
            this->menuButtons[x]->buttonShape.setPosition((sf::Vector2f
                    ((float) WindowProperties::WIN_WIDTH - this->menuButtons[x]->buttonShape.getSize().x,
                     (float) WindowProperties::WIN_HEIGHT - this->menuButtons[x]->buttonShape.getSize().y)));
        else if (x == 4)
            this->menuButtons[x]->buttonShape.setPosition((sf::Vector2f
                    (0, (float) WindowProperties::WIN_HEIGHT - this->menuButtons[x]->buttonShape.getSize().y)));
        else
            this->menuButtons[x]->buttonShape.setPosition((sf::Vector2f(firstXPos, firstYPos)));
    }
}

void MenuHandler::stopMusic() {
    this->music.stop();
}

void MenuHandler::startMusic() {
    this->music.play();
}
