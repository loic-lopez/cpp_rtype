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
                sf::Texture texture;
                float scaleX;
                float scaleY;
                texture.loadFromFile(path);
                this->menuBackgroundSprite.setTexture(texture);
                scaleX = (float) WindowProperties::WIN_WIDTH / this->menuBackgroundSprite.getGlobalBounds().width;
                scaleY = (float) WindowProperties::WIN_HEIGHT / this->menuBackgroundSprite.getGlobalBounds().height;
                this->menuBackgroundSprite.scale(scaleX, scaleY);
                this->menuBackgroundSprite.setPosition(0, 0);
                cpt = true;
            }
            else {
                std::cout << path << std::endl;
                this->hud.addLayer(path);
            }
        }
    });
}


void Menu::drawMenu(sf::RenderWindow &App)
{
    App.draw(this->menuBackgroundSprite);
    this->hud.drawHudMenu(App);
}
