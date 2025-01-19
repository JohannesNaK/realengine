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
#include <random>
using namespace reng;


reng::GameEngine* engine = reng::GameEngine::getInstance();


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

void loadResources(){
  engine->getResourceHandler()->addTexture("white_paddle", constants::gResPath + "images/white_paddle.png");
  engine->getResourceHandler()->addTexture("red_paddle", constants::gResPath + "images/red_paddle.png");
  engine->getResourceHandler()->addTexture("white_ball", constants::gResPath + "images/whiteball.png");
  engine->getResourceHandler()->addTexture("red_ball", constants::gResPath + "images/redball.png");
  engine->getResourceHandler()->addTexture("health_pickup", constants::gResPath + "images/health_pickup.png");
    engine->getResourceHandler()->addTexture("wall",constants::gResPath + "images/wall.png");
  engine->getResourceHandler()->addFont("HPfont", 20, constants::gResPath + "fonts/arial.ttf");
 
}
void populateWalls(){
   std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist2(0,1); // distribution in range [1, 6]
    int center = engine->getWindowWidth()/2;
         for (int y = 0; y <= 6; y+=2) {
        Sprite* mazeWall = Entity::getInstance("wall",center, 50*y,50,50,12);
        mazeWall->setTexture("wall");
        engine->addSprite(mazeWall);
         }

 }
void setPlayerEnv(){
  Label* playerHP = Label::getInstance(20, 0, 100, 100, "HP: 100", "HPfont");
  Label* secondPlayerHP = Label::getInstance(680, 0, 100, 100, "HP: 100", "HPfont");
  engine->addSprite(playerHP);
  engine->addSprite(secondPlayerHP);
  secondPlayerHP->setColor(255U, 0U, 0U);
  engine->getPhysicsEngine()->enableBoundaries(true); 
  Player* player = Player::getInstance("P1",100,300,35,55,100,playerHP);
  
  player->setTexture("white_paddle");
  Player* secondPlayer = Player::getInstance("P2",1100,300,35,55,100 ,'w','s','a','d', secondPlayerHP);
 
  secondPlayer->setTexture("red_paddle");
 
  player->enableKey('A', true);
  player->enableKey('D', true);
  secondPlayer->enableKey('a', true);
  secondPlayer->enableKey('d', true);
  engine->addSprite(player);
  engine->addSprite(secondPlayer);
  reng::Ball* ball = reng::Ball::getInstance(100, 300, 20, 20, 6, 3, player);
  ball->setTexture("white_ball");
  engine->addSprite(ball);
  reng::Ball* secondBall = reng::Ball::getInstance(1100, 300, 20, 20, -6, 3, secondPlayer);      
  engine->addSprite(secondBall);     
  secondBall->setTexture("red_ball"); 
   populateWalls();
}
  
int main(int argc, char* argv[]){
   
 
  engine->init(1200,600);
  loadResources();
  setPlayerEnv();
  HPPickup* hp = new HPPickup(300,200,6);
  
  HPPickup* secondHp = new HPPickup(900,200,6);
  hp->setTexture("health_pickup");
  engine->addSprite(hp);
   secondHp->setTexture("health_pickup");
  engine->addSprite(secondHp);
  int ballCount = 2;
  engine->getPhysicsEngine() -> addCollisionListener([&ballCount](CollisionTrigger& trigger) {
        Projectile* proj = dynamic_cast<Projectile*>(trigger.getColliderSprite());
         if (proj!= nullptr) {
                  Player*  entity = dynamic_cast<Player*>(trigger.getIntoSprite());

             if (entity != nullptr) {
              if (proj->getSource() != entity && proj->getSource() != nullptr) {
                 entity->damage(4);
                 std::string hpText = "HP: " + std::to_string(entity->getHP());
                 entity->setTextLabel(hpText);
                 if (entity->getHP() <= 0) {
                  Label* gameOver = Label::getInstance(250, 200, 400, 100, "GAME OVER! " + entity->getName() + " WON!", "HPfont");
                  Label* countDown = Label::getInstance(250,350,400,100, "Restart in: " + std::to_string(6), "HPfont");
                 
                 engine->addSprite(gameOver);
                 engine->addSprite(countDown);
            
                 engine->render();
                  for (int i = 5; i > 0; --i ){
                      SDL_Delay(1000);
                      countDown->setText("Restart in: "  + std::to_string(i));
                      engine->render();

                  }
                  //Cleanup session
                  engine->clearAllSprites();
                  //Restart game env.
                  setPlayerEnv();
                  ballCount = 2;
                 }
                 else if (ballCount < 3){
                    if (entity->getName() == "P2") {
                      
                      reng::Ball* p1Ball = reng::Ball::getInstance(100, 300, 20, 20, 4, 3, proj->getSource());      
                      engine->addSprite(p1Ball);     
                      p1Ball->setTexture("white_ball"); 
                      ballCount++;
                    } else if (entity->getName() == "P1") {
                       reng::Ball* p2Ball = reng::Ball::getInstance(1100, 300, 20, 20, -4, 3, proj->getSource());      
                      engine->addSprite(p2Ball);     
                      p2Ball->setTexture("red_ball"); 
                              ballCount++;
                    }
                 }
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
 