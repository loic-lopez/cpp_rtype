//
// Created by Pierre on 03/12/2017.
//

#ifndef RTYPE_UNDERWATER_H
#define RTYPE_UNDERWATER_H

#include <SFML/Audio.hpp>
#include "Enum.h"
#include "Bg.h"
#include "HUD.h"
#include "Level/ALevel.h"

// LEVEL 1

class Underwater : public ALevel
{

public:
    Underwater();
    ~Underwater();

    virtual void start();
};


#endif //RTYPE_UNDERWATER_H
