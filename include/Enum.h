//
// Created by Eric on 02/12/2017.
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

enum class Stance : int
{
    IDLE = 0,
    DEATH = 1
};

enum class Side
{
    ALLIED,
    ENEMY
};

enum class GameState : int
{
    GAME = 0,
    SPLASHSCREEN = 1,
    MENU = 2,
    CLOSE = 3
};

enum class EnemyType
{
    BASIC_A,
    BASIC_B
};

enum class BulletType
{
    PLAYER_A,
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
    PLAYER,
    PLAYER_BULLETS_A,
    ENEMY1,
    BULLET_BASIC_A,
    BULLET_ENEMY_A
};
#endif //RTYPE_ENUM_H
