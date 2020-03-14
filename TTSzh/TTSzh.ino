/*
    @name             TTS中文播报器
    @description      TTS转中文语言播报
    @version          1.0
    @date             2020/3/9
    @Author           chemoontheshy
*/
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);//串口调试波特率
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
    if(data=="1"){
        Serial.println("你好");
      
    }else if(data=="2"){
        Serial.println("再见");
    }else if(data=="3"){
        Serial.println("有什么可以帮到你？");
    }else if(data=="4"){
        Serial.println("我不会，很抱歉");
    }else if(data=="5"){
        Serial.println("你叫什么名字");
    }else if(data=="6"){
        Serial.println("很高兴认识你");
    }
    
  }

}
