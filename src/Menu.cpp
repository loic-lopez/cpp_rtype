//
// Created by Zakelis on 09/01/2018.
//

#include "Menu.h"

Menu::Menu() : fader(0.1f, 0.1f),
               particleVelocity(200.0f, -90.0f)
{
    this->particleColorGradient[0.f] = sf::Color(0, 150, 0);
    this->particleColorGradient[0.5f] = sf::Color(0, 150, 100);
    this->particleColorGradient[1.f] = sf::Color(0, 0, 150);
    this->colorizer.
}

Menu::~Menu()
{

}

void Menu::initMenu(const std::string &path) {
    this->music.stop();
    bool parsedBackgroundTexture = false;
    bool parsedMouseParticleTexture = false;
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
            else if (!parsedMouseParticleTexture){
                this->mouseParticleTexture.loadFromFile(path);
                parsedMouseParticleTexture = true;
            }
            else {
                if (this->buttonEffectsPaths.size() == 3) {
                    std::cout << "Button number " << this->menuButtons.size() << " is beeing created." << std::endl;
                    Button *newButton = new Button(this->buttonEffectsPaths);
                    std::cout << "Button number " << this->menuButtons.size() << " correctly created." << std::endl;
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
    this->particleEmitter.setEmissionRate(30.0f);
    this->particleEmitter.setParticleLifetime(sf::seconds(5.0f));
    this->particleSystem.setTexture(this->mouseParticleTexture);
    this->particleSystem.addEmitter(this->particleEmitter);
    this->particleSystem.addAffector(thor::AnimationAffector(this->colorizer));
    this->particleSystem.addAffector(thor::AnimationAffector(this->fader));
    this->particleSystem.addAffector(thor::TorqueAffector(100.0f));
    this->particleSystem.addAffector(thor::ForceAffector(sf::Vector2f(0.0f, 100.0f)));

}


void Menu::drawMenu(sf::RenderWindow &App)
{
    App.draw(this->menuBackgroundSprite);
    for (int x = 0; x < this->menuButtons.size(); ++x) {
        App.draw(this->menuButtons[x]->buttonShape);
    }
    App.draw(this->particleSystem);
}

void Menu::updateMenu(sf::Event &e, sf::RenderWindow &window) {
    for (int i = 0; i < this->menuButtons.size(); ++i) {
        this->menuButtons[i]->update(e, window);
    }
    this->particleEmitter.setParticlePosition(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
    this->particleEmitter.setParticleVelocity(thor::Distributions::deflect(this->particleVelocity, 10.0f));
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

void Menu::modifyParticleVelocity(int delta) {
    this->particleVelocity.phi += 12.5f * delta;
}

