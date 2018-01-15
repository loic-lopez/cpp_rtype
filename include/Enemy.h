//
// Created by Zàkelis on 06/12/2017.
//

#ifndef RTYPE_ENNEMY_H
#define RTYPE_ENNEMY_H

#include "WindowProperties.h"
#include "Entity.h"
#include "Bullet.h"


class Enemy : public Entity{
private:
    bool back = true;
    bool back2 = false;
    EnemyType enemyType;

public:
    Enemy(EnemyType type);
    ~Enemy();
    virtual void shoot();
    virtual void updatePos();
    Bullet *straightBullet(BulletType bulletType);
};


#endif //RTYPE_ENNEMY_H
