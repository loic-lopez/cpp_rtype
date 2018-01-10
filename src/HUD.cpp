//
// Created by Loic Dupil on 09/01/2018.
//

#include <HUD.h>

Hud::Hud() {
    this->HP = 3;
}

Hud::~Hud() {

}

void Hud::addLayer(const std::string &path, int speed) {
    (void) speed;
    t_layer *nLayer = new t_layer;

    nLayer->texture.loadFromFile(path);
    nLayer->img.setTexture(nLayer->texture);
    nLayer->img.setPosition(0, 0);
    layers.push_back(nLayer);
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
