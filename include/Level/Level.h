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

class Level : public ALevel
{

public:
    Level();
    ~Level();

    virtual void start();

//    void setMusicStatus(const std::string &status);
//    const sf::SoundSource::Status getMusicStatus() const;
};


#endif //RTYPE_LEVEL_H
