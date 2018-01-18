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

class DeepSpace :public ALevel
{

public:
    DeepSpace();
    ~DeepSpace();

    virtual void start();
    virtual void enemiesGenerator(short);

};

#endif //R_TYPE_LEVEL2_H
