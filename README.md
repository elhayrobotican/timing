# timing

# Debounce Library

This library allow setting reading button state for certain amount of time, in order to insure reading only single input and prevent false reading due to bouncing. (Bouncing is the tendency of any two metal contacts in an electronic device to generate multiple signals as the contacts close or open; debouncing is any kind of hardware device or software that ensures that only a single signal will be acted upon for a single opening or closing of a contact) 

Instructions:
1.	Create new Debounce object using Debounce(int pin, int interval) constructor. Pin is the pin number on which the component is connected, interval is the Debounce time interval between the start and end of reading process. 50 is usually a good choice (5 milliseconds).
2.	Use int readState() to read the state of the component. will return 1 or 0.

# led-strober
Arduino library allowing easy control over predefined indicator led light patterns

led-strober is a great tool for when you writing Arduino software, and want one of your board leds to operate as an indicator to all kind of situatuions, allowing you quicker debugging and give you info about the board current state.

## Prerequisite
led-strober depends on my timer library to operate properly. You can get my timer library [here](https://github.com/elhayr1/timer/tree/master/src).
Just insert timer src files into led-strober src folder, and you are set to go. 

## Usage
Using led-strober library is easy. 
1. include led-strober header. e.g.
```
#include "led_strober.h"
```

2. Create new LedStrober instance. e.g.
```
LedStrober strober;
```

3. Set initial led notes. e.g.
```
void setup()
{
  ...
  strober.setNotes(LedStrober::LedNotes::BLINK_SLOW);
  ...
}
```

4. Invoke play() method inside loop(), and set notes in run time according to your needs. e.g.
```
void loop()
{
  strober.play(INDICATOR_LED);
  ...
  ...
  if (x)
    strober.setNotes(LedStrober::LedNotes::STROBE);
  else if (y)
    strober.setNotes(LedStrober::LedNotes::BLINK_FAST);
}
```

You can also invoke setNotes with a custom made notes array. e.g.
```
int16_t custom_notes[4] = {1, 500, 0, 500};
strober.setNotes(custom_notes, 4);
```
Array size must be even, because each note is a pair i.e. [note, interval], so the array look like so:
(note, interval, note, interval, ..., note, interval)
note value can be 0 or 1, and interval is the time (in milliseconds) to wait asynchronically before playing next note.

For full example go to [here](https://github.com/elhayr1/led-strober/blob/master/examples/emergency_monitor/emergency_monitor.ino).


# timer
Async timer library for Arduino

This library allow you to set and use timers easily over Arduino platform. Timer implementation is asynchroncally, meaning your microcontroller loop will keep running, as opposed to Arduino's delay() function for example.

# Usage
Include Timer header file
```
#include "timer.h"
```

Create a new Timer instance
```
Timer keep_alive_timer;
```

Start the timer, and do something when it's finished

```
void loop()
{
  ...
  ...
  keep_alive_timer.start(1000);
  if (heartbit_recved)
    keep_alive_timer.startOver();
  else if (keep_alive_timer.finished())
    Serial.println("TIMEOUT");
  ...
  ...
}
```
The code in the example above wait for heartbit package input. If no heartbit is received within one second, the program will pring "TIMEOUT" message. I heartbit is received within one second, timer is starting over and waiting for next heartbit.
Although start() is invoked inside loop(), timer will only start once. Only after timer finish, start() method will cause it to start again. If you wish to start timer again before it's finished, invoke startOver();

Timer is used in my led-strober library. You can find led-strober library [here](https://github.com/elhayr1/led-strober).


