//
// Created by Loic Dupil on 09/01/2018.
//

#include <HUD.h>
#include <Handler/GameHandler.h>


Hud::Hud()
{

}

Hud::~Hud()
{

}

/*void Hud::addLayer(const std::string &path)
{
    t_layer *nLayer = new t_layer;

    nLayer->texture.loadFromFile(path);
    nLayer->img.setTexture(nLayer->texture);
    nLayer->img.setPosition(0, 0);
    layers.emplace_back(nLayer);
}*/

void Hud::initHud(const std::string &path)
{
    Parsing::loadCSV(path, [&, this](std::string const &path, int const &i)
    {
        if (path.find("EmptyHeart.png") != std::string::npos)
            this->fillHeartVector(path, this->emptyHearts);
        else if (path.find("FilledHeart.png") != std::string::npos)
            this->fillHeartVector(path, this->filledHearts);
        else
        {

        }
        (void) i;
       // this->addLayer(path);

    });
}

void Hud::drawHud(sf::RenderWindow &App)
{

    for (const auto &emptyHeart : emptyHearts)
        App.draw(emptyHeart->img);

    for (const auto &filledHeart : filledHearts)
        App.draw(filledHeart->img);

}

void Hud::fillHeartVector(const std::string &path, std::vector<std::shared_ptr<Hud::t_layer>> &vector)
{
    float firstXPos = (float) WindowProperties::WIN_WIDTH / 100;
    float firstYPos = 0;
    int hp = 0;

    vector.emplace_back(new t_layer(path, sf::Vector2f(firstXPos, firstYPos)));
    hp++;
    while (hp < WindowProperties::MAX_PLAYER_HP)
    {
        firstXPos += (float) vector.front()->texture.getSize().x / 2;
        vector.emplace_back(new t_layer(path, sf::Vector2f(firstXPos, firstYPos)));
        hp++;
    }

}

void Hud::takeDamage()
{
    filledHearts.pop_back();
}

Hud::t_layer::t_layer(const std::string &path, sf::Vector2f position)
{
    texture.loadFromFile(path);
    img.setTexture(texture);
    img.setPosition(position);
}
