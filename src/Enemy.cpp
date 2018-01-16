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
        pos.x = WindowProperties::WIN_WIDTH * 120 / 100;
        pos.y = rand() % WindowProperties::WIN_HEIGHT;
        trajectory.x = 1;
        trajectory.y = 0;
        speed = 3;
        weapon.setWeapon(WeaponType::SPREAD, 40, 1);
        this->setSide(Side::ENEMY);
        this->setType(Textures::ENEMY1);
    }

    if (type == EnemyType::BASIC_B)
    {
        enemyType = type;
        orientation = WindowProperties::orientation;
        sprites[(int) Stance::IDLE] = ptr1.getSprite(Textures::ENEMY2);
        pos.x = WindowProperties::WIN_WIDTH * 120 / 100;
        pos.y = rand() % WindowProperties::WIN_HEIGHT;
        trajectory.x = 1;
        trajectory.y = 0;
        speed = 4;
        weapon.setWeapon(WeaponType::STRAIGHT, 30, 2);
        this->setSide(Side::ENEMY);
        this->setType(Textures::ENEMY2);
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
                sf::Vector2f postmp;

                postmp.x = pos.x - 90;
                postmp.y = pos.y;
                shootCooldown = weapon.getCoolDown();;
                weapon.shoot(orientation, postmp, Side::ENEMY, BulletType::ENEMY_A);
                break;
            }
            case EnemyType::BASIC_B :
            {
                sf::Vector2f postmp;

                postmp.x = pos.x - 90;
                postmp.y = pos.y;
                shootCooldown = weapon.getCoolDown();;
                weapon.shoot(orientation, postmp, Side::ENEMY, BulletType::ENEMY_A);
                break;
            }
        }
    }
}

void Enemy::updatePos()
{
    if (shootCooldown > 0) {
        shootCooldown--;
    }
    if (orientation == Orientation::VERTICAL)
    {
        if (back) {
            move(sf::Vector2f(1, 0));
        }
        else {
            move(sf::Vector2f(-1, 0));
        }
        if (pos.x == WindowProperties::WIN_WIDTH && back)
        {
            back = false;
        }
        if (pos.x == 0 && !back)
        {
            back = true;
        }
    }
    else if (orientation == Orientation::HORIZONTAL)
    {
        //move(sf::Vector2f(-trajectory.x, 0));
        if (back)
            move(sf::Vector2f(0, 1));
        else
            move(sf::Vector2f(0, -1));
        if (pos.y == WindowProperties::WIN_HEIGHT && back)
        {
            back = false;
        }
        if (pos.y == 0 && !back)
        {
            back = true;
        }
        if (back2)
            move(sf::Vector2f(trajectory.x, 0));
        else
            move(sf::Vector2f(-trajectory.x, 0));
        if (pos.x == WindowProperties::WIN_WIDTH && back2)
            back2 = false;
        if (pos.x == 0 && !back2)
            back2 = true;
    }

}