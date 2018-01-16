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

class Level1 : public ALevel
{

public:
    Level1();
    ~Level1();

    virtual void start();
};


#endif //RTYPE_LEVEL_H
