//
// Created by Zakelis on 16/01/2018.
//

#include <Handler/GameOverScreenHandler.h>

GameOverScreenHandler::GameOverScreenHandler() {
    this->functionsHandler.emplace_back([this]() {
        //BOUTON CONTINUE
        WindowProperties::gameState = GameState::LEVEL1;
        this->music.stop();
    });
    this->functionsHandler.emplace_back([this]() {
        //BOUTON TO MENU
        WindowProperties::gameState = GameState::MENU;
        this->music.stop();
    });
    this->functionsHandler.emplace_back([this]() {
        //BOUTON EXIT
        WindowProperties::gameState = GameState::CLOSE;
        this->music.stop();
    });
}

GameOverScreenHandler::~GameOverScreenHandler() {
    this->music.stop();
}

void GameOverScreenHandler::initGameOverScreen(const std::string &path) {
    this->music.stop();
    bool parsedBackgroundTexture = false;
    bool parsedTextTexture = false;
    Parsing::loadCSV(path, [&, this](std::string const &path, int const &i) {
        if (path.substr(path.find_last_of('.') + 1) == "ogg") {
            this->music.openFromFile(path);
            this->music.setLoop(true);
            this->music.play();
        } else if (path.substr(path.find_last_of('.') + 1) == "png" ||
                   path.substr(path.find_last_of('.') + 1) == "jpg") {
            if (!parsedBackgroundTexture) {
                float scaleX;
                float scaleY;
                this->backgroundTexture.loadFromFile(path);
                this->backgroundSprite.setTexture(this->backgroundTexture);
                scaleX = (float) WindowProperties::WIN_WIDTH / this->backgroundSprite.getGlobalBounds().width;
                scaleY = (float) WindowProperties::WIN_HEIGHT / this->backgroundSprite.getGlobalBounds().height;
                this->backgroundSprite.scale(scaleX, scaleY);
                this->backgroundSprite.setPosition(0, 0);
                parsedBackgroundTexture = true;
            } else if (parsedBackgroundTexture && !parsedTextTexture) {
                this->textTexture.loadFromFile(path);
                this->textSprite.setTexture(this->textTexture);
                this->textSprite.setPosition(WindowProperties::WIN_WIDTH / 2 - this->textSprite.getGlobalBounds().width,
                                             WindowProperties::WIN_HEIGHT / 4);
                parsedTextTexture = true;
            } else {
                if (this->buttonEffectsPaths.size() < 3) {
                    this->buttonEffectsPaths.push_back(path);
                    if (this->buttonEffectsPaths.size() == 3) {
                        Button *newButton = new Button(this->buttonEffectsPaths);
                        this->gameOverButtons.push_back(newButton);
                        this->buttonEffectsPaths.clear();
                    }
                }
            }
        }

    });
    this->determineButtonsPosition();
    for (int j = 0; j < gameOverButtons.size(); j++)
        this->gameOverButtons.at(j)->onClick = this->functionsHandler.at(j);
}

void GameOverScreenHandler::drawGameOverScreen(sf::RenderWindow &App) {
    App.draw(this->backgroundSprite);
    App.draw(this->textSprite);
    for (auto &gameOverButton : this->gameOverButtons) {
        App.draw(gameOverButton->buttonShape);
    }
}

void GameOverScreenHandler::updateGameOverScreen(sf::Event &e, sf::RenderWindow &window) {
    for (auto &gameOverButton : this->gameOverButtons) {
        gameOverButton->update(e, window);
    }
}

void GameOverScreenHandler::determineButtonsPosition() {

}

void GameOverScreenHandler::stopMusic() {
    this->music.stop();
}