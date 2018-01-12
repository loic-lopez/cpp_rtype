//
// Created by Zàkelis on 06/12/2017.
//

#include "Enemy.h"

Enemy::Enemy(EnemyType type) : Entity()
{
    TextureManager &ptr1 = TextureManager::Instance();
    stance = Stance::IDLE;
    if (type == EnemyType::BASIC_A)
    {
        enemyType = type;
        orientation = WindowProperties::orientation;
        sprites[(int) Stance::IDLE] = ptr1.getSprite(Textures::ENEMY1);
        pos.x = WindowProperties::WIN_WIDTH * 60 / 100;
        pos.y = WindowProperties::WIN_HEIGHT / 2;
        trajectory.x = 0;
        trajectory.y = 0;
        speed = 10;
        weapon.setWeapon(WeaponType::SPREAD, 6, 10);
    }
}

Enemy::~Enemy()
{

}

Bullet *Enemy::straightBullet(BulletType bulletType)
{
    Bullet *bullet = new Bullet(bulletType);
    if (orientation == Orientation::HORIZONTAL)
    {
        bullet->setTrajectory(sf::Vector2f(-1, 0));
        bullet->setOrientation(Orientation::HORIZONTAL);
    }
    else
    {
        bullet->setTrajectory(sf::Vector2f(0, 1));
        bullet->setOrientation(Orientation::VERTICAL);
    }
    return (bullet);
}

void Enemy::shoot()
{
    if (shootCooldown == 0)
    {
        switch (enemyType)
        {
            case EnemyType::BASIC_A :
            {
                shootCooldown = weapon.getCoolDown();;
                weapon.shoot(orientation, pos, Side::ENEMY, BulletType::ENEMY_A);
            }
        }
    }
}

void Enemy::updatePos()
{
    if (shootCooldown > 0)
        shootCooldown--;
    if (orientation == Orientation::VERTICAL)
    {
        if (back == true)
            move(sf::Vector2f(1, 0));
        else
            move(sf::Vector2f(-1, 0));
        if (pos.x == WindowProperties::WIN_WIDTH && back == true)
        {
            back = false;
        }
        if (pos.x == 0 && back == false)
        {
            back = true;
        }
    }
    else if (orientation == Orientation::HORIZONTAL)
    {
        if (back == true)
            move(sf::Vector2f(0, 1));
        else
            move(sf::Vector2f(0, -1));
        if (pos.y == WindowProperties::WIN_HEIGHT && back == true)
        {
            back = false;
        }
        if (pos.y == 0 && back == false)
        {
            back = true;
        }
    }

}