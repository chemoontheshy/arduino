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
    //Serial.println("data:" + data);
    String hex = data;
    long dec = todec(hex);
    Serial.print("dec: ");
    Serial.println(dec);
    Serial.print("hex: ");
    Serial.println(hex);
  }
}
long todec(String hex) {
  long dec;
  char arr[hex.length() + 1];
  hex.toCharArray(arr, hex.length() + 1);
  //Serial.println(arr);
  dec = strtol(arr, NULL, 16);
  return dec;
}
