# timing

Debounce Library

This library allow setting reading button state for certain amount of time, in order to insure reading only single input and prevent false reading due to bouncing. (Bouncing is the tendency of any two metal contacts in an electronic device to generate multiple signals as the contacts close or open; debouncing is any kind of hardware device or software that ensures that only a single signal will be acted upon for a single opening or closing of a contact) 

Instructions:
1.	Create new Debounce object using Debounce(int pin, int interval) constructor. Pin is the pin number on which the component is connected, interval is the Debounce time interval between the start and end of reading process. 50 is usually a good choice (5 milliseconds).
2.	Use int readState() to read the state of the component. will return 1 or 0.

