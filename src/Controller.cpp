//
// Created by loic on 04/12/2017.
//

#include "Controller.h"

Controller::~Controller()
{

}

Controller::Controller()
{
    connected = sf::Joystick::isConnected(0);
}

bool Controller::isConnected() const
{
    return connected;
}
