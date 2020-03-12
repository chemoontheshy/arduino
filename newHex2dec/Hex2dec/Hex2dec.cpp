/*******************
  ==Arduino==
  @name         Hex2dec
  @namespace    qchenmo.com
  @version      1.0
  @description  cpp
  @author       chemoontheshy
  @date         2020/3/9

*******************/
#include"Hex2dec.h"
#include"Arduino.h"

Hex2dec::Hex2dec()
{

}
String Hex2dec::getsDec(String hex, char type) {
  String sdec;
  String gethex = hex;
  char gettype = type;
  char cdec[gethex.length() + 1];
  char arr[gethex.length() + 1];
  gethex.toCharArray(arr, gethex.length() + 1);
  int num = 0;
  int cnum = 0;
  char c[2];
  for (int i = 0; i < gethex.length() + 1; i++) {
    if (arr[i] != type) {
      c[num] = arr[i];
      num = num + 1;
      if (num == 2) {
        long lchar;
        lchar = strtol(c, NULL, 16);
        if (lchar < 10) {
          sdec = sdec + "00" + lchar;
        } else if (lchar < 100) {
          sdec = sdec + "0" + lchar;
        } else {
          sdec = sdec + lchar;
        }

        num = 0;
        sprintf(c, "") ;
      }
    } else {
      sdec = sdec + gettype;

    }
  }
  //sdec.toCharArray(cdec, gethex.length() + 1);
  return sdec;
}

Hex2dec::~Hex2dec()
{

}
