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

#include"StepMotor.h"
#include"Arduino.h"


StepMotor::StepMotor(byte pinA_1, byte pinA_2, byte pinB_1, byte pinB_2, int p_step, int p_speed)
{
  pinMode(pinA_1, OUTPUT);
  pinMode(pinA_2, OUTPUT);
  pinMode(pinB_1, OUTPUT);
  pinMode(pinB_2, OUTPUT);
  pin1 = pinA_1;
  pin2 = pinA_2;
  pin3 = pinB_1;
  pin4 = pinB_2;
  StepMotorStep = p_step;
  StepMotorSpeed = p_speed;

}

StepMotor::~StepMotor()
{
  stop();
}

void StepMotor::setMode(int direction)
{
  switch (direction) {
    case 0:
      stop();
      break;
    case 1:
      left();
      break;
    case 2:
      right();
      break;
  }

}
void StepMotor::left() {
  ctlStepMotor(StepMotorStep, StepMotorSpeed);
  stop();
}
void StepMotor::right() {
  ctlStepMotor(-StepMotorStep, StepMotorSpeed);
  stop();
}
void StepMotor::ctlStepMotor(int angle, char speeds) {
  for (int j = 0; j < abs(angle); j++)
  {
    if (angle > 0)
    {
      for (int i = 0; i < 8; i++)
      {
        digitalWrite(pin1, ((tab1[i] & 0x01) == 0x01 ? true : false));
        digitalWrite(pin2, ((tab1[i] & 0x02) == 0x02 ? true : false));
        digitalWrite(pin3, ((tab1[i] & 0x04) == 0x04 ? true : false));
        digitalWrite(pin4, ((tab1[i] & 0x08) == 0x08 ? true : false));
        delay(speeds);
      }
    }
    else
    {
      for (int i = 0; i < 8; i++)
      {
        digitalWrite(pin1, ((tab2[i] & 0x01) == 0x01 ? true : false));
        digitalWrite(pin2, ((tab2[i] & 0x02) == 0x02 ? true : false));
        digitalWrite(pin3, ((tab2[i] & 0x04) == 0x04 ? true : false));
        digitalWrite(pin4, ((tab2[i] & 0x08) == 0x08 ? true : false));
        delay(speeds);
      }
    }
  }
}
void StepMotor:: stop()
{
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
}
