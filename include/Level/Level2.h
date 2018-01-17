//
// Created by Loic Dupil on 17/01/2018.
//

#ifndef R_TYPE_LEVEL2_H
#define R_TYPE_LEVEL2_H

#include <SFML/Audio.hpp>
#include "Enum.h"
#include "Bg.h"
#include "HUD.h"
#include "Level/ALevel.h"

class Level2 :public ALevel
{

public:
    Level2();
    ~Level2();

    virtual void start();
};

#endif //R_TYPE_LEVEL2_H
