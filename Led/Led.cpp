/*******************
  ==Arduino==
  @name         Led.h
  @namespace    qchenmo.com
  @version      1.0
  @description  Blink
  @author       chemoontheshy
  @date         2020/6/5
*******************/

#include"Led.h"
#include"Arduino.h"


Led::Led()
{

}

Led::~Led()
{
}

void Led::attach(byte pin) {
  PIN = pin;
  pinMode(PIN, OUTPUT);
}
void Led::on() { //Define an impulse function
    digitalWrite(PIN, HIGH);
}
void Led::off() { //Define an impulse function
    digitalWrite(PIN, LOW);
}
