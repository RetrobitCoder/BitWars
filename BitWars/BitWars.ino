#include <Arduboy2.h>
#include "Round.h"

Arduboy2 ab;
Round rond;

void setup() 
{
  ab.begin();
  ab.initRandomSeed();
  start();
}

//TODO: randomly pick 2 bytes of length 5
//TODO: only need to do at start of each round
void start()
{
  rond.create_problem(8, 9, "^"); 
}

void drawProblem()
{
  ab.setCursor(10,0);
  ab.print(rond.get_problem());
  ab.setCursor(10, HEIGHT-8);
  ab.print(rond.get_round_number());
}

void draw()
{
  drawProblem();
  ab.drawLine(0,8,WIDTH,8);
  ab.drawLine(0,HEIGHT-10, WIDTH, HEIGHT-10);
}

void loop() 
{
  if(!(ab.nextFrame())) return;
  ab.clear();
  draw();
  ab.display();
}
