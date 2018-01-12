//
// Created by Eric on 30/11/2017.
//

#include "Animation.h"

Animation::Animation()
{
}

Animation::Animation(const Animation& animation) : speed(animation.speed),
                                                   scale(animation.scale),
                                                   width(animation.width),
                                                   height(animation.height)
{
    data = animation.data;
    texture = animation.texture;
    frame = 0;
    currentSpeed = 0;
    sprite.setTexture(*texture);
    updateFrame();
}

Animation::Animation(const std::string &path, Stance stance)
{
    data = new std::vector<int>;
    currentSpeed = 0;
    std::ifstream infile(findCsv(path, stance));
    std::string line;
    if (std::getline(infile, line)) {
        texture = new sf::Texture;
        texture->loadFromFile("./ressources/" + path + "/" + line.substr(0, line.find(',')));
        line = line.substr(line.find(',') + 1);
        scale = std::stoi(line.substr(0, line.find(',')));
        line = line.substr(line.find(',') + 1);
        speed =  std::stoi(line.substr(0, line.find(',')));
        while (std::getline(infile, line)) {
            for (size_t i = 0; i < 4; i++) {
                data->push_back(std::stoi(line.substr(0, line.find(','))));
                line = line.substr(line.find(',') + 1);
            }
        }
        width = (*data)[2];
        height = (*data)[3];
        frame = 0;
        sprite.setTexture(*texture);
        updateFrame();
    }
}

Animation::~Animation()
{

}

void Animation::freeDatas()
{
    delete texture;
    delete data;
}

void Animation::updateFrame()
{
    width = (*data)[frame * 4 + 2] * scale / 100;
    height = (*data)[frame * 4 + 3] * scale / 100;
    sprite.setTextureRect(sf::IntRect((*data)[frame * 4 + 0], (*data)[frame * 4 + 1], (*data)[frame * 4 + 2], (*data)[frame * 4 + 3]));
}

void Animation::rotateSprite(Orientation orientation)
{
    if (orientation == Orientation::HORIZONTAL) {
        sprite.setRotation(90);
    }
    else if (orientation == Orientation::VERTICAL) {
        sprite.setRotation(0);
    }
}

void Animation::drawFrame(sf::RenderWindow &App, sf::Vector2f pos, Orientation orientation)
{
    sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
    sprite.setPosition(pos);
    sprite.setScale((float)scale / 100.0f , (float)scale / 100.0f);
    rotateSprite(orientation);
    App.draw(sprite);
    currentSpeed++;
    if (currentSpeed == speed) {
        currentSpeed = 0;
        frame = (frame + 1) % ((*data).size() / 4);
        updateFrame();
    }

}

std::string Animation::findCsv(const std::string &path, Stance stance)
{
    if (stance == Stance::IDLE)
        return ("./ressources/" + path + "/idle.csv");
    else if (stance == Stance::DEATH)
        return ("./ressources/" + path + "/death.csv");
    return ("");
}

void Animation::setColor(sf::Color color)
{
    sprite.setColor(color);
}

sf::FloatRect Animation::getSize() {
    return (sprite.getGlobalBounds());
}

void Animation::setScale(int _scale) {
    scale = _scale;
}

int Animation::totalFrame() {
    return (data->size() / 4);
}