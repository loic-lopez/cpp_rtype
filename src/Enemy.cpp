//
// Created by Zàkelis on 06/12/2017.
//

#include "Enemy.h"

Enemy::Enemy(EnemyType type) : Entity()
{
    TextureManager &ptr1 = TextureManager::Instance();
    stance = Stance::IDLE;
    back = static_cast<bool>(std::rand() % 2);
    if (type == EnemyType::BASIC_A)
    {
        enemyType = type;
        orientation = WindowProperties::orientation;
        sprites[(int) Stance::IDLE] = ptr1.getSprite(Textures::ENEMY1);
        pos.x = WindowProperties::WIN_WIDTH * 120 / 100;
        pos.y = std::rand() % WindowProperties::WIN_HEIGHT;
        trajectory.x = 1;
        trajectory.y = 1;
        speed = 3;
        rewardScore = 5;
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
        pos.y = std::rand() % WindowProperties::WIN_HEIGHT;
        trajectory.x = 2;
        trajectory.y = 1;
        speed = 4;
        rewardScore = 10;
        weapon.setWeapon(WeaponType::STRAIGHT, 30, 2);
        this->setSide(Side::ENEMY);
        this->setType(Textures::ENEMY2);
    }
    if (type == EnemyType::BOSS_A)
    {
        enemyType = type;
        orientation = WindowProperties::orientation;
        sprites[(int) Stance::IDLE] = ptr1.getSprite(Textures::BOSS1);
        pos.x = WindowProperties::WIN_WIDTH * 120 / 100;
        pos.y = WindowProperties::WIN_HEIGHT / 2;
        hp = 20;
        trajectory.x = 0;
        trajectory.y = 3;
        speed = 3;
        rewardScore = 100;
        weapon.setWeapon(WeaponType::SPREAD, 40, 3);
        this->setSide(Side::ENEMY);
        this->setType(Textures::BOSS1);
    }
    if (type == EnemyType::BOSS_B)
    {
        enemyType = type;
        orientation = WindowProperties::orientation;
        sprites[(int) Stance::IDLE] = ptr1.getSprite(Textures::BOSS2);
        pos.x = WindowProperties::WIN_WIDTH * 120 / 100;
        pos.y = WindowProperties::WIN_HEIGHT / 2;
        hp = 30;
        trajectory.x = 0;
        trajectory.y = 3;
        speed = 3;
        rewardScore = 150;
        weapon.setWeapon(WeaponType::SPREAD, 40, 3);
        this->setSide(Side::ENEMY);
        this->setType(Textures::BOSS2);
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
            case EnemyType::BOSS_B :
            case EnemyType::BOSS_A :
            {
                sf::Vector2f postmp;

                postmp.x = pos.x - 90;
                postmp.y = pos.y;
                shootCooldown = weapon.getCoolDown();;
                weapon.shoot(orientation, postmp, Side::ENEMY, BulletType::ENEMY_A);
                break;
            }

            case EnemyType::NONE:break;
        }
    }
}

void Enemy::updatePos()
{
    if (shootCooldown > 0)
    {
        shootCooldown--;
    }
    if (back)
        move(sf::Vector2f(0, trajectory.y));
    else
        move(sf::Vector2f(0, -trajectory.y));
    if (pos.y == WindowProperties::WIN_HEIGHT && back) {
        back = false;
    }
    if (pos.y == 0 && !back) {
        back = true;
    }
    if (back2)
        move(sf::Vector2f(trajectory.x, 0));
    else
        move(sf::Vector2f(-trajectory.x, 0));
    if (pos.x == WindowProperties::WIN_WIDTH && back2)
        back2 = false;
    if (pos.x <= WindowProperties::WIN_WIDTH / 3 && !back2)
        back2 = true;
}

unsigned Enemy::getReward() {
    return rewardScore;
}
