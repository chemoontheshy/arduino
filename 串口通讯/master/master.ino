/*
    @name             demo
    @description      调试串口，发送命令
    @version          1.0
    @date             2020/3/9
    @Author           chemoontheshy
*/
 int i = 10;
void setup() {
  Serial.begin(9600);//串口调试波特率
  //
 
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
    Serial.print(data);
  }
}
