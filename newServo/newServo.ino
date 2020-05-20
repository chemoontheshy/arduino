/*
    @name             demo
    @description      调试串口，发送命令
    @version          1.0
    @date             2020/3/9
    @Author           chemoontheshy
*/

int servoPin = 4;    //定义舵机接口数字接口7 也就是舵机的橙色信号线。
int nowPos = 90;
void setup() {
  pinMode(servoPin, OUTPUT); //设定舵机接口为输出接口
  Serial.begin(115200);//串口调试波特率
  servo(nowPos);
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
    int sd = data.toInt();
    servo(sd);
    delay(600);
  }
}

void servo(int angle) { //定义一个脉冲函数
  //发送50个脉冲
  for (int i = 0; i < 50; i++) {
    int pulsewidth = (angle * 11) + 500; //将角度转化为500-2480的脉宽值
    digitalWrite(servoPin, HIGH);   //将舵机接口电平至高
    delayMicroseconds(pulsewidth);  //延时脉宽值的微秒数
    digitalWrite(servoPin, LOW);    //将舵机接口电平至低
    delayMicroseconds(20000 - pulsewidth);
  }
  delay(100);
}

