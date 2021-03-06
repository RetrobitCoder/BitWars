#include "Round.h"

/*** Public ***/

String Round::getProblem()
{
  return this->problem;
}

void Round::createProblem(byte a, byte b, String op)
{
  if(op == "&")
  {
    this->answer = a & b;
  }
  else if(op == "|")
  {
    this->answer = a | b;
  }
  else if(op == "^")
  {
    this->answer = a ^ b;
  }
  else if(op == ">>")
  {
    this->answer = a >> b;
  }
  else
  {
    this->answer = a << b;
  }

  this->problem = convert(a) + op + convert(b) + "=";
  this->roundNum++;
}

bool Round::checkAnswer(String guess)
{
  return (guess == convert(this->answer));
}

long Round::getRoundNumber()
{
  return this->roundNum;
}

String Round::getAnswer()
{
  return convert(this->answer);
}

void Round::resetRound()
{
  this->roundNum = 0;
}
/*** Private ***/

String Round::convert(byte num)
{
  String numString = "";
  for(int i = 4; i >= 0; i--) numString = numString + ((num >> i) & 1);
  return numString;
}

