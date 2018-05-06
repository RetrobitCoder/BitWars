#ifndef enemy_h
#define enemy_h

#include <Arduboy2.h>
#include "Lazer.h"

class Enemy
{
  public:
    Enemy(){};
    Enemy(byte xPos, byte yPos, byte num);
    //get x location
    byte getX();
    //get y location
    byte getY();
    //get value
    byte getValue();
    //get ship
    String getShip();
    //get lazer
    Lazer* getLazer();
    //update enemy
    void updateEnemy();
    //update lazer
    void updateLazer();
    //fire lazer
    void fireLazer(byte y1);
    //remove lazer
    void deleteLazer();
  private:
    byte x;
    byte y;
    byte movement = 2;
    byte value;
    String ship;
    Lazer* lazer = NULL;  
};

#endif
