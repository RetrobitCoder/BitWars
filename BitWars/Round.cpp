#include "Round.h"

/*** Public ***/

String Round::get_problem()
{
  return this->problem;
}

void Round::create_problem(byte a, byte b, String op)
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

bool Round::check_answer(byte guess)
{
  return (guess == this->answer);
}

long Round::get_round_number()
{
  return this->roundNum;
}

/*** Private ***/

String Round::convert(byte num)
{
  String numString = "";
  for(int i = 4; i >= 0; i--) numString = numString + ((num >> i) & 1);
  return numString;
}

