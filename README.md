# Timing Library
Timing library is a combination of time-based tools for fast and easy usage.
This readme file explain and demonstrate the use of these tools

----------------------------------------------------------------------
## 1. Debounce 
If you are using a physical button on your board, and trying to digitaRead() from it, you might want to use Debounce to make sure the reading is correct. Bouncing is the tendency of any two metal contacts in an electronic device to generate multiple signals as the contacts close or open; debouncing is any kind of hardware device or software that ensures that only a single signal will be acted upon for a single opening or closing of a contact) 

### 1.1 Usage:
1. Create Debounce instance using Debounce(int pin, int interval) constructor. Interval param is the Debounce time interval between the start and end of reading process. 50 is usually a good choice (5 milliseconds).
2. Invoke readState() to read the state of the component. Will return 1 or 0 when done reading, or -1 if reading is still in process.
----------------------------------------------------------------------

## 2. Strober
Light your board led with predefined or custom patterns. Strober is a great tool for when you writing Arduino software, and want one of your board leds to operate as an indicator to all kind of situatuions, allowing you quicker debugging and getting info about the board current state.

### 2.1 Prerequisite
Strober depends on Timer class to operate properly. Timer class is included in Timing library.

### 2.2 Usage
Using strober is easy. 
1. include strober header. e.g.
```
#include "strober.h"
```

2. Create new Strober instance. e.g.
```
Strober strober;
```

3. Set initial led notes. e.g.
```
void setup()
{
  ...
  strober.setNotes(Strober::Notes::BLINK_SLOW);
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
    strober.setNotes(Strober::Notes::STROBE);
  else if (y)
    strober.setNotes(Strober::Notes::BLINK_FAST);
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

For full example go to [here](https://github.com/elhayr1/timing/blob/master/examples/emergency_monitor/emergency_monitor.ino).

----------------------------------------------------------------------

# 3. Timer
Async timer

This library allow you to set and use timers easily over Arduino platform. Timer implementation is asynchroncally, meaning your microcontroller loop will keep running, as opposed to Arduino's delay() function for example. This is very important if you want your board to keep doing thing in the background while using timer.

# 3.1 Usage
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
The code in the example above wait for heartbit package input. If no heartbit is received within one second, the program will pring "TIMEOUT" message. If heartbit is received within one second, timer is starting over again and waiting for next heartbit.
Although start() is invoked inside loop(), timer will only start once. Only after timer finish, start() method will cause it to start again. If you wish to start timer again before it's finished, invoke startOver();
