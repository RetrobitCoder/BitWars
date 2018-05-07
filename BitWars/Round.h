#ifndef round_h
#define round_h

#include <Arduboy2.h>

class Round
{
  public:
    Round(){}

    //get round problem
    String getProblem();
    //create round problem
    void createProblem(byte a, byte b, String op);
    //check if user answer is right
    bool checkAnswer(String guess);
    //get the round number
    long getRoundNumber();
    //get correct answer
    String getAnswer();
    //reset round
    void resetRound();
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
