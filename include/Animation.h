//
// Created by Eric on 30/11/2017.
//

#ifndef RTYPE_ANIMATION_H
#define RTYPE_ANIMATION_H

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include "Enum.h"

class Animation {
private:
    sf::Texture *texture;
    sf::Sprite sprite;
    std::vector<int> *data;
    size_t frame;
    int scale;
    int speed;
    int currentSpeed;
    int width;
    int height;
public:
    Animation();
    Animation(const Animation& animation);
    Animation(const std::string &path, Stance stance);
    ~Animation();
    void updateFrame();
    void drawFrame(sf::RenderWindow &App, sf::Vector2f pos, Orientation orientation);
    void rotateSprite(Orientation orientation);
    std::string findCsv(const std::string &path, Stance stance);
    void setColor(sf::Color);
    void freeDatas();
    sf::FloatRect getSize();
    void setScale(int);
    int totalFrame();
};


#endif //RTYPE_ANIMATION_H
