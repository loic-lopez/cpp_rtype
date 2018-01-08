//
// Created by Eric on 03/12/2017.
//

#ifndef RTYPE_LEVEL_H
#define RTYPE_LEVEL_H

#include <SFML/Audio.hpp>
#include "Enum.h"
#include "Bg.h"

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
};


#endif //RTYPE_LEVEL_H
