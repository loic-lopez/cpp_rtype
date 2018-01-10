//
// Created by Loic Dupil on 09/01/2018.
//

#ifndef R_TYPE_HUD_H
#define R_TYPE_HUD_H

#include <WindowProperties.h>
#include <SFML/Graphics.hpp>
#include "Parsing.h"

class Hud
{
    struct t_layer {
        sf::Texture texture;
        sf::Sprite img;
        int     id;
    };

    unsigned int basisHP;
    unsigned int currentPlayerHP;
    std::vector<t_layer *> layers;


public:
    Hud();
    ~Hud();
    void addLayer(const std::string &path);
    void initHud(const std::string &path);
    void drawHud(sf::RenderWindow &App);

};

#endif //R_TYPE_HUD_H
