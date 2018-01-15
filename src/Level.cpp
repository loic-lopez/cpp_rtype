//
// Created by Pierre on 03/12/2017.
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
        if (path.substr(path.find_last_of('.') + 1) == "ogg")
        {
            music.openFromFile(path);
            music.setLoop(true);
        }
        else if (path.substr(path.find_last_of('.') + 1) == "png" ||
                (path.substr(path.find_last_of('.') + 1) == "jpg"))
            this->back.addLayer(path, i);
    });
}

void Level::drawLvl(sf::RenderWindow &App)
{
    back.drawBackground(App);
}

void Level::setMusicStatus(const std::string &status)
{
    if (status == "stop")
        music.stop();
    else if (status == "play")
        music.play();
    else if (status == "pause")
        music.pause();
}

const sf::SoundSource::Status Level::getMusicStatus() const {
    return (music.getStatus());
/*
    if (music.getStatus() == sf::SoundSource::Stopped)
        return (sf::SoundSource::Stopped);
    else if (music.getStatus() == sf::SoundSource::Paused)
        return (sf::SoundSource::Paused);
    else if (music.getStatus() == sf::SoundSource::Playing)
        return (sf::SoundSource::Playing);
*/
}
