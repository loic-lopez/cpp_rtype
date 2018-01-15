//
// Created by Zàkelis on 03/12/2017.
//

#ifndef RTYPE_LEVEL_H
#define RTYPE_LEVEL_H

#include <SFML/Audio.hpp>
#include "Enum.h"
#include "Bg.h"
#include "HUD.h"

class Level {
private:
    Orientation orientation;
    Bg back;
    sf::Music music;

public:
    Level();
    ~Level();
    void initLvl(const std::string &path);
    void changeOrientation(Orientation orientation);
    void drawLvl(sf::RenderWindow &App);
    void changeMusicStatus(const std::string &status);
    const sf::SoundSource::Status getMusicStatus(void);
};


#endif //RTYPE_LEVEL_H
