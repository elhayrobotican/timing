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
    int newState = digitalRead(_pin);

    _timer.start();

    if (_state != newState)
        _state = newState;
    if (_timer.finished())
        return _state; //done reading button state

    return -1; //still reading button state
}