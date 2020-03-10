/*
    @name             Hex to decimal
    @description      Hex to decimal
    @version          1.0
    @date             2020/3/9
    @Author           chemoontheshy
*/
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);//serial baud rate
}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available() > 0)//received data
  {
    String data;
    while (Serial.available() > 0) {
      data = data + char(Serial.read());
      delay(2);
    }
    Serial.println("data:" + data);
    String hex = data;
    String dec;
    dec = todec(hex);
    //    long dec = todec(hex);
    Serial.print("dec: ");
    Serial.println(dec);
    Serial.print("hex: ");
    Serial.println(hex);
  }
}
String todec(String hex) {
  String sdec;
  char arr[hex.length() + 1];
  char narr[hex.length() + 1];
  hex.toCharArray(arr, hex.length() + 1);
  int num = 0;
  char c[2];
  for (int i = 0; i < hex.length() + 1; i++) {
    if (arr[i] != ' ') {
      c[num] = arr[i];
      num = num + 1;
      if (num == 2) {
        long lchar;
        lchar = strtol(c, NULL, 16);
        sdec = sdec + lchar;
      }
    } else {
      sdec = sdec + ' ';
      num = 0;
      sprintf(c, "") ;
    }
  }
  sdec.toCharArray(narr, hex.length() + 1);
  Serial.print("sdec:");
  Serial.println(sdec);
  Serial.print("narr:");
  Serial.println(narr);
  Serial.print("arr:");
  Serial.println(arr);
  return sdec;
}


