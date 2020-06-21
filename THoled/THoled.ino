
/**
   HDC1080例程
   @author 沉默
   @date 2019/09/21
*/
#include "U8glib.h"
#include "hz.c"
String t = "Temp:";
String st = "";
String h = "Humi:";
String sh = "";
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);
#include <ClosedCube_HDC1080.h>
ClosedCube_HDC1080 hdc1080;

void draw() {
   u8g.setFont(u8g_font_ncenB14);//还是先设置一个字体 
  u8g.setPrintPos(0,30);//然后设置一个位置
  u8g.print(t);//然后就是数据
  u8g.print(st);
  u8g.setFont(u8g_font_ncenB14);//还是先设置一个字体 
  u8g.setPrintPos(0,54);//然后设置一个位置
  u8g.print(h);//然后就是数据
  u8g.print(sh);
}

void setup()
{
  Serial.begin(115200);
  hdc1080.begin(0x40);
}

void loop()
{
  st=hdc1080.readTemperature();
  st=st+"C";
  sh=hdc1080.readHumidity();
  sh=sh+"%";
  u8g.firstPage();  
  do {
    draw();
  } 
  while( u8g.nextPage() ); //延迟一段时间后重新生成图片
  delay(2000);


}
