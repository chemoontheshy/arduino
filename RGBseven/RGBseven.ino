/*
    @name             RGB
    @description      RGB demo
    @version          1.2
    @date             2020/3/9
    @Author           chemoontheshy
*/
int r = 9;
int g = 10;
int b = 11;
#include"Hex2dec.h"
Hex2dec hex2dec;
//颜色
String Red = "#FF0000"; //红色 #FF0000
String Orange = "#FF7F00"; //橙色 #FF7F00
String Yellow = "#FFFF00"; //黄色 #FFFF00
String Green = "#00FF00"; //绿色#00FF00
String Cyan = "#00FFFF"; //青色 #00FFFF
String Blue = "#0000FF"; //蓝色 #0000FF
String Purple = "#8B00FF"; //紫色 #8B00FF
String color[7] = {Red, Orange, Yellow, Green, Cyan, Blue, Purple};

void setup() {
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
  Serial.begin(115200);//serial baud rate
  Serial.println(sizeof(color));
  // put your setup code here, to run once:
  for (int i = 0; i < 7; i++) {
    Serial.println(color[i]);
    String decstr = change(color[i]);
    outcolor(decstr);
  }


}

void loop() {
  // put your main code here, to run repeatedly:

}
String change(String color) {
  String dec = hex2dec.getsDec(color, '#');
  Serial.println(dec);
  return dec;
}
void outcolor(String decstr) {
  if (decstr.indexOf("#") > -1) {
    decstr = decstr.substring(1);
    int ib = 255 - decstr.substring(6).toInt();
    int ig = 255 - decstr.substring(3, 6).toInt();
    int ir = 255 - decstr.substring(0, 3).toInt();
    digitalWrite(r, ir);   // 点亮r
    digitalWrite(g, ig);   // 点亮g
    digitalWrite(b, ib);   // 点亮b
    Serial.print(ir);
    Serial.print(ig);
    Serial.println(ib);
  }
  delay(2000);

}
