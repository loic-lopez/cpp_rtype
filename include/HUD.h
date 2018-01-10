//
// Created by Loic Dupil on 09/01/2018.
//

#ifndef R_TYPE_HUD_H
#define R_TYPE_HUD_H

#include <WindowProperties.h>
#include <SFML/Graphics.hpp>

class Hud
{
    struct t_layer {
        sf::Texture texture;
        sf::Sprite img;
    };

    unsigned int HP;
    std::vector<t_layer *> layers;
public:
    Hud();
    ~Hud();
    void addLayer(const std::string &path, int speed);
    void addLayerAlignedForMenu(const std::string &path, int speed, int cpt);
    void drawHUD(sf::RenderWindow &App);
    void flushLayers();
};

#endif //R_TYPE_HUD_H
