

#ifndef DEBOUNCE_H
#define DEBOUNCE_H

#include "timer.h"

#define STILL_READING -1

class Debounce
{
private:
    Timer timer_;
    uint8_t pin_;
    uint16_t interval_;

public:

    Debounce(int interval) { interval_ = interval; }

    /***********************************************
    * Return -1 if reading is in process, and 0 or 1
    * when reading is done
    ************************************************/
    int readState(int pin)
    {
      timer_.start(interval_);
      
      if (timer_.finished())
        return digitalRead(pin); 
      
      return STILL_READING; 
    }
};

#endif //DEBOUNCE_H
