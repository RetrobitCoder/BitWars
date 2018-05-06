#include "Enemy.h"

Enemy::Enemy(byte xPos, byte yPos, byte num)
{
  this->x = xPos;
  this->y = yPos;
  this->value = num;
  String v = value + "";
  this->ship = "{" + v + "}";
}

byte Enemy::getX()
{
  return this->x;
}

byte Enemy::getY()
{
  return this->y;
}

byte Enemy::getValue()
{
  return this->value;
}

String Enemy::getShip()
{
  return this->ship;
}

Lazer* Enemy::getLazer()
{
  return this->lazer;
}

void Enemy::updateEnemy()
{
  this->x = this-x - movement;
}

void Enemy::updateLazer()
{
  if(this->lazer != NULL) this->lazer->moveLazer();
}

void Enemy::fireLazer(byte y1)
{
  if(y1 == this->y + 3) lazer = new Lazer(this->x, this->y + 3, -1);
}

void Enemy::deleteLazer()
{
  delete this->lazer;
  this->lazer = NULL; 
}

