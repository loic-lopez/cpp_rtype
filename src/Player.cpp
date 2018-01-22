//
// Created by Zakelis on 29/11/2017.
//

#include <Static/WindowProperties.h>
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
    sprites[(int) Stance::IDLE] = ptr1.getSprite(Textures::PLAYER);
    shootCooldown = 0;
    GameMovementMode = ControlType::KEYBOARD;
    weapon.setWeapon(WeaponType::STRAIGHT, 10);
    setHp(WindowProperties::MAX_PLAYER_HP);
    score = 0;
    shotSound.openFromFile("./ressources/bullet/shot.ogg");
    shotSound2.openFromFile("./ressources/bullet/shot.ogg");
    shotSound3.openFromFile("./ressources/bullet/shot.ogg");
    shotSound4.openFromFile("./ressources/bullet/shot.ogg");
    shotSound.setLoop(false);
    shotSound2.setLoop(false);
    shotSound3.setLoop(false);
    shotSound4.setLoop(false);
    setSide(Side::ALLIED);
    this->setType(Textures::PLAYER);
    blinkingValue = 255;
}

Player::~Player()
{
    shotSound.stop();
    shotSound2.stop();
    shotSound3.stop();
    shotSound4.stop();
}

void Player::shoot()
{
    if (shootCooldown == 0)
    {
        shootCooldown = weapon.getCoolDown();
        weapon.shoot(orientation, pos, Side::ALLIED, BulletType::PLAYER_A);
        if (shotSound.getStatus() != sf::SoundStream::Playing)
            shotSound.play();
        else if (shotSound2.getStatus() != sf::SoundStream::Playing)
            shotSound2.play();
        else if (shotSound3.getStatus() != sf::SoundStream::Playing)
            shotSound3.play();
        else
            shotSound4.play();
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

unsigned int Player::getScore() const {
    return score;
}

void Player::setScore(unsigned int score) {
    Player::score = score;
}

sf::FloatRect   Player::getHitBox()
{
    sf::FloatRect hitbox = sprites[(int) stance].getSize();
    return (sf::FloatRect((pos.x - hitbox.width / 2.f) - 3.5f, (pos.y - hitbox.height / 2.f)  - 3.5f, hitbox.width  - 3.5f, hitbox.height  - 3.5f));
}

void    Player::drawSpriteBlinking()
{
    if (blinkingValue >= 0)
        blinkingValue -= 10;
    else
        blinkingValue += 10;
    sprites[(int) stance].drawFrame(*WindowProperties::App, pos, orientation, blinkingValue);
}

void Player::setBlinkingValue(unsigned int blinkingValue)
{
    Player::blinkingValue = blinkingValue;
}

WeaponType Player::getWeapon()
{
    return this->weapon.getType();
}

void Player::setWeapon(WeaponType type, int cd, int lvl)
{
    this->weapon.setWeapon(type, cd, lvl);
}

void Player::weaponUp()
{
    this->weapon.lvlUp();
}
