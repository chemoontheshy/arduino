#include"hz.c"
  
void setup() {
  
   Serial.begin(115200);
  
   Serial.println(hz[1]);
  
   Serial.println(hz[2]);
  
}
  
  
void loop()
  
{
  
   int sensorValue = analogRead(A0);
  
   float vol = sensorValue * 2.5 / 1024;
  
   Serial.print(hz[0]); Serial.print(vol, 2);  Serial.println("V");
  
   delay(150);
  
}
