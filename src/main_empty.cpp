#include <iostream>
#include <SDL2/SDL.h>
#include "GameEngine.h"
#include "RectSprite.h"
#include "Event.h"
#include "SpriteMoveTrigger.h"
#include "Projectile.h"
#include "Constants.h"
#include "Player.h"
#include <string>
#include "Ball.h"

using namespace reng;

int main(int argc, char* argv[]){
   
  reng::GameEngine* engine = reng::GameEngine::getInstance();
  engine->init();

  engine->getTextureHandler()->addTexture("paddle", constants::gResPath + "images/paddle.png");
    
  Player* player = Player::getInstance("Test player",10,110,50,50,1);
  player->setTexture("paddle");
  player->setPosition(reng::Vector(0,300));

  Player* secondPlayer = Player::getInstance("Second test player",10,110,50,50,1,'w','s','a','d');
  secondPlayer->setTexture("paddle");
  secondPlayer->setPosition(reng::Vector(750,300));

  engine->addSprite(player);
  engine->addSprite(secondPlayer);

  player->enableKey('A', false);
  player->enableKey('D', false);
  secondPlayer->enableKey('a', false);
  secondPlayer->enableKey('d', false);

  reng::Ball* ball = reng::Ball::getInstance(400, 300, 20, 20, 2, 2);
  engine->getTextureHandler()->addTexture("ball", constants::gResPath + "images/whiteball.jpeg");
  ball->setTexture("ball");
  engine->addSprite(ball);
  
  engine->getPhysicsEngine()->enableBoundaries(true); 

  engine->run();

  return 0;
}
 