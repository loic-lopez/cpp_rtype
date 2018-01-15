//
// Created by Zàkelis on 29/11/2017.
//

#ifndef RTYPE_IENTITY_H
#define RTYPE_IENTITY_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Enum.h"
#include "Animation.h"
#include "TextureManager.h"

class IEntity
{
public:
    virtual ~IEntity() {};
    virtual int *getHp() = 0;
    virtual void setHp(int hp) = 0;
    virtual const sf::Vector2f &getPos() const = 0;
    virtual void setPos(const sf::Vector2f &pos) = 0;
    virtual sf::FloatRect getBounds() = 0;
    virtual void setSide(Side) = 0;
    virtual Side getSide() = 0;
    virtual void setType(Textures) = 0;
    virtual Textures getType() = 0;

    virtual Stance getStance() const = 0;
    virtual void setStance(Stance stance) = 0;

    virtual void drawSprite(sf::RenderWindow &App) = 0;
    virtual void move(sf::Vector2f) = 0;
    virtual void changeOrientation(Orientation) = 0;
    virtual void shoot() = 0;
    virtual void updatePos() = 0;
    virtual bool outOfBounds() = 0;

    virtual void setTrajectory(const sf::Vector2f &) = 0;
    virtual Orientation getOrientation() const = 0;
    virtual void setOrientation(Orientation orientation) = 0;
    virtual sf::FloatRect getHitBox() = 0;
};

#endif //RTYPE_IENTITY_H
