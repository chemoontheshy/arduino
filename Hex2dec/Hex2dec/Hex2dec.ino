/*******************
  ==Arduino==
  @name         Hex2dec
  @namespace    qchenmo.com
  @version      1.0
  @description  hex to dec demo
  @author       chemoontheshy
  @date         2020/3/9

*******************/
#include "Hex2dec.h"
String hex = "e8d05f4";
long dec;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);//serial baud rate

  Hex2dec hex2dec(hex);
  dec = hex2dec.getDec();
   Serial.print("dec: ");
   Serial.print(dec);
}

void loop() {
  // put your main code here, to run repeatedly:


}
