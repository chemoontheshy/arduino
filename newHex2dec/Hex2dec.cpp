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

Hex2dec::Hex2dec(String hex)
{
  char arr[hex.length()+1];
  hex.toCharArray(arr, hex.length()+1);
  //Serial.println(arr);
  dec = strtol(arr, NULL, 16);
}
long Hex2dec::getDec(){
  return dec;
}

Hex2dec::~Hex2dec()
{
  
}
