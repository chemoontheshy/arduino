/*******************
  ==Arduino==
    @name             MVoltage.cpp
    @description      利用ADC差分来测量电压24V电压，
                      中位值滤波法去掉噪音
                      根据电压来确定电池电量
    @version          1.0
    @date             2020/8/19
    @Author           chemoontheshy
    @note             1.校准，基于MCU的基准电压（参考电压）（每个电压都不一样）
*******************/

#ifndef _Voltage_H_
#define _Voltage_H_

//导入Arduino核心头文件
#include"Arduino.h"


class Voltage
{
  private:
    byte adcA;//ADCIN-
    byte adcB;//ADCIN+
    float reVoltage=5.0;//The reference voltage
    //Discharge cut-off voltage(limit)
    float minVoltage;
    //Full electric voltage
    float maxVoltage;
    //Reminder charging(less than 20%)
    float lowCoefficient =0.2;
    //Full power prompt (above 80%)
    float highCoefficient=0.8;
    //current voltage
    float nowVoltage;
    //dump energy
    float nowPower;
    #define FILTER_N 101

  public:
    Voltage();
    ~Voltage();
    //
    void init(byte anA, byte anB, float reVol);
    void setPower(float minVol,float maxVol,float lowCoe,float highCoe);
    float Filter();
    float currentPower();
    int alarm();
    float ADCtoVoltage(int adcVl);
    

};

#endif
