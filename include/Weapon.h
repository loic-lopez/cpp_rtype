//
// Created by Pierre on 09/12/2017.
//

#ifndef RTYPE_WEAPON_H
#define RTYPE_WEAPON_H

#include <SFML/Graphics.hpp>
#include "Enum.h"


class Weapon {
private:
    WeaponType weaponType;
    int lvlWeapon;
    int coolDown;
public:
    Weapon();
    ~Weapon();
    void shoot(Orientation, sf::Vector2f, Side, BulletType);
    void lvlUp();
    void setWeapon(WeaponType, int);
    void setWeapon(WeaponType, int, int);
    void straight(Orientation, sf::Vector2f, Side, BulletType);
    void spread(Orientation, sf::Vector2f, Side, BulletType);
    void addBullet(Orientation orientation, sf::Vector2f pos, Side side, BulletType bulletType, sf::Vector2f trajectory);
    int getCoolDown() const;
    void setCoolDown(int coolDown);
};


#endif //RTYPE_WEAPON_H
