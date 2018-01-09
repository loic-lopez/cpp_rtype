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
