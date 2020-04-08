// defines pins numbers
const int stepPin = 5;
const int dirPin = 6;
const int Ena = 7;
String flag;
void setup() {
  // Sets the two pins as Outputs
  Serial.begin(115200);//串口调试波特率
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(Ena,  OUTPUT);
  digitalWrite(Ena,HIGH);
}
void loop() {
  if (Serial.available() > 0)//串口接收到数据
  {
    readSerial();
  }
  if (flag == "a") {
    forward();
  }
  if (flag == "d") {
    backward();
  }

}
void readSerial() {
  String data;
  while (Serial.available() > 0) {
    data = data + char(Serial.read());
    delay(2);
  }
  Serial.println("data:" + data);
  if (data == "a") {
    flag = "a";
  }
  if (data == "s") {
    flag = "s";
    digitalWrite(Ena, HIGH);
  }
    if (data == "w") {
    flag = "w";
    digitalWrite(Ena,LOW);
  }
  if (data == "d") {
    flag = "d";
  }
   if (data == "e") {
    flag = "e";
  }
}
void forward() {
  digitalWrite(dirPin, HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for (int x = 0; x < 200; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(800);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(800);
  }
  delay(10); // One second delay
}
void backward() {
  digitalWrite(dirPin, LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for (int x = 0; x < 200; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(800);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(800);
  }
  delay(10); // One second delay
}

