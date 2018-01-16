//
// Created by loic on 02/12/2017.
//

#include <iostream>
#include "Static/WindowProperties.h"
#include "Bg.h"

Bg::Bg()
{
    orientation = WindowProperties::orientation;
}

Bg::~Bg()
{

}

void Bg::addLayer(const std::string &path, int speed)
{
    t_layer *nLayer = new t_layer;

    nLayer->text.loadFromFile(path);
    nLayer->img.setTexture(nLayer->text);
    nLayer->speed = speed;
    nLayer->img.setPosition(0, 0);
    if (orientation == Orientation::VERTICAL)
    {
        float scale = (float) WindowProperties::WIN_WIDTH / nLayer->img.getGlobalBounds().width;
        nLayer->img.scale(scale, scale);
        nLayer->position1 = (float) WindowProperties::WIN_HEIGHT - nLayer->img.getGlobalBounds().height;
        nLayer->position2 = (float) WindowProperties::WIN_HEIGHT - 2 * nLayer->img.getGlobalBounds().height;
    }
    else if (orientation == Orientation::HORIZONTAL)
    {
        float scale = (float) WindowProperties::WIN_HEIGHT / nLayer->img.getGlobalBounds().width;
        nLayer->img.scale(scale, scale);
        nLayer->img.setRotation(90);
        nLayer->position1 = nLayer->img.getGlobalBounds().width;
        nLayer->position2 = 0;
    }
    layers.push_back(nLayer);
}

void Bg::drawBackground(sf::RenderWindow &App)
{
    for (size_t i = 0; i < layers.size(); i++)
    {
        if (orientation == Orientation::VERTICAL)
        {
            layers[i]->img.setPosition(0, layers[i]->position1);
            App.draw(layers[i]->img);
            layers[i]->img.setPosition(0, layers[i]->position2);
            App.draw(layers[i]->img);
            layers[i]->position1 = layers[i]->position1 + layers[i]->speed;
            layers[i]->position2 = layers[i]->position2 + layers[i]->speed;
            if (layers[i]->position1 > WindowProperties::WIN_HEIGHT)
            {
                layers[i]->position1 = layers[i]->position2 - layers[i]->img.getGlobalBounds().height;
            }
            if (layers[i]->position2 > WindowProperties::WIN_HEIGHT)
            {
                layers[i]->position2 = layers[i]->position1 - layers[i]->img.getGlobalBounds().height;
            }
        }
        else if (orientation == Orientation::HORIZONTAL)
        {
            layers[i]->img.setPosition(layers[i]->position1, 0);
            App.draw(layers[i]->img);
            layers[i]->img.setPosition(layers[i]->position2, 0);
            App.draw(layers[i]->img);
            layers[i]->position1 = layers[i]->position1 - layers[i]->speed;
            layers[i]->position2 = layers[i]->position2 - layers[i]->speed;
            if (layers[i]->position1 < 0)
            {
                layers[i]->position1 = layers[i]->position2 + layers[i]->img.getGlobalBounds().width;
            }
            if (layers[i]->position2 < 0)
            {
                layers[i]->position2 = layers[i]->position1 + layers[i]->img.getGlobalBounds().width;
            }
        }
    }
}

void Bg::changeOrientation(Orientation orientation1)
{
    if (orientation == Orientation::VERTICAL && orientation1 != Orientation::VERTICAL)
    {
        for (size_t i = 0; i < layers.size(); i++)
        {
            float scale = (float) WindowProperties::WIN_HEIGHT / layers[i]->img.getGlobalBounds().width;
            layers[i]->img.scale(scale, scale);
            layers[i]->img.setRotation(90);
        }
    }
    else if (orientation == Orientation::HORIZONTAL && orientation1 != Orientation::HORIZONTAL)
    {
        for (size_t i = 0; i < layers.size(); i++)
        {
            layers[i]->img.setRotation(0);
            float scale = (float) WindowProperties::WIN_WIDTH / layers[i]->img.getGlobalBounds().width;
            layers[i]->img.scale(scale, scale);

        }
    }
    orientation = orientation1;
}

void Bg::flushLayers()
{
    while (layers.empty() != true)
    {
        delete layers[0];
        layers.erase(layers.begin());
    }

}
