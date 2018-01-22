//
// Created by Loic Dupil on 18/01/2018.
//

#include "PowerUp.h"

PowerUp::PowerUp()
{
    TextureManager &ptr1 = TextureManager::Instance();
    std::random_device  device;
    std::mt19937 mt(device());
    std::uniform_int_distribution<int>     value(0, 2);
    stance = Stance::IDLE;
    pos.x = WindowProperties::WIN_WIDTH;
    pos.y = std::rand() % WindowProperties::WIN_HEIGHT;
    trajectory.x = 1;
    trajectory.y = 1;
    speed = 5;
    this->setSide(Side::ALLIED);
    switch (value(mt))
    {
        case 0:
        {
            this->type = Textures::LIFEUP;
            sprites[(int) Stance::IDLE] = ptr1.getSprite(Textures::LIFEUP);
            type = Textures::LIFEUP;
            break;
        }
        case 1:
        {
            this->type = Textures::SPREAD;
            sprites[(int) Stance::IDLE] = ptr1.getSprite(Textures::SPREAD);
            type = Textures::SPREAD;
            break;
        }
        case 2:
        {
            this->type = Textures::STRAIGHT;
            sprites[(int) Stance::IDLE] = ptr1.getSprite(Textures::STRAIGHT);
            type = Textures::STRAIGHT;
            break;
        }
    }
}

PowerUp::~PowerUp()
{

}

void PowerUp::updatePos()
{
    move(sf::Vector2f(-1, 0));
}

unsigned PowerUp::getReward()
{
    return 0;
}

void PowerUp::shoot()
{

}
