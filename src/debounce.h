// Created by Elchay Rauper
// Last modified on 01/12/2015

#ifndef DEBOUNCE_H
#define DEBOUNCE_H

#include "Arduino.h"
#include "../timer/Timer.h"

//TODO: edit this lib
//TODO: test this lib

class Debounce
{
private:
    Timer _timer;
    int _state;
    int _pin;

public:
    Debounce(int pin, int interval);
    int readState();
};

#endif //DEBOUNCE_H
