/*******************
  ==Arduino==
  @name         StepMotor
  @namespace    qchenmo.com
  @version      1.0
  @description  function: you should see the rocker arm
   of the stepper motor spin clockwise and counterclockwise
   alternatedly Stepper Motor Arduino Uno R3
  @author       chemoontheshy
  @date         2020/10/19
*******************/

#ifndef _StepMotor_H_
#define _StepMotor_H_

//导入Arduino核心头文件
#include"Arduino.h"

const char tab1[] =
{
  0x01, 0x03, 0x02, 0x06, 0x04, 0x0c, 0x08, 0x09
};
const char tab2[] =
{
  0x01, 0x09, 0x08, 0x0c, 0x04, 0x06, 0x02, 0x03
};
class StepMotor
{
  private:
    byte pin1;//A+
    byte pin2;//B-
    byte pin3;//B+
    byte pin4;//B-
    int  StepMotorStep;
    int  StepMotorSpeed;//The shorter the interval,the faster the speed
    int direction;


  public:
    StepMotor(byte pinA_1, byte pinA_2, byte pinB_1, byte pinB_2, int p_step, int p_speed);
    void ctlStepMotor(int angle, char speeds);
    ~StepMotor();
    void setMode(int direction);
    void left();//left
    void right();//right
    void stop();
};

#endif
