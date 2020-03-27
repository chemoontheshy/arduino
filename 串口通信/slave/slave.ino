#define PIN 3
String data;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(115200);
  pinMode(PIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
    if (Serial.available() > 0) {
    receive();
    if(data=="a"){
       digitalWrite(PIN, HIGH);  
    }
     if(data=="s"){
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
