// Created by Elchay Rauper
// Last modified on 01/12/2015

#ifndef DEBOUNCE_H
#define DEBOUNCE_H

#include "Arduino.h"
#include "timer.h"

//TODO: edit this lib
//TODO: test this lib

class Debounce
{
private:
    Timer _timer;
    int _pin;

public:
    Debounce(int interval)
    {
            _timer.setDelay(interval);
    }
    
    //returns -1 while debounce still running, or the state when done
    int readState(int pin)
    {
         _timer.start();

        if (_timer.finished())
            return digitalRead(pin); //done reading button state

        return -1; //still reading button state
    }
};

#endif //DEBOUNCE_H
