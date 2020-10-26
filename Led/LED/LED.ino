#include"LED.h"
String data;
#define pinL 12
#define pinR 11
LED led(pinL, pinR);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    receive();
    if (data == "a") {
      led.Led(HIGH, LOW);
    }
    if (data == "s") {
      led.Led(LOW, LOW);
    }
    if (data == "w") {
      led.Led(HIGH, HIGH);
    }
     if (data == "d") {
      led.Led(LOW, HIGH);
    }
  }
}
void receive() {
  data = "";
  while (Serial.available() > 0) {
    data = data + char(Serial.read());
    delay(2);
  }
  Serial.println("data:" + data);
}
