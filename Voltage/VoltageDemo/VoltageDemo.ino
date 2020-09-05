/*
    @name             MVoltage demo
    @description      利用ADC差分来测量电压24V电压，
                      中位值滤波法去掉噪音
                      根据电压来确定电池电量
                      调用库文件
    @version          1.0
    @date             2020/8/19
    @Author           chemoontheshy
    @note             1.校准，基于MCU的标准电压（每个电压都不一样）

*/
#include"Voltage.h"

//adc pin
byte adcA = A2;
byte adcB = A0;
//current Voltage ,By mesurement we know that
float reVol = 4.74;
//min Vol
float minVol = 18.0;
//max Vol
float maxVol = 25.2;
//min Vol
float lowCoe = 0.2;
//min Vol
float highCoe = 0.8;
//new Voltge;
Voltage voltage;
void setup() {
  // put your setup code here, to run once:
  voltage.init(adcA, adcB, reVol);
  voltage.setPower(minVol, maxVol, lowCoe, highCoe);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  float nowVoltage =  voltage.Filter();
  Serial.print("nowVoltage: ");
  Serial.println(nowVoltage);
  float currentPower =  voltage.currentPower();
  Serial.print("currentPower: ");
  Serial.println(currentPower);
  int alarm =  voltage.alarm();
  Serial.print("alarm: ");
  Serial.println(alarm);
  delay(1000);
}
