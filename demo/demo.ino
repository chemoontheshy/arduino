/*
 *  @name             demo
 *  @description      Writing template
 *  @version          1.0
 *  @date             2020/3/9
 *  @Author           chemoontheshy
 */
void setup() {
  Serial.begin(115200);//串口调试波特率
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

   
  }
