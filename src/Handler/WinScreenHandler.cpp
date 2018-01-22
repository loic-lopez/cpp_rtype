//
// Created by Zakelis on 16/01/2018.
//

#include <Handler/WinScreenHandler.h>
#include <Core/WinScreenCore.h>
#include <Handler/GameHandler.h>

WinScreenHandler::WinScreenHandler() {
    this->functionsHandler.emplace_back([this]() {
        //BOUTON RETRY
        WindowProperties::gameState = GameState::LEVEL1;
        this->music.stop();
        this->winButtons[0]->setState(0);
    });
    this->functionsHandler.emplace_back([this]() {
        //BOUTON TO MENU
        WindowProperties::gameState = GameState::MENU;
        this->music.stop();
        this->winButtons[1]->setState(0);
    });
    this->functionsHandler.emplace_back([this]() {
        //BOUTON EXIT
        WindowProperties::gameState = GameState::CLOSE;
        this->music.stop();
        this->winButtons[2]->setState(0);

    });
}

WinScreenHandler::~WinScreenHandler() {
    this->music.stop();
}

void WinScreenHandler::initWinScreen(const std::string &path)
{
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
                        this->winButtons.emplace_back(new Button(this->buttonEffectsPaths));
                        this->buttonEffectsPaths.clear();
                    }
                }
            }
        }

    });
    this->determineButtonsPosition();
    for (int j = 0; j < winButtons.size(); j++)
        this->winButtons.at(j)->onClick = this->functionsHandler.at(j);
}

void WinScreenHandler::drawWinScreen(sf::RenderWindow &App) {
    background.drawBackground(App);
    App.draw(this->textSprite);
    for (auto &gameOverButton : this->winButtons) {
        App.draw(gameOverButton->buttonShape);
    }
}

void WinScreenHandler::updateWinScreen(sf::Event &e, sf::RenderWindow &window)
{
    for (auto &gameOverButton : this->winButtons) {
        gameOverButton->update(e, window);
    }
}

void WinScreenHandler::determineButtonsPosition() {
    float posX;
    float posY;

    for (int i = 0; i < this->winButtons.size(); ++i) {
        if (i == 0)
            posX = 0;
        else if (i != 1)
            posX = (WindowProperties::WIN_WIDTH / 2) - (this->winButtons[i]->getDimensions().x / 2);
        else
            posX = WindowProperties::WIN_WIDTH - this->winButtons[i]->getDimensions().x;
        posY = WindowProperties::WIN_HEIGHT - this->winButtons[i]->getDimensions().y;
        this->winButtons[i]->buttonShape.setPosition(sf::Vector2f(posX, posY));
    }
}

void WinScreenHandler::stopMusic() {
    this->music.stop();
}

void WinScreenHandler::playMusic() {
    this->music.play();
}

const Bg &WinScreenHandler::getBackground() const {
    return background;
}

void WinScreenHandler::drawWinScreen(sf::RenderWindow &App, int opacity)
{
    background.getLayers().at(0)->img.setColor(sf::Color(255, 255, 255, opacity));
    background.drawBackground(App);

    textSprite.setColor(sf::Color(255, 255, 255, opacity));
    App.draw(this->textSprite);

    for (auto &gameOverButton : this->winButtons) {
        gameOverButton->setButtonColor(sf::Color(255, 255, 255, opacity));
        App.draw(gameOverButton->buttonShape);
    }
}

