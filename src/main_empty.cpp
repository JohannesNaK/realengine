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
 
int main(int argc, char* argv[]){
   
  reng::GameEngine* engine = reng::GameEngine::getInstance();
  engine->init();
  SDL_Texture* gubbTx = IMG_LoadTexture(engine->getRenderer(), (constants::gResPath + "images/paddle.png").c_str() );
  if (!gubbTx)
    SDL_Log("Failed to load texture: %s", SDL_GetError());
    
  //reng::RectSprite rect(20,20,20,20,{255,0,0,0});
  //eng.addSprite(&rect);
  //höhöhö black magiccc
  //eng.getPhysicsEngine()->move(rect, reng::Vector(10,3));

  // reng::Projectile* p = reng::Projectile::getInstance(10, 10, 200, 200, 2, 2);
  reng::Player player("Test player",10,110,50,50,1);
  player.setTexture(gubbTx);
  player.setPosition(reng::Vector(0,300));
  //engine->setCameraFollowSprite(&player);
  reng::Player secondPlayer("Second test player",10,110,50,50,1,'w','s','a','d');
  secondPlayer.setTexture(gubbTx);
  secondPlayer.setPosition(reng::Vector(750,300));
  //reng::RectSprite rect(20,20,20,20,{255,0,0,0});
  //engine->addSprite(&rect);
  engine->addSprite(&player);
  engine->addSprite(&secondPlayer);
  //p->setTexture(gubbTx);
  //engine->addSprite(p);

  player.enableKey('A', false);
  player.enableKey('D', false);

  secondPlayer.enableKey('a', false);
  secondPlayer.enableKey('d', false);

  reng::Ball* ball = reng::Ball::getInstance(400, 300, 20, 20);  //X, Y, Width, Height
  SDL_Texture* ballImage = IMG_LoadTexture(engine->getRenderer(), (constants::gResPath + "images/whiteball.jpeg").c_str() );
  ball->setTexture(ballImage);
  
  engine->addSprite(ball);
  
  engine->getPhysicsEngine()->enableBoundaries(true); 

  engine->run();

  SDL_DestroyTexture(gubbTx);
  return 0;
}
 