//
// Created by Eric on 08/12/2017.
//

#include "TextureManager.h"

TextureManager TextureManager::m_instance = TextureManager();

TextureManager::TextureManager()
{
    sprites[(int) Textures::BULLET_BASIC_A] = Animation("bullet", Stance::IDLE);
    sprites[(int) Textures::BULLET_ENEMY_A] = Animation("enemyBulletA", Stance::IDLE);
    sprites[(int) Textures::REIMU] = Animation("player", Stance::IDLE);
    sprites[(int) Textures::REIMU_BULLETS_A] = Animation("reimuBullets", Stance::IDLE);
    sprites[(int) Textures::ENEMY1] = Animation("enemy1", Stance::IDLE);
}

TextureManager::~TextureManager()
{
    for (size_t i = 0; i < 5; i++)
    {
        sprites[i].freeDatas();
    }
}

TextureManager &TextureManager::Instance()
{
    return m_instance;
}

Animation &TextureManager::getSprite(Textures text)
{
    return (sprites[(int) text]);
}