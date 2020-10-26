/*******************
  ==Arduino==
  @name         Led.h
  @namespace    qchenmo.com
  @version      1.0
  @description  blink
  @author       chemoontheshy
  @date         2020/6/5
*******************/

#ifndef _Led_H_
#define _Led_H_

//Arduino core header files
#include "Arduino.h"

class Led
{
  private:
    byte PIN;//PWM
   
  public:
    Led();// Constructor
    ~Led();
    void attach(byte pin);//sets the servo position according to the scaled value
    void on();
    void off();
};
#endif


