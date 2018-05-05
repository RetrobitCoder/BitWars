#ifndef round_h
#define round_h

#include <Arduboy2.h>

class Round
{
  public:
    Round(){}

    //get round problem
    String get_problem();
    //create round problem
    void create_problem(byte a, byte b, String op);
    //check if user answer is right
    bool check_answer(byte guess);
    //get the round number
    long get_round_number();
    
  private:
    String problem;
    long roundNum = 0;
    byte byte1;
    byte byte2;
    byte answer;

    //convert 5bit num to binary representation as a String
    String convert(byte num);
};

#endif
