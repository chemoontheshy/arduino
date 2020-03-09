/*******************
  ==Arduino==
  @name         Stepper
  @namespace    qchenmo.com
  @version      1.0
  @description  4（5）线步进电机库例程，四相电机,头文件
  @author       chemoontheshy
  @date         2020/3/7

*******************/

#ifndef _STEPPER_H_
#define _STEPPER_H_

//导入Arduino核心头文件
#include"Arduino.h"


class STEPPER
{
  private:
    byte pin1;//A+
    byte pin2;//B-
    byte pin3;//B+
    byte pin4;//B-
    int  Stepperspeed;//间隔越短，速度越快
    int direction;

  public:
    STEPPER(byte pinA_1, byte pinA_2, byte pinB_1, byte pinB_2,int p_speed);
    void steprun(int direction);
    void left();//左转
    void right();//右转
    ~STEPPER();
    void stop(); 

};

#endif
