//
// Created by Pierre on 08/12/2017.
//

#ifndef RTYPE_TEXTUREMANAGER_H
#define RTYPE_TEXTUREMANAGER_H

#include <iostream>
#include "Animation.h"

class TextureManager {
public:
    static TextureManager& Instance();
    Animation &getSprite(Textures);
private:
    Animation sprites[5];
    TextureManager& operator= (const TextureManager&){
        return *this;
    }
    TextureManager (const TextureManager&){}

    static TextureManager m_instance;
    TextureManager();
    ~TextureManager();
};


#endif //RTYPE_TEXTUREMANAGER_H
