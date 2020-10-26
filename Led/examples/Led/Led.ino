#include "Led.h"
#define ledPin 7
Led led;
void setup() {
  // put your setup code here, to run once:
  led.attach(ledPin);
   Serial.begin(115200);//串口调试波特率
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0)//串口接收到数据
  {
    String data;
    while (Serial.available() > 0) {
      data = data + char(Serial.read());
      delay(2);
    }
      if (data == "a") {
      led.on();
    } if (data == "d") {
      led.off();
    } 
  }
}
