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

#define IN1 A0
#define IN2 A1
#define IN3 A2
#define IN4 A3
int myStep = 32;
int mySpeed = 1;
StepMotor stepMotor(IN1, IN2, IN3, IN4, myStep, mySpeed);
//
#define Stepper_stop 0//停止
#define Stepper_left 1//正转
#define Stepper_right 2//反转
int Stepper_mode = 0; //模式
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  //put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    receive();
  }
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
    stepMotor.left();
  }  else if (data == "d") {
    stepMotor.right();
  }
  delay(200);

}
