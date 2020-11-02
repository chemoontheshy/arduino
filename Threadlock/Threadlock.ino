#define PIN 3 //输出针脚
#define switchA 6 //输入针脚（接微动开关）
String data;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(115200);
  pinMode(PIN, OUTPUT);
  pinMode(switchA, INPUT_PULLUP);//INPUT_PULLUP自带上拉不需要自己另外接上位电阻
  //digitalWrite(PIN, HIGH);
}

// the loop function runs over and over again forever
void loop() {
  int val = digitalRead( switchA);
  //可以通过触碰（微动）开关获取一个信号，改变灯的开关
  if (val == HIGH) {
    digitalWrite(PIN, LOW);
    Serial.println("LOW");
  } else {
    digitalWrite(PIN, HIGH);
    Serial.println("HIGH");
  }
  //可以通过串口控制
  if (Serial.available() > 0) {
    receive();
    if (data == "a") {
      digitalWrite(PIN, HIGH);
    }
    if (data == "s") {
      digitalWrite(PIN, LOW);
    }
  }                     // wait for a second
}

void receive() {
  data = "";
  while (Serial.available() > 0) {
    data = data + char(Serial.read());
    delay(2);
  }
  Serial.println("data:" + data);
  Serial.print("datasize:");
  Serial.println(data.length());
}
