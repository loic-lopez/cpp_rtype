//
// Created by Eric on 06/12/2017.
//

#ifndef RTYPE_ENNEMY_H
#define RTYPE_ENNEMY_H

#include "Entity.h"
#include "Bullet.h"


class Enemy : public Entity{
private:
    bool back = true;
    EnemyType enemyType;
public:
    Enemy(EnemyType type);
    ~Enemy();
    virtual void shoot();
    virtual void updatePos();
    Bullet *straightBullet(BulletType bulletType);
};


#endif //RTYPE_ENNEMY_H
