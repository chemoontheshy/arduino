int Filter_Value;
int stepNum = 90;
#include <Step.h>
Step myStep;
void setup() {
  Serial.begin(115200);       // 初始化串口通信
  randomSeed(analogRead(0)); // 产生随机种子
  myStep.init(4, 5, 6, 7, 20000);
}

void loop() {
  Filter_Value = Filter();       // 获得滤波器输出值
  Serial.println(Filter_Value); // 串口输出
  int val = map(Filter_Value, 0, 1023, 0, 180); //从0-1023映射到0-255
  Serial.println("val:"); // 串口输出
  Serial.println(val); // 串口输出
  while (stepNum > val) {
    stepNum--;
   myStep.set(2);
 
  }
   Serial.print("stepNum"); // 串口输出
   Serial.println(stepNum); // 串口输出
  while (stepNum < val) {
    stepNum++;
     myStep.set(1);

  }
  delay(200);
}

// 用于随机产生一个300左右的当前值
int Get_AD() {
  return analogRead(A2);
}

// 中位值滤波法
#define FILTER_N 101
int Filter() {
  int filter_buf[FILTER_N];
  int i, j;
  int filter_temp;
  for (i = 0; i < FILTER_N; i++) {
    filter_buf[i] = Get_AD();
    delay(1);
  }
  // 采样值从小到大排列（冒泡法）
  for (j = 0; j < FILTER_N - 1; j++) {
    for (i = 0; i < FILTER_N - 1 - j; i++) {
      if (filter_buf[i] > filter_buf[i + 1]) {
        filter_temp = filter_buf[i];
        filter_buf[i] = filter_buf[i + 1];
        filter_buf[i + 1] = filter_temp;
      }
    }
  }
  return filter_buf[(FILTER_N - 1) / 2];
}
