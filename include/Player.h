//
// Created by Zàkelis on 29/11/2017.
//

#ifndef RTYPE_PLAYER_H
#define RTYPE_PLAYER_H

#include <SFML/Audio/Music.hpp>
#include "Entity.h"
#include "Bullet.h"

class Player : public Entity
{
public:
    void setGameMovementMode(ControlType GameMovementMode);
    ControlType getGameMovementMode() const;
    Player();
    ~Player();
    virtual void shoot();
    virtual void updatePos();

private:
    ControlType GameMovementMode;
    sf::Music   shotSound;
};


#endif //RTYPE_PLAYER_H
