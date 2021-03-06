//
// Created by Zàkelis on 09/12/2017.
//

#include <Handler/GameHandler.h>

Weapon::Weapon()
{
    lvlWeapon = 1;
}

Weapon::~Weapon()
= default;

void
Weapon::addBullet(Orientation orientation, sf::Vector2f pos, Side side, BulletType bulletType, sf::Vector2f trajectory)
{
    Bullet *bullet = new Bullet(bulletType);
    bullet->setTrajectory(trajectory);
    bullet->setOrientation(orientation);
    bullet->setPos(pos);
    bullet->setSide(side);
    GameHandler::Instance().getCurrentLevel()->addBullet(bullet);
}

void Weapon::straight(Orientation orientation, sf::Vector2f pos, Side side, BulletType bulletType)
{
    int i = 0;

    while (i < lvlWeapon)
    {
        if (orientation == Orientation::HORIZONTAL)
        {
            addBullet(orientation,
                      sf::Vector2f(pos.x + ((float) WindowProperties::WIN_WIDTH * 2.f / 100.f) * (lvlWeapon - i),
                                   pos.y - ((float) WindowProperties::WIN_HEIGHT * 1.5f / 100.f) -
                                   i * ((float) WindowProperties::WIN_HEIGHT * 3.f / 100.f)),
                      side, bulletType,
                      sf::Vector2f(1.f, 0.f));
            addBullet(orientation,
                      sf::Vector2f(pos.x + ((float) WindowProperties::WIN_WIDTH * 2.f / 100.f) * (lvlWeapon - i),
                                   pos.y + ((float) WindowProperties::WIN_HEIGHT * 1.5f / 100.f) +
                                   i * ((float) WindowProperties::WIN_HEIGHT * 3.f / 100.f)),
                      side, bulletType,
                      sf::Vector2f(1.f, 0.f));
        }
        else
        {
            addBullet(orientation,
                      sf::Vector2f(pos.x - ((float) WindowProperties::WIN_WIDTH * 1.f / 100.f) -
                                   i * ((float) WindowProperties::WIN_WIDTH * 2.f / 100.f),
                                   pos.y - ((float) WindowProperties::WIN_HEIGHT * 2.f / 100.f) * (lvlWeapon - i)),
                      side, bulletType,
                      sf::Vector2f(0.f, -1.f));
            addBullet(orientation,
                      sf::Vector2f(pos.x + ((float) WindowProperties::WIN_WIDTH * 1.f / 100.f) +
                                   i * ((float) WindowProperties::WIN_WIDTH * 2.f / 100.f),
                                   pos.y - ((float) WindowProperties::WIN_HEIGHT * 2.f / 100.f) * (lvlWeapon - i)),
                      side, bulletType,
                      sf::Vector2f(0.f, -1.f));
        }
        i++;
    }
}

void Weapon::spread(Orientation orientation, sf::Vector2f pos, Side side, BulletType bulletType)
{

    int i = 0;
    while (i < lvlWeapon)
    {
        if (orientation == Orientation::HORIZONTAL)
        {
            addBullet(orientation,
                      sf::Vector2f(pos.x + (float) WindowProperties::WIN_WIDTH * 2.f / 100.f,
                                   pos.y),
                      side, bulletType,
                      sf::Vector2f(1.f - (i * 0.05f), 0.f - (i) * 0.1f - 0.08f));
            addBullet(orientation,
                      sf::Vector2f(pos.x + (float) WindowProperties::WIN_WIDTH * 2.f / 100.f,
                                   pos.y),
                      side, bulletType,
                      sf::Vector2f(1.f - (i * 0.05f), 0.f + (i) * 0.1f + 0.08f));
        }
        else
        {
            addBullet(orientation,
                      sf::Vector2f(pos.x,
                                   pos.y - (float) WindowProperties::WIN_HEIGHT * 2.f / 100.f),
                      side, bulletType,
                      sf::Vector2f(0.f - (i) * 0.1f - 0.05f, -1.f + (i * 0.05f)));
            addBullet(orientation,
                      sf::Vector2f(pos.x,
                                   pos.y - (float) WindowProperties::WIN_HEIGHT * 2.f / 100.f),
                      side, bulletType,
                      sf::Vector2f(0.f + (i) * 0.1f + 0.05f, -1.f + (i * 0.05f)));
        }
        i++;
    }
}

void Weapon::shoot(Orientation orientation, sf::Vector2f pos, Side side, BulletType bullettype)
{
    switch (weaponType)
    {
        case WeaponType::STRAIGHT :
        {
            straight(orientation, pos, side, bullettype);
            break;
        }
        case WeaponType::SPREAD :
        {
            spread(orientation, pos, side, bullettype);
            break;
        }
        case WeaponType::HOMING :
        {
            break;
        }
        case WeaponType::ROTATE :
        {
            break;
        }
    }
}

void Weapon::lvlUp()
{
    if (lvlWeapon < 3)
        lvlWeapon++;
}

void Weapon::setWeapon(WeaponType weapon, int cd)
{
    coolDown = cd;
    weaponType = weapon;
}

void Weapon::setWeapon(WeaponType weapon, int cd, int level)
{
    coolDown = cd;
    weaponType = weapon;
    lvlWeapon = level;
}

int Weapon::getCoolDown() const
{
    return coolDown;
}

void Weapon::setCoolDown(int coolDown)
{
    Weapon::coolDown = coolDown;
}

WeaponType Weapon::getType()
{
    return this->weaponType;
}
