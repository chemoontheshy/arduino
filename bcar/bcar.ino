int  left_a = 9;
int  left_b = 10;
int  right_a = 11;
int  right_b = 12;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);//serial baud rate
  pinMode(left_a, OUTPUT);
  pinMode(left_b, OUTPUT);
  pinMode(right_a, OUTPUT);
  pinMode(right_b, OUTPUT);

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
    if (data == "w") {
      Serial.println("w");
      forward();
    } if (data == "s") {
       Serial.println("s");
      stopward();
    } if (data == "x") {
       Serial.println("x");
      backward();
    } if (data == "a") {
       Serial.println("a");
      leftward();
    } if (data == "d") {
       Serial.println("d");
      rightward();
    }
  }
}
void forward() {
  digitalWrite(left_a, HIGH);
  digitalWrite(left_b, LOW);
  digitalWrite(right_a, HIGH);
  digitalWrite(right_b, LOW);
}
void backward() {
  digitalWrite(left_a, LOW);
  digitalWrite(left_b, HIGH);
  digitalWrite(right_a, LOW);
  digitalWrite(right_b, HIGH);
}
void leftward() {
  digitalWrite(left_a, LOW);
  digitalWrite(left_b, HIGH);
  digitalWrite(right_a, HIGH);
  digitalWrite(right_b, LOW);
}
void rightward() {
  digitalWrite(left_a, HIGH);
  digitalWrite(left_b, LOW);
  digitalWrite(right_a, LOW);
  digitalWrite(right_b, HIGH);
}
void stopward() {
  digitalWrite(left_a, LOW);
  digitalWrite(left_b, LOW);
  digitalWrite(right_a, LOW);
  digitalWrite(right_b, LOW);
}

