//
// Created by Pierre on 03/12/2017.
//

#ifndef RTYPE_UNDERWATER_H
#define RTYPE_UNDERWATER_H

// LEVEL 5

#include "ALevel.h"

class Underwater : public ALevel
{

public:
    Underwater();
    ~Underwater();

    virtual void enemiesGenerator(short);
    virtual void start();
};


#endif //RTYPE_UNDERWATER_H
