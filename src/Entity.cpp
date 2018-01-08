//
// Created by Eric on 29/11/2017.
//

#include "Entity.h"

Entity::Entity() {
    shootCooldown = 0;
    hp = 100;
    orientation = Orientation::VERTICAL;
}

Entity::~Entity() {
}

int Entity::getHp() const {
    return hp;
}

void Entity::setHp(int hp) {
    Entity::hp = hp;
}

const sf::Vector2f &Entity::getPos() const{
    return pos;
}

void Entity::setPos(const sf::Vector2f &pos) {
    Entity::pos = pos;
}

Stance Entity::getStance() const {
    return stance;
}

void Entity::setStance(Stance stance) {
    Entity::stance = stance;
}

void Entity::drawSprite(sf::RenderWindow &App) {
    sprites[(int)stance].drawFrame(App, pos, orientation);
}

void Entity::move(sf::Vector2f mov) {
    pos.x += ((int)mov.x * speed);
    if (pos.x < 0)
        pos.x = 0;
    else if (pos.x > WIN_WIDTH)
        pos.x = WIN_WIDTH;
    pos.y += ((int)mov.y * speed);
    if (pos.y < 0)
        pos.y = 0;
    else if (pos.y > WIN_HEIGHT)
        pos.y = WIN_HEIGHT;
}

void Entity::changeOrientation(Orientation newOrientation) {
    if (orientation != newOrientation) {
        float percentx = pos.x / (float)WIN_WIDTH;
        float percenty = pos.y / (float)WIN_HEIGHT;
        float previousx = trajectory.x;
        float previousy = trajectory.y;
        if (newOrientation == Orientation::HORIZONTAL) {
            pos.x = (1.f - percenty) * (float) WIN_WIDTH;
            trajectory.x =  - previousy;
        }
        else if (newOrientation == Orientation::VERTICAL) {
            pos.x = (percenty) * (float) WIN_WIDTH;
            trajectory.x =  previousy;
        }
        if (newOrientation == Orientation::HORIZONTAL) {
            pos.y = percentx * (float) WIN_HEIGHT;
            trajectory.y =  previousx;
        }
        else if (newOrientation == Orientation::VERTICAL) {
            pos.y = (1.f - percentx) * (float) WIN_HEIGHT;
            trajectory.y =  - previousx;
        }
        orientation = newOrientation;
    }
}

bool Entity::outOfBounds() {
    return !(pos.x < 0 || pos.y < 0 || pos.x > WIN_WIDTH || pos.y > WIN_HEIGHT);
}

void Entity::setTrajectory(const sf::Vector2f &newTrajectory) {
    trajectory = newTrajectory;
}

Orientation Entity::getOrientation() const {
    return orientation;
}

void Entity::setOrientation(Orientation orientation) {
    Entity::orientation = orientation;
}