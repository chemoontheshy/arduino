/*******************
  ==Arduino==
  @name         Hex2dec
  @namespace    qchenmo.com
  @version      1.0
  @description  c
  @author       chemoontheshy
  @date         2020/3/9

*******************/

#ifndef _Hex2dec_H_
#define _Hex2dec_H_

//Arduino core header files
#include "Arduino.h"

class Hex2dec
{
  private:
    char cdec;
  public:
    Hex2dec();
    ~Hex2dec();
    String getsDec(String hex, char type);
    
};
#endif
