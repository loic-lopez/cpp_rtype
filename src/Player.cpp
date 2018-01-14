//
// Created by Eric on 29/11/2017.
//

#include <WindowProperties.h>
#include "Player.h"

Player::Player() : Entity()
{
    TextureManager &ptr1 = TextureManager::Instance();
    pos.x = WindowProperties::WIN_WIDTH * 10 / 100;
    pos.y = WindowProperties::WIN_HEIGHT / 2;
    trajectory.x = 0;
    trajectory.y = 0;
    speed = 10;
    stance = Stance::IDLE;
    sprites[(int) Stance::IDLE] = ptr1.getSprite(Textures::REIMU);
    shootCooldown = 0;
    GameMovementMode = ControlType::KEYBOARD;
    weapon.setWeapon(WeaponType::STRAIGHT, 10);
    setHp(3);
    setSide(Side::ALLIED);
    this->setType(Textures::REIMU);

}

Player::~Player()
{

}

void Player::shoot()
{
    if (shootCooldown == 0)
    {
        shootCooldown = weapon.getCoolDown();
        weapon.shoot(orientation, pos, Side::ALLIED, BulletType::REIMU_A);
    }
}

void Player::updatePos()
{
    if (shootCooldown > 0)
        shootCooldown--;
}

ControlType Player::getGameMovementMode() const
{
    return GameMovementMode;
}

void Player::setGameMovementMode(ControlType GameMovementMode)
{
    Player::GameMovementMode = GameMovementMode;
}
