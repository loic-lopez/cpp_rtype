//
// Created by Zakelis on 16/01/2018.
//

#include <Handler/GameOverScreenHandler.h>

GameOverScreenHandler::GameOverScreenHandler() {
    this->functionsHandler.emplace_back([this]() {
        //BOUTON RETRY
        WindowProperties::gameState = GameState::LEVEL1;
        std::cout << "TO LEVEL 1" << std::endl;
        this->music.stop();
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
        } else if (path.substr(path.find_last_of('.') + 1) == "png" ||
                   path.substr(path.find_last_of('.') + 1) == "jpg") {
            if (!parsedBackgroundTexture) {
                background.addLayer(path, i);
                parsedBackgroundTexture = true;

            } else if (parsedBackgroundTexture && !parsedTextTexture) {
                this->textTexture.loadFromFile(path);
                this->textSprite.setTexture(this->textTexture);
                this->textSprite.setPosition(
                        WindowProperties::WIN_WIDTH / 2 - (this->textSprite.getGlobalBounds().width / 2),
                        WindowProperties::WIN_HEIGHT / 4);
                parsedTextTexture = true;
            } else {
                if (this->buttonEffectsPaths.size() < 3) {
                    this->buttonEffectsPaths.push_back(path);
                    if (this->buttonEffectsPaths.size() == 3) {
                        this->gameOverButtons.emplace_back(new Button(this->buttonEffectsPaths));
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
    background.drawBackground(App);
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
    float posX;
    float posY;

    for (int i = 0; i < this->gameOverButtons.size(); ++i) {
        if (i == 0)
            posX = 0;
        else if (i != 1)
            posX = (WindowProperties::WIN_WIDTH / 2) - (this->gameOverButtons[i]->getDimensions().x / 2);
        else
            posX = WindowProperties::WIN_WIDTH - this->gameOverButtons[i]->getDimensions().x;
        posY = WindowProperties::WIN_HEIGHT - this->gameOverButtons[i]->getDimensions().y;
        this->gameOverButtons[i]->buttonShape.setPosition(sf::Vector2f(posX, posY));
    }
}

void GameOverScreenHandler::stopMusic() {
    this->music.stop();
}

void GameOverScreenHandler::playMusic() {
    this->music.play();
}

const Bg &GameOverScreenHandler::getBackground() const {
    return background;
}

void GameOverScreenHandler::drawGameOverScreen(sf::RenderWindow &App, int opacity)
{
    background.getLayers().at(0)->img.setColor(sf::Color(255, 255, 255, opacity));
    background.drawBackground(App);

    textSprite.setColor(sf::Color(255, 255, 255, opacity));
    App.draw(this->textSprite);

    for (auto &gameOverButton : this->gameOverButtons) {
        gameOverButton->setButtonColor(sf::Color(255, 255, 255, opacity));
        App.draw(gameOverButton->buttonShape);
    }
}

