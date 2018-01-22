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

/*    if (lvlWeapon >= 1) {
        Bullet *bullet = new Bullet(bulletType);
        Bullet *bullet2 = new Bullet(bulletType);
        if (orientation == Orientation::HORIZONTAL) {
            bullet->setTrajectory(sf::Vector2f(1.f, 0.f));
            bullet->setOrientation(Orientation::HORIZONTAL);
            bullet2->setTrajectory(sf::Vector2f(1.f, 0.f));
            bullet2->setOrientation(Orientation::HORIZONTAL);
            bullet->setPos(sf::Vector2f(pos.x + ((float) WIN_WIDTH * 2.f / 100.f), pos.y -
                                                                                   ((float) WIN_HEIGHT * 1.5f / 100.f) *
                                                                                   ((float) WIN_HEIGHT * 3.f / 100.f)));
            bullet2->setPos(sf::Vector2f(pos.x + ((float) WIN_WIDTH * 2.f / 100.f), pos.y + ((float) WIN_HEIGHT * 1.5f /
                                                                                             100.f) *
                                                                                            ((float) WIN_HEIGHT * 3.f /
                                                                                             100.f)));
        } else {
            bullet->setTrajectory(sf::Vector2f(-0.1f, -1.f));
            bullet->setOrientation(Orientation::VERTICAL);
            bullet2->setTrajectory(sf::Vector2f(0.1f, -1.f));
            bullet2->setOrientation(Orientation::VERTICAL);
            bullet->setPos(sf::Vector2f(pos.x, pos.y - ((float) WIN_HEIGHT * 2.f / 100.f)));
            bullet2->setPos(sf::Vector2f(pos.x, pos.y - ((float) WIN_HEIGHT * 2.f / 100.f)));
        }
        bullet->setSide(side);
        bullet2->setSide(side);
        game.addBullet(bullet);
        game.addBullet(bullet2);
    }
    if (lvlWeapon >= 2) {
        Bullet *bullet = new Bullet(bulletType);
        Bullet *bullet2 = new Bullet(bulletType);
        if (orientation == Orientation::HORIZONTAL) {
            bullet->setTrajectory(sf::Vector2f(1.f, 0.f));
            bullet->setOrientation(Orientation::HORIZONTAL);
            bullet2->setTrajectory(sf::Vector2f(1.f, 0.f));
            bullet2->setOrientation(Orientation::HORIZONTAL);
            bullet->setPos(sf::Vector2f(pos.x, pos.y - ((float) WIN_HEIGHT * 2.f / 100.f)));
            bullet2->setPos(sf::Vector2f(pos.x, pos.y - ((float) WIN_HEIGHT * 2.f / 100.f)));
        } else {
            bullet->setTrajectory(sf::Vector2f(0.3f, -0.75f));
            bullet->setOrientation(Orientation::VERTICAL);
            bullet2->setTrajectory(sf::Vector2f(-0.3f, -0.75f));
            bullet2->setOrientation(Orientation::VERTICAL);
            bullet->setPos(sf::Vector2f(pos.x, pos.y - ((float) WIN_HEIGHT * 2.f / 100.f)));
            bullet2->setPos(sf::Vector2f(pos.x, pos.y - ((float) WIN_HEIGHT * 2.f / 100.f)));
        }
        bullet->setSide(side);
        bullet2->setSide(side);
        game.addBullet(bullet);
        game.addBullet(bullet2);
    }*/
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
