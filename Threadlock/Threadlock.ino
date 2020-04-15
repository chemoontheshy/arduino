#define PIN 3
#define switchA 6
String data;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(115200);
  pinMode(PIN, OUTPUT);
  pinMode(switchA, INPUT_PULLUP);
  //digitalWrite(PIN, HIGH);
}

// the loop function runs over and over again forever
void loop() {
  int val = digitalRead( switchA);
  if (val == HIGH) {
    digitalWrite(PIN, LOW);
    Serial.println("LOW");
  } else {
    digitalWrite(PIN, HIGH);
    Serial.println("HIGH");
  }
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
