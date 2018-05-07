#include "Enemy.h"

Enemy::Enemy(byte xPos, byte yPos, byte num)
{
  this->x = xPos;
  this->y = yPos;
  this->value = num;
  this->ship = num;
  this->ship = "{" + this->ship + "}";
}

byte Enemy::getX()
{
  return this->x;
}

void Enemy::setX(byte pos)
{
  this->x = pos;
}

byte Enemy::getY()
{
  return this->y;
}

byte Enemy::getValue()
{
  return this->value;
}

void Enemy::setValue(byte num)
{
  this->value = num;
  this->ship = num;
  this->ship = "{" + this->ship + "}";
  this->dead = false;
}

String Enemy::getShip()
{
  return this->ship;
}

void Enemy::updateEnemy()
{
  this->x = this->x - this->movement;
}

bool Enemy::isDead()
{
  return this->dead;
}

void Enemy::died()
{
  this->dead = true;
}

