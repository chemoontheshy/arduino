/*
    @name             SoftwareSerialHex
    @description      SoftwareSerial send and receive the Hex.
    @version          1.0
    @date             2020/4/26
    @Author           chemoontheshy
*/
#include <SoftwareSerial.h>
SoftwareSerial portOne(7, 6);
unsigned char hexdata[4] = {0x80,0x80,0x80,0x77};
unsigned char getdata[10];
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);//串口调试波特率
  // Start both software serial ports
  portOne.begin(9600); 
  portOne.write(hexdata,4);
}

void loop() {
  if (portOne.available() > 0) {
    String temp;
    int num;
    while (portOne.available() > 0) {
      getdata[num] = portOne.read();
      num++;
      delay(2);
    }
    portOne.flush();
     Serial.print("Dec: ");
    for (int i = 0; i < 10; i++) {
      Serial.print(getdata[i]);
      Serial.print(" ");
    }
    Serial.println(" ");
    Serial.print("Hex: ");
    for (int i = 0; i < 10; i++) {
      Serial.print(getdata[i],HEX);
      Serial.print(" ");
    }
    Serial.println(" ");
    Serial.print("String: ");
    for (int i = 0; i < 10; i++) {
      Serial.print(char(getdata[i]));
    }
    Serial.println(" ");
  }
  delay(1000);

}


