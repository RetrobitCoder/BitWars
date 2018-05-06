#ifndef lazer_h
#define lazer_h

#include <Arduboy2.h>

class Lazer
{
  public:
    Lazer(){};
    Lazer(byte x, byte y, byte dir);
    //get x1 location
    byte getX1();
    //get x2 location
    byte getX2();
    //get y1 location
    byte getY1();
    //get y2 location
    byte getY2();
    //move lazer
    void moveLazer();
  private:
    byte x1;
    byte y1;
    byte x2;
    byte y2;
    byte len = 5;
    byte movement = 3;
};

#endif
