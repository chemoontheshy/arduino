
/*
    @name             Hex to decimal
    @description      Hex to decimal
    @version          1.4
    @date             2020/3/13
    @Author           chemoontheshy
*/
#include"Hex2dec.h"
Hex2dec hex2dec;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);//serial baud rate
}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available() > 0)//received data
  {
    String data;
    while (Serial.available() > 0) {
      data = data + char(Serial.read());
      delay(2);
    }
    Serial.println("data:" + data);
    String hex = data;
    String dec;
    /*
      (String hex,char ' ')
      参数1，输入的需要转换的16进制（String）
      参数2，输入分隔符，默认‘ ’（默认空格，）NUll也可以，但是会报警告。（char）
    */
    dec = hex2dec.getsDec(hex, ',');
    //    long dec = todec(hex);
    Serial.print("dec: ");
    Serial.println(dec);
    Serial.print("hex: ");
    Serial.println(hex);
  }
}
