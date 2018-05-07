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
    //set x location
    void setX(byte pos);
    //get y location
    byte getY();
    //get value
    byte getValue();
    //set value
    void setValue(byte num);
    //get ship
    String getShip();
    //update enemy
    void updateEnemy();
    //check if dead
    bool isDead();
    //dead
    void died();
  private:
    byte x;
    byte y;
    byte movement = 2;
    byte value;
    bool dead = false;
    String ship;
};

#endif
