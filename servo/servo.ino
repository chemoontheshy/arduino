/*
    @name             Servo
    @description      Servo
    @version          1.0
    @date             2020/6/4
    @Author           chemoontheshy
*/
#include <Servo.h>
Servo myservo;
int pos = 90;
void setup() {
  Serial.begin(115200);//串口调试波特率
  myservo.attach(3);
  //
  int a = 0;

  while (a < 5) {
    Serial.print(".");
    a = a + 1;
    delay(500);
  }
  Serial.println("ready");
}

void loop()
{
  if (Serial.available() > 0)//串口接收到数据
  {
    String data;
    while (Serial.available() > 0) {
      data = data + char(Serial.read());
      delay(2);
    }
    Serial.println("data:" + data);
    if (data == "a") {
      for (pos; pos <= 180; pos ++) { // 0°到180°
        // in steps of 1 degree
        myservo.write(pos);              // 舵机角度写入
            delay(2);            // 等待转动到指定角度
      }
    } if (data == "d") {
      for (pos ; pos >= 0; pos --) { // 从180°到0°
        myservo.write(pos);              // 舵机角度写入
        delay(2);                      // 等待转动到指定角度
      }
    } if (data == "s") {
        myservo.write(90);              // 舵机角度写
       delay(5);
    }
  }

}
