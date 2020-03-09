/*
    @name             RGB
    @description      RGB demo
    @version          1.2
    @date             2020/3/9
    @Author           chemoontheshy
*/
int r = 9;
int g = 10;
int b = 11;
void setup() {
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
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
    if (data.indexOf("#") > -1) {
      data = data.substring(1);
      String rb = data.substring(4);
      String rg = data.substring(2, 4);
      String rr = data.substring(0, 2);
      long cr = hextodec(rr);
      long cg = hextodec(rg);
      long cb = hextodec(rb);
      Serial.println(cr);
      Serial.println(cg);
      Serial.println(cb);
      digitalWrite(r, cr);   // 点亮r
      digitalWrite(g, cg);   // 点亮g
      digitalWrite(b, cb);   // 点亮b
    }
  }
}
long hextodec(String hex) {
  long dec;
  char arr[hex.length() + 1];
  hex.toCharArray(arr, hex.length() + 1);
  //Serial.println(arr);
  dec = strtol(arr, NULL, 16);
  return dec;
}
