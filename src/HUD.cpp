//
// Created by Loic Dupil on 09/01/2018.
//

#include <HUD.h>
#include <Handler/GameHandler.h>

Hud::Hud()
{
    this->basisHP = 3;
}

Hud::~Hud()
{

}

void Hud::addLayer(const std::string &path)
{
    t_layer *nLayer = new t_layer;

    nLayer->texture.loadFromFile(path);
    nLayer->img.setTexture(nLayer->texture);
    nLayer->img.setPosition(0, 0);
    layers.emplace_back(nLayer);
}

void Hud::initHud(const std::string &path)
{
    Parsing::loadCSV(path, [&, this](std::string const &path, int const &i)
    {
        (void) i;
        this->addLayer(path);

    });
}

void Hud::drawHud(sf::RenderWindow &App)
{
    int currentPlayerHP = GameHandler::Instance().getPlayer().getHp();
    float firstXPos = (float) WindowProperties::WIN_WIDTH / 100;
    float firstYPos = 0;
    for (size_t i = 0; i < this->basisHP; i++)
    {
        layers[0]->img.setPosition(firstXPos, firstYPos);
        firstXPos += (float) layers[0]->texture.getSize().x / 2;
        App.draw(layers[0]->img);

    }
    firstXPos = (float) WindowProperties::WIN_WIDTH / 100;
    for (size_t i = 0; i < currentPlayerHP; i++)
    {
        layers[1]->img.setPosition(firstXPos, firstYPos);
        firstXPos += (float) layers[1]->texture.getSize().x / 2;
        App.draw(layers[1]->img);
    }
}