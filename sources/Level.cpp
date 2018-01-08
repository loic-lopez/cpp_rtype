//
// Created by Eric on 03/12/2017.
//

#include "Level.h"

Level::Level() {

}

Level::~Level() {
    music.stop();
    back.flushLayers();
}

void Level::changeOrientation(Orientation orientation)
{
    back.changeOrientation(orientation);
}

void Level::initLvl(const std::string &path)
{
    music.stop();
    back.flushLayers();
    orientation = Orientation::VERTICAL;
    std::ifstream infile("./ressources/" + path + "/" + path + ".csv");
    std::string line;
    if (std::getline(infile, line)) {
       music.openFromFile("./ressources/" + path + "/" + line.substr(0, line.find(',')));
       music.setLoop(true);
       music.play();
        while (std::getline(infile, line)) {
            std::string pathSprite = "./ressources/" + path + "/" + line.substr(0, line.find(','));
            line = line.substr(line.find(',') + 1);
            back.addLayer(pathSprite, std::stoi(line.substr(0, line.find(','))));
        }
    }
}

void Level::drawLvl(sf::RenderWindow &App)
{
    back.drawBackground(App);
}