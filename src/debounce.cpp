// Created by Elchay Rauper
// Last modified on 01/12/2015

#include "Debounce.h"

Debounce::Debounce(int pin, int interval)
{
    _pin = pin;
    _state = digitalRead(pin);
    _timer.setDelay(interval);
}

//returns -1 while debounce still running, or the state when done
int Debounce::readState()
{
    _timer.start();

    if (_timer.finished())
        return digitalRead(_pin); //done reading button state

    return -1; //still reading button state
}
