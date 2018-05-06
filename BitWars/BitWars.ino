#include <Arduboy2.h>
#include "Round.h"
#include "Player.h"
#include "Lazer.h"

enum class GameState : unsigned char
{
  Title, Play, Pause, GameOver
};

Arduboy2 ab;
Round rond;
Player player;
Lazer* lazer = NULL;
GameState gameState = GameState::Play;
byte thrust = 2;
String ops[5] = {"&", "|", "^", "<<", ">>"};

void setup() 
{
  ab.begin();
  ab.initRandomSeed(); //will want to move to function that starts 1st level
  start();
}

//start new round
void start()
{
  byte a = rand() % 32;
  byte b = rand() % 32;
  int opsPos = rand() % 5;
  rond.createProblem(a, b, ops[opsPos]); 
}

void drawProblem()
{
  ab.setCursor(10,0);
  ab.print(rond.getProblem());
  ab.setCursor(10, HEIGHT-8);
  ab.print(rond.getRoundNumber());
}

void drawLazer()
{
  ab.drawLine(lazer->getX1(), lazer->getY1(), lazer->getX2(), lazer->getY2());
}

void drawPlayer()
{
  ab.setCursor(0, player.getY());
  ab.print(player.getShip());
}

void drawGameHUD()
{
  ab.drawLine(0,8,WIDTH,8); 
  ab.drawLine(0,HEIGHT-10, WIDTH, HEIGHT-10);
  ab.setCursor(WIDTH/2+16, HEIGHT-8);
  if(lazer == NULL) ab.print("READY");
  else ab.print("CHARGING");
}

void draw()
{
  drawGameHUD();
  drawProblem();
  drawPlayer();
  if(lazer != NULL) drawLazer();
}

//check for wall and enemy collisions
void collisionCheck()
{
  byte pos = player.getY();
  if(pos < 8) player.setY(9);
  else if(pos+8 > HEIGHT-10) player.setY(HEIGHT-17);
  if(lazer != NULL)
  {
    if(lazer->getX2() == WIDTH)
    {
      delete lazer;
      lazer = NULL; 
    }
  }
}

void gameLoop()
{
  draw();
  if(ab.pressed(UP_BUTTON)) player.setY(player.getY() - thrust);
  else if(ab.pressed(DOWN_BUTTON)) player.setY(player.getY() + thrust);
  else if(ab.justPressed(LEFT_BUTTON)) gameState = GameState::Pause;
  else if(ab.justPressed(A_BUTTON)) if(lazer == NULL) lazer = new Lazer(0,player.getY() + 3);
  if(lazer != NULL) lazer->moveLazer();
  collisionCheck();
}

void pauseScreen()
{
  draw();
  ab.drawRect(WIDTH/2 - 20, HEIGHT/2 - 5, 40, 12);
  ab.setCursor(WIDTH/2 - 18, HEIGHT/2 - 3);
  ab.print("Paused");
  if(ab.justPressed(LEFT_BUTTON)) gameState = GameState::Play;
}

void loop() 
{
  if(!(ab.nextFrame())) return;
  ab.clear();
  ab.pollButtons();
  switch(gameState)
  {
    case GameState::Title:
      break;
    case GameState::Play:
      gameLoop();
      break;
    case GameState::Pause:
      pauseScreen();
      break;
    case GameState::GameOver:
      break;
  }
  ab.display();
}
