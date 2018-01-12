//
// Created by Eric on 29/11/2017.
//

#ifndef RTYPE_ENTITY_H
#define RTYPE_ENTITY_H

#include "IEntity.h"
#include "Weapon.h"

class Entity : public IEntity
{
protected:
    int hp;
    sf::Vector2f pos;
    sf::Vector2f trajectory;
    int shootCooldown;

    Weapon weapon;
    Stance stance;
    Animation sprites[2];
    int speed;
    Orientation orientation;

public:
    Entity();
    ~Entity();
    virtual int getHp() const;
    virtual void setHp(int hp);
    virtual const sf::Vector2f &getPos() const;
    virtual void setPos(const sf::Vector2f &pos);
    virtual Stance getStance() const;
    virtual void setStance(Stance stance);
    virtual sf::FloatRect getBounds();
    virtual void drawSprite(sf::RenderWindow &App);
    virtual void move(sf::Vector2f);
    virtual void changeOrientation(Orientation);
    virtual bool outOfBounds();
    virtual void setTrajectory(const sf::Vector2f &newTrajectory);
    virtual Orientation getOrientation() const;
    virtual void setOrientation(Orientation orientation);

    virtual void shoot() = 0;
    virtual void updatePos() = 0;
};

#endif //RTYPE_ENTITY_H
