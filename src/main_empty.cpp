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
#include "Entity.h"
#include "Label.h"
using namespace reng;

int main(int argc, char* argv[]){
   
  reng::GameEngine* engine = reng::GameEngine::getInstance();
  engine->init();

  engine->getResourceHandler()->addFont("HPfont", 30, constants::gResPath + "fonts/arial.ttf");
  Label* playerHP = Label::getInstance(0, 0, 50, 50, "HP: 100", "HPFont");
  playerHP->setColor(255, 0, 0);
  engine->addSprite(playerHP);

  engine->getResourceHandler()->addTexture("paddle", constants::gResPath + "images/paddle.png");
  
  Player* player = Player::getInstance("Test player",10,110,50,50,24);
  player->setTexture("paddle");
  player->setPosition(reng::Vector(0,300));

  Player* secondPlayer = Player::getInstance("Second test player",10,110,50,50,24 ,'w','s','a','d');
  secondPlayer->setTexture("paddle");
  secondPlayer->setPosition(reng::Vector(750,300));

  engine->addSprite(player);
  engine->addSprite(secondPlayer);

  player->enableKey('A', true);
  player->enableKey('D', true);
  secondPlayer->enableKey('a', false);
  secondPlayer->enableKey('d', false);

  reng::Ball* ball = reng::Ball::getInstance(300, 300, 20, 20, 4, 3, player);
  engine->getResourceHandler()->addTexture("white_ball", constants::gResPath + "images/whiteball.jpeg");
    engine->getResourceHandler()->addTexture("red_ball", constants::gResPath + "images/redball.jpeg");
  ball->setTexture("white_ball");
  engine->addSprite(ball);
  reng::Ball* hellBullet = reng::Ball::getInstance(400, 300, 20, 20, -4, 3, secondPlayer);      
  reng::GameEngine::getInstance()->addSprite(hellBullet);     
  hellBullet->setTexture("red_ball"); 
  engine->getPhysicsEngine()->enableBoundaries(true); 
  engine->getPhysicsEngine() -> addCollisionListener([](CollisionTrigger& trigger) {
        Projectile* proj = dynamic_cast<Projectile*>(trigger.getColliderSprite());
        if (proj!= nullptr) {
            Entity* entity = dynamic_cast<Entity*>(trigger.getIntoSprite());
            if (entity != nullptr) {
              if (proj->getSource() != entity) {
                entity->damage(4);
              } else {
                //bonk
              }
                
          }
        }
    });
  engine->run();

  return 0;
}
 