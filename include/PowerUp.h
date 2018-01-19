//
// Created by Loic Dupil on 18/01/2018.
//

#ifndef R_TYPE_POWERUP_H
#define R_TYPE_POWERUP_H

#include <random>
#include <Enum.h>
#include <Entity.h>
#include <functional>
#include "Enum.h"
#include "Static/WindowProperties.h"

class PowerUp :public Entity
{
    ControlType GameMovementMode;

public:
    PowerUp();
    ~PowerUp();

    virtual void updatePos();

};

#endif //R_TYPE_POWERUP_H
