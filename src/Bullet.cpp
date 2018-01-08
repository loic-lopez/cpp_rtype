//
// Created by Eric on 04/12/2017.
//

#include "Bullet.h"

Bullet::Bullet(BulletType type) {
    TextureManager& ptr1 = TextureManager::Instance();
    switch (type) {
        case BulletType::BASIC_A : {
            speed = 40;
            stance = Stance::IDLE;
             sprites[(int)Stance::IDLE] = Animation(ptr1.getSprite(Textures::BULLET_BASIC_A));
             break;
        }
        case BulletType::ENEMY_A : {
            speed = 10;
            stance = Stance::IDLE;
            sprites[(int)Stance::IDLE] = Animation(ptr1.getSprite(Textures::BULLET_ENEMY_A));
            break;
        }
        case BulletType::REIMU_A : {
            speed = 20;
            stance = Stance::IDLE;
            sprites[(int)Stance::IDLE] = Animation(ptr1.getSprite(Textures::REIMU_BULLETS_A));
            break;
        }
    }
}

Bullet::~Bullet() {

}

Side Bullet::getSide() const {
    return side;
}

void Bullet::setSide(Side side) {
    Bullet::side = side;
}

void Bullet::shoot() {

}

void Bullet::updatePos() {
    if (side == Side::ALLIED) {
        pos.x = pos.x + (float) speed * trajectory.x;
        pos.y = pos.y + (float) speed * trajectory.y;
    }
    else {
        pos.x = pos.x - (float) speed * trajectory.x;
        pos.y = pos.y - (float) speed * trajectory.y;
    }
}