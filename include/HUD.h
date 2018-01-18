//
// Created by Loic Dupil on 09/01/2018.
//

#ifndef R_TYPE_HUD_H
#define R_TYPE_HUD_H

#include <Static/WindowProperties.h>
#include <SFML/Graphics.hpp>
#include <memory>
#include "Parsing.h"
#include "Player.h"

class Hud
{
    struct t_layer {
        sf::Texture texture;
        sf::Sprite img;
        int     id;
        t_layer(const std::string &path, sf::Vector2f position);
    };

    std::vector<std::shared_ptr<t_layer>> emptyHearts;
    std::vector<std::shared_ptr<t_layer>> filledHearts;
    std::vector<std::shared_ptr<t_layer>> scoreNumbers;
    std::shared_ptr<t_layer>              scoreText;

    void fillHeartVector(const std::string &path, std::vector<std::shared_ptr<t_layer>> &vector);
    void addScoreNumberTexture(const std::string &path);
    void addScoreTexture(const std::string &path);

public:
    Hud();
    ~Hud();
    //void addLayer(const std::string &path);
    void initHud(const std::string &path);
    void drawHud(sf::RenderWindow &App);
    void takeDamage();

};

#endif //R_TYPE_HUD_H
