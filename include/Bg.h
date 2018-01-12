//
// Created by Pierre on 02/12/2017.
//

#ifndef RTYPE_BACKGROUND_H
#define RTYPE_BACKGROUND_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "Enum.h"

typedef struct s_layer {
    sf::Texture text;
    sf::Sprite img;
    int speed;
    float position1;
    float position2;
} t_layer;

class Bg {
private:
    Orientation orientation;
    std::vector<t_layer *> layers;
public:
    Bg();
    ~Bg();
    void addLayer(const std::string &path, int speed);
    void drawBackground(sf::RenderWindow &App);
    void changeOrientation(Orientation orientation1);
    void flushLayers();
};


#endif //RTYPE_BACKGROUND_H
