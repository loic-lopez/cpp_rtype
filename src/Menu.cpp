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
    int vector_size = 0;
    Parsing::loadCSV(path, [&, this] (std::string const &path, int const &i) {
        if (path.substr(path.find_last_of('.') + 1) == "ogg") {
            this->music.openFromFile(path);
            this->music.setLoop(true);
            this->music.play();
        }
        else if (path.substr(path.find_last_of('.') + 1) == "png" ||
                path.substr(path.find_last_of('.') + 1) == "jpg") {
            if (!cpt) {
                float scaleX;
                float scaleY;
                backgroundTexture.loadFromFile(path);
                std::cout << path << std::endl;
                this->menuBackgroundSprite.setTexture(backgroundTexture);
                scaleX = (float) WindowProperties::WIN_WIDTH / this->menuBackgroundSprite.getGlobalBounds().width;
                scaleY = (float) WindowProperties::WIN_HEIGHT / this->menuBackgroundSprite.getGlobalBounds().height;
                this->menuBackgroundSprite.scale(scaleX, scaleY);
                this->menuBackgroundSprite.setPosition(0, 0);
                cpt = true;
            }
            else {
                if (vector_size == 2) {
                    this->button_effects_paths.clear();
                    vector_size = 0;
                }
                else {
                    std::cout << path << std::endl;
                    this->button_effects_paths.push_back(path);
                    vector_size++;
                }
            }
        }
    });
}


void Menu::drawMenu(sf::RenderWindow &App)
{
    App.draw(this->menuBackgroundSprite);
    for (int x = 0; x < this->menu_buttons; ++x) {
        App.draw(this->menu_buttons[x]);
    }
}
