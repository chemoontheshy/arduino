/*******************
  ==Arduino==
    @name             MVoltage.h
    @description      利用ADC差分来测量电压24V电压，
                      中位值滤波法去掉噪音
                      根据电压来确定电池电量
                      调用库
    @version          1.0
    @date             2020/8/19
    @Author           chemoontheshy
    @note             1.校准，基于MCU的标准电压（每个电压都不一样）
*******************/

#include"Voltage.h"
#include"Arduino.h"


Voltage::Voltage() {

}
Voltage::~Voltage() {

}
void Voltage::init(byte anA, byte anB, float reVol) {
  adcA = anA;
  adcB = anB;
  
  if (reVol > 0) {
    reVoltage = reVol;
  }
}
void Voltage::setPower(float minVol, float maxVol, float lowCoe, float highCoe) {
  if (lowCoe > 0) {
    lowCoefficient = lowCoe;
  }
  if (highCoe > 0) {
    highCoefficient = highCoe;
  }
  minVoltage = minVol;
  maxVoltage = maxVol;

}

float Voltage::Filter() {
  int afilter_buf[FILTER_N];
  int bfilter_buf[FILTER_N];
  int i, j;
  int afilter_temp;
  int bfilter_temp;
  for (i = 0; i < FILTER_N; i++) {
    afilter_buf[i] = analogRead(adcA);
    bfilter_buf[i] = analogRead(adcB);
    delay(1);
  }
  // 采样值从小到大排列（冒泡法）
  for (j = 0; j < FILTER_N - 1; j++) {
    for (i = 0; i < FILTER_N - 1 - j; i++) {
      if (afilter_buf[i] > afilter_buf[i + 1]) {
        afilter_temp = afilter_buf[i];
        afilter_buf[i] = afilter_buf[i + 1];
        afilter_buf[i + 1] = afilter_temp;
      }
      if (bfilter_buf[i] > bfilter_buf[i + 1]) {
        bfilter_temp = bfilter_buf[i];
        bfilter_buf[i] = bfilter_buf[i + 1];
        bfilter_buf[i + 1] = bfilter_temp;
      }
    }
  }
  int av = afilter_buf[(FILTER_N - 1) / 2];
  int bv = bfilter_buf[(FILTER_N - 1) / 2];
  //4.84为基准电压
  float aVoltage = ADCtoVoltage(av);
  Serial.print(aVoltage);
  float bVoltage = ADCtoVoltage(bv);
  Serial.print(bVoltage);
  nowVoltage = (bVoltage - aVoltage) * 10;
  return nowVoltage;
}
float Voltage::ADCtoVoltage(int adcVol) {
  float vol =  adcVol * (reVoltage / 1023.00);
  return vol;
}
float Voltage::currentPower() {
  if (minVoltage < 0 && maxVoltage < 0) {
    Serial.print("There is no set min or max Voltage,range:0~1");
    return;
  }
  nowPower = (nowVoltage - minVoltage) / (maxVoltage - minVoltage);
  return nowPower;
}

int Voltage::alarm() {
  if (nowPower < lowCoefficient) {
    return 0;
  }else if (nowPower > highCoefficient) {
    return 2;
  }else{
    return 1;
  }
  
}
