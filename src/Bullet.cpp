//
// Created by Pierre on 04/12/2017.
//

#include <Static/WindowProperties.h>
#include "Bullet.h"

Bullet::Bullet(BulletType type)
{
    TextureManager &ptr1 = TextureManager::Instance();
    switch (type)
    {
        case BulletType::BASIC_A :
        {
            speed = 40;
            stance = Stance::IDLE;
            sprites[(int) Stance::IDLE] = Animation(ptr1.getSprite(Textures::BULLET_BASIC_A));
            setSide(Side::ALLIED);
            setType(Textures::BULLET_BASIC_A);
            break;
        }
        case BulletType::ENEMY_A :
        {
            speed = 10;
            stance = Stance::IDLE;
            sprites[(int) Stance::IDLE] = Animation(ptr1.getSprite(Textures::BULLET_ENEMY_A));
            setSide(Side::ENEMY);
            setType(Textures::BULLET_ENEMY_A);
            break;
        }
        case BulletType::PLAYER_A:
        {
            speed = 20;
            stance = Stance::IDLE;
            sprites[(int) Stance::IDLE] = Animation(ptr1.getSprite(Textures::PLAYER_BULLETS_A));
            setSide(Side::ALLIED);
            setType(Textures::PLAYER_BULLETS_A);
            break;
        }
    }
}

Bullet::~Bullet()
{

}

Side Bullet::getSide() const
{
    return side;
}

void Bullet::setSide(Side side)
{
    Bullet::side = side;
}

void Bullet::shoot()
{

}

void Bullet::updatePos()
{
    if (side == Side::ALLIED)
    {
        pos.x = pos.x + (float) speed * trajectory.x;
        pos.y = pos.y + (float) speed * trajectory.y;
    }
    else
    {
        pos.x = pos.x - (float) speed * trajectory.x;
        pos.y = pos.y - (float) speed * trajectory.y;
    }
}