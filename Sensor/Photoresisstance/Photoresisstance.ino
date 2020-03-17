
#define AD5 A5   //定义模拟口A5
#define LED 10   //定义数字口13

int val = 0;//光照度数值
bool auto_mode = false;
String a;
void setup()  //程序初始化
{
  pinMode(LED, OUTPUT); //设置LED为输出模式
  Serial.begin(115200);//设置波特率9600
}

void loop()//程序主体循环
{
  if (auto_mode == true) {
    automode();
  }
  if (Serial.available() > 0)//received data
  {
    String data;
    while (Serial.available() > 0) {
      data = data + char(Serial.read());
      delay(2);
    }
    a = data;
    Serial.println("a:" + a);

    if (a == "7") {
      Serial.println("First mode");
      analogWrite(LED, 20);
    }
    if (a == "8") {
      Serial.println("Second mode");
      analogWrite(LED, 120);
    }
    if (a == "9") {
      Serial.println("Third mode");
      analogWrite(LED, 255);
    }
    if (a == "6") {
      if (auto_mode == false) {
        Serial.println("automode start");
        auto_mode = true;
      } else {
        Serial.println("automode close");
        auto_mode = false;
      }
    }
  }
}

void automode() {
  val = analogRead(AD5);  //读取模拟口AD5的值，存入val变量
  //  Serial.print("val = ");  //串口输出"val = "
  //  Serial.println(val);     //串口输出val变量的值，并换行
  delay(1000);     //延时1000ms
  analogWrite(LED, val / 4);
  Serial.print("val/4 = ");  //串口输出"val = "
  Serial.println(val / 4);   //串口输出val变量的值，并换行
}

