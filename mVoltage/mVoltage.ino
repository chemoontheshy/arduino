/*******************
  ==Arduino==
    @name             MVoltage
    @description      利用ADC差分来测量电压24V电压，
                      中位值滤波法去掉噪音
                      根据电压来确定电池电量
    @version          1.0
    @date             2020/8/19
    @Author           chemoontheshy
    @note             1.校准，基于MCU的标准电压（每个电压都不一样）
*******************/
int nowValue = 0;
//放完电截止电压（极限）
float minVoltage = 18.0;
//充满电电压
float maxVoltage = 25.2;
//提醒充电（低于20%）（25.2-18.0）*20%+18.0=19.44
float lowVoltage = 19.44;
//满电提示（高于80%）（25.2-18.0）*80%+18.0=23.76
float highVoltage = 23.76;
void setup()
{
  // 初始化串口
  Serial.begin(115200);
}
void loop()
{
  // 读出当前光线强度，并输出到串口显示
  Filter();

}

// 算术平均滤波法
// 中位值滤波法
#define FILTER_N 201
void Filter() {
  int afilter_buf[FILTER_N];
  int bfilter_buf[FILTER_N];
  int i, j;
  int afilter_temp;
  int bfilter_temp;
  for (i = 0; i < FILTER_N; i++) {
    afilter_buf[i] = analogRead(A0);
    bfilter_buf[i] = analogRead(A2);
    delay(10);
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
  float aVoltage = av * (4.84 / 1023.00);
  float bVoltage = bv * (4.84 / 1023.00);
  float cVoltage = (bVoltage - aVoltage)*10;
  Serial.print("aVoltage: ");
  Serial.println(aVoltage);
  Serial.print("bVoltage: ");
  Serial.println(bVoltage);
  Serial.print("cVoltage: ");
  Serial.println(cVoltage,1);
}


