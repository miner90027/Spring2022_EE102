/* EE102 Lab-Frequency and Duty Cycle 
   Check to see if the TimerOne-r11 library is already included in your list of libraries:
   Click on: Sketch>Include Library> TimerOne-r11
   
   If not found in libraries you must download the "*.zip" file to your PC/Mac then un-zip and 
   include the file in your Arduino Library:
   
   Download file can be found at the following link: 
   TimerOne library can be downloaded and included in your Arduino Library by
   Downloading from: https://code.google.com/p/arduino-timerone/downloads/detail?name=TimerOne-r11.zip&can=2&q=
   
   Include in your Arduino IDE Library as follows:
   Sketch > Include Library > Add .ZIP library > Timer1
   
   Additional information about TimerOne can be found at:
   http://playground.arduino.cc/Code/Timer1
   
   Sketch reference from: "Programming Arduino: Next Steps, Going Further with Sketches",(p66)
   by Simon Monk
   Copyright 2014 by McGraw-Hill Education
*/

#include <TimerOne.h> // includes the family of functions used to access the ATmega168/328 16 bit hardware timer

void setup() {
  // Only pin D9 and pin D10 for the Arduion Micro will work with the Timer1 functions
  
pinMode(9, OUTPUT);           // Identify pin D9 as an output pin

Timer1.initialize();          // initialize(period) = Must call this method first to use any other methods.
                              // Optionally specifie timer's period here (in microseconds). 
 
Timer1.pwm(9, (1023 * 0.3), 40000); // pwm(pin, duty, period) = generates waveform on specified pin.
                             // Duty cycle is specified between 0 and 1023.  Period specified in microseconds.
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
