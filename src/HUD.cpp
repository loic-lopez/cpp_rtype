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
    Parsing::loadCSV(path, [&, this] (std::string const &path, int const &i) {
        (void)i;
        std::cout << "hello" << std::endl;
        std::cout << this->basisHP << std::endl;
        this->addLayer(path);

    });
}

void Hud::drawHud(sf::RenderWindow &App)
{
    float     firstXPos = (float)WindowProperties::WIN_WIDTH / 10;
    float     firstYPos = 0;
    for (size_t i = 0; i < this->basisHP; i++)
    {
        layers[0]->img.setPosition(firstXPos, firstYPos);
        firstXPos += (float)layers[0]->texture.getSize().x;
        App.draw(layers[0]->img);

    }
    firstXPos = (float)WindowProperties::WIN_WIDTH / 10;
   for (size_t i = 0; i < this->currentPlayerHP; i++)
    {
        layers[1]->img.setPosition(firstXPos, firstYPos);
        firstXPos += (float)layers[1]->texture.getSize().x;
        App.draw(layers[1]->img);

    }

}

void Hud::addLayerAlignedForMenu(const std::string &path, int speed, int cpt) {
    (void) speed;
    t_layer *nLayer = new t_layer;

    nLayer->texture.loadFromFile(path);
    nLayer->img.setTexture(nLayer->texture);
    nLayer->img.setPosition(WindowProperties::WIN_WIDTH / 2 - ((nLayer->img.getGlobalBounds().width / 2)),
                            (float)50 + WindowProperties::WIN_HEIGHT / 5 * cpt);
    layers.push_back(nLayer);
}

void Hud::drawHUD(sf::RenderWindow &App) {
    for (size_t i = 0; i < layers.size(); i++) {
            App.draw(layers[i]->img);
    }
}

void Hud::flushLayers() {
    while (layers.empty() != true)
    {
        delete layers[0];
        layers.erase(layers.begin());
    }
}
