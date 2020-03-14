/*
    @name             Hex to decimal
    @description      Hex to decimal
    @version          1.3
    @date             2020/3/11
    @Author           chemoontheshy
*/

#include"Hex2dec.h"
String hex = "#FE04D0";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);//serial baud rate
  Hex2dec hex2dec;
  String sdec = hex2dec.getsDec(hex,'#');
  Serial.println("hex:" + hex);
  Serial.println("sdec:" + sdec);
}

void loop() {
  // put your main code here, to run repeatedly:

}
