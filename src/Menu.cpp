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

void Menu::initMenu(const std::string &path_dir) {
    this->music.stop();
    this->background.flushLayers();
    this->hud.flushLayers()
    orientation = Orientation::VERTICAL;
    std::ifstream infile("./ressources/" + path_dir + "/" + path_dir + ".csv");
    std::string line;
    if (std::getline(infile, line)) {
        music.openFromFile("./ressources/" + path_dir + "/" + line.substr(0, line.find(',')));
        music.setLoop(true);
        music.play();
        if (std::getline(infile, line)) {
            std::string pathSprite = "./ressources/" + path_dir + "/" + line.substr(0, line.find(','));
            line = line.substr(line.find(',') + 1);
            this->background.addLayer(pathSprite, 0);
            int cpt = 0;
            while (std::getline(infile, line)) {
                std::string pathSprite = "./ressources/" + path_dir + "/" + line.substr(0, line.find(','));
                line = line.substr(line.find(',') + 1);
                this->hud.addLayerAlignedForMenu(pathSprite, 0, cpt);
                cpt++;
            }
        }
    }
}


void Menu::drawMenu(sf::RenderWindow &App)
{
    this->background.drawBackground(App);
    this->hud.drawHUD(App);
}
