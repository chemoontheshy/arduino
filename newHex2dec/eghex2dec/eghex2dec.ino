
/*
    @name             Hex2dec
    @description      Hex to decimal
    @version          1.0
    @date             2020/3/13
    @Author           chemoontheshy
*/
#include"Hex2dec.h"
Hex2dec hex2dec;
void setup() {
  Serial.begin(115200);//serial baud rate
  // put your setup code here, to run once:
  String hex1 = "#F10423";
  String hex2 = "D1 03 68";
  String hex3 = "D1,03,8";
  String dec1;
  String dec2;
  String dec3;
  dec1 = hex2dec.getsDec(hex1, '#');
  dec2 = hex2dec.getsDec(hex2, ' ');
  dec3 = hex2dec.getsDec(hex3, ',');
  //    long dec = todec(hex);
   Serial.print("hex1: ");
  Serial.println(hex1);
  Serial.print("dec1: ");
  Serial.println(dec1);
  Serial.print("hex2: ");
  Serial.println(hex2);
  Serial.print("dec2: ");
  Serial.println(dec2);
  Serial.print("hex3: ");
  Serial.println(hex3);
  Serial.print("dec3: ");
  Serial.println(dec3);
 

}

void loop() {
  // put your main code here, to run repeatedly:

}
