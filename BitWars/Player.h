#ifndef player_h
#define player_h

#include <Arduboy2.h>

class Player
{
  public:
    Player()
    {
      x = 0;
      y = HEIGHT/2;
    }
  
    //get y location
    byte getY();
    //set y location
    void setY(byte pos);
    //get ascii ship
    String getShip();
  private:
    byte x;
    byte y;
    String ship = ">=";
};

#endif
