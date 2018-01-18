//
// Created by Zàkelis on 03/12/2017.
//

#ifndef RTYPE_LEVEL_H
#define RTYPE_LEVEL_H

#include <SFML/Audio.hpp>
#include "Enum.h"
#include "Bg.h"
#include "HUD.h"
#include "Level/ALevel.h"

// LEVEL 1

class Space : public ALevel
{

public:
    Space();
    ~Space();

    virtual void enemiesGenerator(short);
    virtual void start();
};


#endif //RTYPE_LEVEL_H
