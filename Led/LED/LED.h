/*******************
  ==Arduino==
  @name         Stepper
  @namespace    qchenmo.com
  @version      0.1
  @description  4（5）线步进电机库例程，四相电机,头文件
  @author       chemoontheshy
  @date         2020/3/7

*******************/

#ifndef _LED_H_
#define _LED_H_

//导入Arduino核心头文件
#include"Arduino.h"

class LED
{
  private:
    int ledR;//R
    int ledL;//L

  public:
    LED(int ledRight, int ledLeft);
    void Led(int r,int l);

};

#endif
