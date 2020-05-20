#include <EEPROM.h>
int addr;
char val;
int address = 0;
byte value;

void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:

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
    if (data == "1") {
      addr = 1;
      val = 1;
      EEPROM.write(addr, val);//addr地址val 数值
    }
    if (data == "2") {
      address = 1;
      value = EEPROM.read(address);
      Serial.print("data:");
      Serial.println( value);
    }

  }
}
