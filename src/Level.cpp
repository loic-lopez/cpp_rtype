//
// Created by Eric on 03/12/2017.
//

#include <Parsing.h>
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
    back.flushLayers();
    orientation = Orientation::VERTICAL;
    Parsing::loadCSV(path, [&, this] (std::string const &path, int const &i) {
        this->back.addLayer(path, i);
    });
}

void Level::drawLvl(sf::RenderWindow &App)
{
    back.drawBackground(App);
}