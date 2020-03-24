  
/**
 * HDC1080例程
 * @author 沉默
 * @date 2019/09/21
 */
#include <ClosedCube_HDC1080.h>
ClosedCube_HDC1080 hdc1080;
 
void setup()
{
  Serial.begin(115200);
  hdc1080.begin(0x40);
}
 
void loop()
{
  Serial.print("Temperature: ");
  Serial.print(hdc1080.readTemperature());
  Serial.println(".");
  Serial.print("Humidity: ");
  Serial.print(hdc1080.readHumidity());
  Serial.println( "%");
  delay(2000);
 
 
}
