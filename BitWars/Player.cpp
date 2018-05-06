#include "Player.h"

byte Player::getY()
{
  return this->y;
}

void Player::setY(byte pos)
{
  this->y = pos;
}

String Player::getShip()
{
  return this->ship;
}

