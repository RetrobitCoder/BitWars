#include "Lazer.h"

Lazer::Lazer(byte x, byte y)
{
  this->x1 = x;
  this->y1 = y;
  this->x2 = x + this->len;
  this->y2 = y;
}

byte Lazer::getX1()
{
  return this->x1;
}

byte Lazer::getY1()
{
  return this->y1;
}

byte Lazer::getX2()
{
  return this->x2;
}

byte Lazer::getY2()
{
  return this->y2;
}

void Lazer::moveLazer()
{
  this->x1 = x1 + movement;
  this->x2 = x2 + movement;
}

