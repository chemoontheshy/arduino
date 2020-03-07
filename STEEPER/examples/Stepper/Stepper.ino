/*******************
  ==Arduino==
  @name         Stepper
  @namespace    qchenmo.com
  @version      0.1
  @description  4（5）线步进电机库例程，四相电机
  @author       chemoontheshy
  @date         2020/3/7

*******************/

#include"STEPPER.h"
int stepperSpeed = 6000;
#define Stepper_stop 0//停止
#define Stepper_left 1//正转
#define Stepper_right 2//反转
int Stepper_mode = 0; //模式
STEPPER stepper(8, 9, 10, 11, stepperSpeed);//定义针脚和速度
int incomedate = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

}

void loop() {
  if (Serial.available() > 0) {
    receive();
  }
  stepperrun();
}

void receive() {
  int pos = 0;
  String data;
  while (Serial.available() > 0) {
    data = data + char(Serial.read());
    delay(2);
  }
  Serial.println("data:" + data);
  if (data == "a") {
    Stepper_mode = 1;
  } else if (data == "s") {
    Stepper_mode = 0;
  } else if (data == "d") {
    Stepper_mode = 2;
  }
  delay(200);

}

void stepperrun() {
  switch (Stepper_mode) {
    case 0:
      stepper.steprun(Stepper_stop);
      break;
    case 1:
      stepper.steprun(Stepper_left);
      break;
    case 2:
      stepper.steprun(Stepper_right);
      break;
  }
}

