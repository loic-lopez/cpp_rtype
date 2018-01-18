//
// Created by loic lopez on 17/01/2018.
//

#ifndef R_TYPE_SPACECEMETERY_H
#define R_TYPE_SPACECEMETERY_H

// LEVEL 3

#include "ALevel.h"

class SpaceCemetery : public ALevel
{
public:
    SpaceCemetery();
    ~SpaceCemetery();

    virtual void start();
    virtual void enemiesGenerator(short);

};

#endif //R_TYPE_SPACECEMETERY_H
