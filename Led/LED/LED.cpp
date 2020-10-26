/*******************
  ==Arduino==
  @name         Stepper
  @namespace    qchenmo.com
  @version      0.1
  @description  4（5）线步进电机库例程，四相电机,主文件
  @author       chemoontheshy
  @date         2020/3/7

*******************/

#include"LED.h"
#include"Arduino.h"


LED::LED(int ledRight, int ledLeft)
{
  ledR = ledRight;
  ledL = ledLeft;
  pinMode(ledR, OUTPUT);
  pinMode(ledL, OUTPUT);
}

void LED::Led(int r, int l)
{
  if (r == HIGH ) {
    digitalWrite(ledR, HIGH);
  } else if (r == LOW ) {
    digitalWrite(ledR, LOW);
  }  if ( l ==HIGH) {
    digitalWrite(ledL, HIGH);
  } else if ( l == LOW) {
    digitalWrite(ledL, LOW);
  }
 delay(200);

}
