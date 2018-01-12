//
// Created by loic lopez on 02/12/2017.
//

#ifndef RTYPE_ENUM_H
#define RTYPE_ENUM_H

#include <fstream>

enum class ControlType
{
    XBOXCONTROLLER,
    KEYBOARD
};

enum class Orientation
{
    VERTICAL,
    HORIZONTAL
};

enum class Stance
{
    IDLE,
    DEATH
};

enum class Side
{
    ALLIED,
    ENEMY
};

enum class GameState
{
    GAME,
    SPLASHSCREEN,
    MENU,
    CLOSE
};

enum class EnemyType
{
    BASIC_A,
    BASIC_B
};

enum class BulletType
{
    REIMU_A,
    BASIC_A,
    ENEMY_A
};

enum class WeaponType
{
    STRAIGHT,
    SPREAD,
    HOMING,
    ROTATE
};

enum class Textures
{
    REIMU,
    REIMU_BULLETS_A,
    ENEMY1,
    BULLET_BASIC_A,
    BULLET_ENEMY_A
};
#endif //RTYPE_ENUM_H
