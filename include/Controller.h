//
// Created by Loic on 04/12/2017.
//

#ifndef RTYPE_CONTROLLER_H
#define RTYPE_CONTROLLER_H


#include <SFML/Window/Joystick.hpp>

class Controller {
public:
    Controller();

    virtual ~Controller();

private:
    bool connected;
public:
    bool isConnected() const;

private:
    unsigned int buttons;
    bool pressed;
};


#endif //RTYPE_CONTROLLER_H
