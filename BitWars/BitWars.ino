#include <Arduboy2.h>
#include "Round.h"
#include "Player.h"
#include "Lazer.h"
#include "Enemy.h"

#define EX WIDTH-16
#define EY1 14
#define EY2 HEIGHT/2 - 4
#define EY3 HEIGHT - 21

enum class GameState : unsigned char
{
  Title, Play, Pause, GameOver
};

Arduboy2 ab;
Round rond;
Player player;
Lazer* lazer = NULL;
Enemy enemy1 = Enemy(EX,EY1,1);
Enemy enemy2 = Enemy(EX,EY2,0);
Enemy enemy3 = Enemy(EX,EY3,0);
GameState gameState = GameState::Title;
byte thrust = 2;
String ops[5] = {"&", "|", "^", "<<", ">>"};
String guess;

void setup() 
{
  ab.begin();
  mainMenu();
}

void createEnemies()
{
  byte value1 = rand() % 2;
  byte value2 = rand() % 2;
  byte value3;
  if(value1 == 1 && value2 == 1) value3 = 0;
  else if(value1 == 0 && value2 == 0) value3 = 1;
  else value3 = rand() % 2;
  enemy1.setValue(value1);
  enemy1.setX(EX);
  enemy2.setValue(value2);
  enemy2.setX(EX);
  enemy3.setValue(value3);
  enemy3.setX(EX);
}

void mainMenu()
{
  if(ab.justPressed(A_BUTTON))
  {
    gameState = GameState::Play;
    ab.initRandomSeed();
    rond.resetRound();
    start();
  }
}

//start new round
void start()
{
  guess = "";
  byte a = rand() % 32;
  byte b = rand() % 32;
  int opsPos = rand() % 5;
  rond.createProblem(a, b, ops[opsPos]); 
  createEnemies();
}

void drawProblem()
{
  ab.setCursor(10,0);
  ab.print(rond.getProblem()+guess);
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

void drawEnemies()
{
  ab.setCursor(enemy1.getX(), enemy1.getY());
  if(!enemy1.isDead()) ab.print(enemy1.getShip());
  ab.setCursor(enemy2.getX(), enemy2.getY());
  if(!enemy2.isDead()) ab.print(enemy2.getShip());
  ab.setCursor(enemy3.getX(), enemy3.getY());
  if(!enemy3.isDead()) ab.print(enemy3.getShip());
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
  drawProblem();
  drawPlayer();
  drawEnemies();
  drawGameHUD();
  if(lazer != NULL) drawLazer();
}

//keep track of guess
void answer(byte value)
{
  guess = guess + value;
  if(guess.length() >= 5)
  {
    if(rond.checkAnswer(guess)) start();
    else gameState = GameState::GameOver;
  }
}

void enemyCollisionCheck()
{
  byte x = 12;
  byte y = player.getY();

  if(x >= enemy1.getX() && x <= enemy1.getX() + 12)
  {
    if(y >= enemy1.getY() && y <= enemy1.getY() + 6) gameState = GameState::GameOver;
    else if(y + 3 >= enemy1.getY() && y + 3 <= enemy1.getY() + 6) gameState = GameState::GameOver;
  }
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
    if(lazer->getX2() >= enemy1.getX() && lazer->getX2() <= enemy1.getX() + 4)
    {
      if(lazer->getY2() >= enemy1.getY() && lazer->getY2() <= enemy1.getY() + 6)
      {
        delete lazer;
        lazer = NULL;
        enemy1.died(); 
        answer(enemy1.getValue());
      }
    }
    if(lazer->getX2() >= enemy2.getX() && lazer->getX2() <= enemy2.getX() + 4)
    {
      if(lazer->getY2() >= enemy2.getY() && lazer->getY2() <= enemy2.getY() + 6)
      {
        delete lazer;
        lazer = NULL;
        enemy2.died();
        answer(enemy2.getValue()); 
      }
    }
    if(lazer->getX2() >= enemy3.getX() && lazer->getX2() <= enemy3.getX() + 4)
    {
      if(lazer->getY2() >= enemy3.getY() && lazer->getY2() <= enemy3.getY() + 6)
      {
        delete lazer;
        lazer = NULL;
        enemy3.died();
        answer(enemy3.getValue()); 
      }
    }
  }
  if(enemy1.getX() < 2 || enemy2.getX() < 2 || enemy3.getX() < 2)
  {
    createEnemies();
  }
  enemyCollisionCheck();
}

void updateEnemies()
{
  if(!enemy1.isDead()) enemy1.updateEnemy();
  if(!enemy2.isDead()) enemy2.updateEnemy();
  if(!enemy3.isDead()) enemy3.updateEnemy();
  if(enemy1.isDead() && enemy2.isDead() && enemy3.isDead()) createEnemies();
}

void gameLoop()
{
  draw();
  if(ab.pressed(UP_BUTTON)) player.setY(player.getY() - thrust);
  else if(ab.pressed(DOWN_BUTTON)) player.setY(player.getY() + thrust);
  else if(ab.justPressed(LEFT_BUTTON)) gameState = GameState::Pause;
  else if(ab.justPressed(A_BUTTON)) if(lazer == NULL) lazer = new Lazer(0,player.getY() + 3,1);
  if(lazer != NULL) lazer->moveLazer();
  collisionCheck();
  if(ab.everyXFrames(5)) updateEnemies();
}

void pauseScreen()
{
  draw();
  ab.drawRect(WIDTH/2 - 20, HEIGHT/2 - 5, 40, 12);
  ab.setCursor(WIDTH/2 - 18, HEIGHT/2 - 3);
  ab.print("Paused");
  if(ab.justPressed(LEFT_BUTTON)) gameState = GameState::Play;
}

void gameOver()
{
  ab.setCursor(0,0);
  ab.print("Game Over");
  ab.setCursor(WIDTH/2, HEIGHT/2);
  ab.print(rond.getAnswer());
  if(ab.justPressed(A_BUTTON)) gameState = GameState::Title;
}

void loop() 
{
  if(!(ab.nextFrame())) return;
  ab.clear();
  ab.pollButtons();
  switch(gameState)
  {
    case GameState::Title:
      mainMenu();
      break;
    case GameState::Play:
      gameLoop();
      break;
    case GameState::Pause:
      pauseScreen();
      break;
    case GameState::GameOver:
      gameOver();
      break;
  }
  ab.display();
}
