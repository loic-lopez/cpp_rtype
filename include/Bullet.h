//
// Created by Zàkelis on 04/12/2017.
//

#ifndef RTYPE_BULLET_H
#define RTYPE_BULLET_H

#include "Entity.h"

class Bullet : public Entity
{
private:
    Side side;
public:
    Bullet(BulletType type);
    ~Bullet();
    Side getSide() const;
    void setSide(Side side);
    virtual void shoot();
    virtual void updatePos();
};


#endif //RTYPE_BULLET_H
