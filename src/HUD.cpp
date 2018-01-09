//
// Created by Loic Dupil on 09/01/2018.
//

#include <HUD.h>

Hud::Hud()
{
    this->basisHP = 3;
    this->currentPlayerHP = 1;
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
    Parsing::loadCSV(path, [&] (std::string const &path, int const &i) {
        (void)i;
        std::cout << "Pute -2" << std::endl;
        this->addLayer(path);
        std::cout << "Pute -4" << std::endl;

    });
}

void Hud::drawHud(sf::RenderWindow &App)
{
    std::cout << "Pute 1" << std::endl;
    float     firstXPos = (float)WindowProperties::WIN_WIDTH / 4;
    float     firstYPos = 0;
    std::cout << "Pute 2" << std::endl;
    for (size_t i = 0; i < this->basisHP; i++)
    {
        std::cout << "Pute 3" << std::endl;
        layers[1]->img.setPosition(firstXPos, firstYPos);
        firstXPos += (float)layers[1]->texture.getSize().x;
        App.draw(layers[1]->img);

    }
    std::cout << "Pute 4" << std::endl;
    firstXPos = (float)WindowProperties::WIN_WIDTH / 4;
    std::cout << "Pute 5" << std::endl;
   for (size_t i = 0; i < this->currentPlayerHP; i++)
    {
        std::cout << "Pute 6" << std::endl;
        layers[0]->img.setPosition(firstXPos, firstYPos);
        firstXPos += (float)layers[0]->texture.getSize().x;
        App.draw(layers[0]->img);

    }

}
