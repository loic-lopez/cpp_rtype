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
    this->background.flushLayers();
    orientation = Orientation::VERTICAL;
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
                this->background.addLayer(path, i);
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
    this->background.drawBackground(App);
}
