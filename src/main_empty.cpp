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
void pause(){
     std::cout << "Press Enter to exit...";
    
    std::cin.get();
}
 
 
int main(int argc, char* argv[]){
   
   reng::GameEngine* engine = reng::GameEngine::getInstance();
    engine->init();
    SDL_Texture* gubbTx = IMG_LoadTexture(engine->getRenderer(), (constants::gResPath + "images/gubbe.bmp").c_str() );
    if (!gubbTx)
    	SDL_Log("Failed to load texture: %s", SDL_GetError());

    //reng::RectSprite rect(20,20,20,20,{255,0,0,0});
    //eng.addSprite(&rect);
    //höhöhö black magiccc
    //eng.getPhysicsEngine()->move(rect, reng::Vector(10,3));

  // reng::Projectile* p = reng::Projectile::getInstance(10, 10, 200, 200, 2, 2);
    reng::Player player("Test player",10,110,50,50,1);
    player.setTexture(gubbTx);
         player.setPosition(reng::Vector(400,300));
  engine->setCameraFollowSprite(&player);
  reng::RectSprite rect(20,20,20,20,{255,0,0,0});
  engine->addSprite(&rect);
    engine->addSprite(&player);
     //p->setTexture(gubbTx);
   // engine->addSprite(p);
    engine->run();
    pause();

    SDL_DestroyTexture(gubbTx);
    return 0;
}
 