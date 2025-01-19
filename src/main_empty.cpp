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
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
using namespace reng;

class HPPickup : public Sprite {
    public:
      HPPickup(int x, int y, int heal) : Sprite(x,y,30,40), heal(heal) {}
      void consumePickup(reng::Player* player) {
       
        player->setHP(player->getHP() + heal);
        std::string hpText = "HP: " + std::to_string(player->getHP());
        player->setTextLabel(hpText);
        setToRemove();
      }
    private:
      int heal;
      bool remove = false;
};
int main(int argc, char* argv[]){
   
  reng::GameEngine* engine = reng::GameEngine::getInstance();
  engine->init();

  engine->getResourceHandler()->addTexture("white_paddle", constants::gResPath + "images/white_paddle.png");
  engine->getResourceHandler()->addTexture("red_paddle", constants::gResPath + "images/red_paddle.png");
     engine->getResourceHandler()->addFont("HPfont", 20, constants::gResPath + "fonts/arial.ttf");

  Label* playerHP = Label::getInstance(20, 0, 100, 100, "HP: 20", "HPfont");
  Label* secondPlayerHP = Label::getInstance(680, 0, 100, 100, "HP: 20", "HPfont");
  secondPlayerHP->setColor(255U, 0U, 0U);

  engine->addSprite(playerHP);
  engine->addSprite(secondPlayerHP);
  Player* player = Player::getInstance("Test player",10,110,35,55,24,playerHP);
  player->setTexture("white_paddle");
  player->setPosition(reng::Vector(0,300));

  Player* secondPlayer = Player::getInstance("Second test player",10,110,35,55,24 ,'w','s','a','d', secondPlayerHP);
  secondPlayer->setTexture("red_paddle");
  secondPlayer->setPosition(reng::Vector(750,300));

  engine->addSprite(player);
  engine->addSprite(secondPlayer);

 
 

  player->enableKey('A', true);
  player->enableKey('D', true);
  secondPlayer->enableKey('a', true);
  secondPlayer->enableKey('d', true);

  reng::Ball* ball = reng::Ball::getInstance(300, 300, 20, 20, 4, 3, player);
  engine->getResourceHandler()->addTexture("white_ball", constants::gResPath + "images/whiteball.png");
  engine->getResourceHandler()->addTexture("red_ball", constants::gResPath + "images/redball.png");
  ball->setTexture("white_ball");
  engine->addSprite(ball);
  reng::Ball* hellBullet = reng::Ball::getInstance(400, 300, 20, 20, -4, 3, secondPlayer);      
  reng::GameEngine::getInstance()->addSprite(hellBullet);     
  hellBullet->setTexture("red_ball"); 
  engine->getPhysicsEngine()->enableBoundaries(true); 
  HPPickup* hp = new HPPickup(300,200,6);
  engine->getResourceHandler()->addTexture("health_pickup.png", constants::gResPath + "images/health_pickup.png");
  hp->setTexture("health_pickup.png");
  engine->addSprite(hp);
 
  engine->addSprite(playerHP);
  engine->addSprite(secondPlayerHP);
  //HP-pickup
  engine->getPhysicsEngine() -> addCollisionListener([](CollisionTrigger& trigger) {
        Projectile* proj = dynamic_cast<Projectile*>(trigger.getColliderSprite());
        if (proj!= nullptr) {
            Player*  entity = dynamic_cast<Player*>(trigger.getIntoSprite());
            if (entity != nullptr) {
              if (proj->getSource() != entity && proj->getSource() != nullptr) {
                 entity->damage(4);
                 std::string hpText = "HP: " + std::to_string(entity->getHP());
                 entity->setTextLabel(hpText);
                 if (entity->getHP() <= 0) {
                  std::cout << "game over? " << std::endl;
                  Label* gameOver = Label::getInstance(250, 200, 400, 100, "GAME OVER! " + entity->getName() + " WON!", "HPfont");
                  Label* countDown = Label::getInstance(250,350,400,100, "Restart in: " + std::to_string(6), "HPfont");
                  reng::GameEngine::getInstance()->addSprite(gameOver);
                  reng::GameEngine::getInstance()->addSprite(countDown);
                   gameOver->setColor(255U, 0U, 0U);
                   reng::GameEngine::getInstance()->render();
                  for (int i = 5; i > 0; --i ){
                    
                      SDL_Delay(1000);
                      countDown->setText("Restart in: "  + std::to_string(i));
                      reng::GameEngine::getInstance()->render();

                  }
                  gameOver->setToRemove();
                  countDown->setToRemove();
                 }
                  
                
      
              } else {
                //bonk
              }
                
          }
        }
    });
    
    engine->getPhysicsEngine()->addCollisionListener([](CollisionTrigger& trigger){
      Player* entity = dynamic_cast<Player*>(trigger.getColliderSprite());
      if (entity != nullptr) {
        HPPickup* hp = dynamic_cast<HPPickup*>(trigger.getIntoSprite());
        if (hp != nullptr) {
          hp->consumePickup(entity);
     
        }
      }
  });
 
  engine->run();

  return 0;
}
 