/***************************************************************
* This example demostrate the use of led-strober lib
* The example listens to serial inputs, and determine
* the board state accordingly. The example uses led-strober
* to blink the led according to the board's current state.
* e.g. for emergency state, the led will blink like strobe light.
****************************************************************/


#include "timing.h"

#define INDICATOR_LED 13
#define EMERGENCY_CH 'E'
#define NORMAL_CH 'N'

Strober strober;
bool emergency_mode;

void setup() 
{
    Serial.begin(9600);
    pinMode(INDICATOR_LED, OUTPUT);
    emergency_mode = false;
    //set initial blinking notes
    strober.setNotes(Strober::Notes::BLINK_SLOW);
}

void loop() 
{
  //play() must be invoked in loop  
  strober.play(INDICATOR_LED);
  char ch = Serial.read();
  
  if (ch == 'E' && !emergency_mode)
  {
    emergency_mode = true;
    Serial.println("Emergency mode on");
    //set notes to STROBE for strobe blinking
    //(in this case: indicates emergency button 
    //was pressed and emergency mode is on)
    strober.setNotes(Strober::Notes::STROBE);
  } 
  else if (ch == 'N' && emergency_mode)
  {
    emergency_mode = false;
    Serial.println("Emergency mode off");
    //set notes to BLINK_SLOW for slow blinking
    //(in this case indicates emergency mode is off)
    strober.setNotes(Strober::Notes::BLINK_SLOW);
  }
}
