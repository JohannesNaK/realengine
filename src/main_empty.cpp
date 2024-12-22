#include <iostream>
#include <SDL2/SDL.h>
#include "GameEngine.h"
#include "RectSprite.h"
#include "Event.h"
#include "SpriteMoveTrigger.h"
#include "Projectile.h"
#include "Constants.h"
void pause(){
     std::cout << "Press Enter to exit...";
    
    std::cin.get();
}
const char keyName(SDL_KeyboardEvent* key){
    return *SDL_GetKeyName(key->keysym.sym);
}
 
int main(int argc, char* argv[]){
   
    GameEngine::init();
    
    SDL_Texture* gubbTx = IMG_LoadTexture(GameEngine::getRenderer(), (constants::gResPath + "images/gubbe.bmp").c_str() );
    if (!gubbTx)
    	SDL_Log("Failed to load texture: %s", SDL_GetError());

    //reng::RectSprite rect(20,20,20,20,{255,0,0,0});
    //eng.addSprite(&rect);
    //höhöhö black magiccc
    //eng.getPhysicsEngine()->move(rect, reng::Vector(10,3));

    reng::Projectile* p = reng::Projectile::getInstance(10, 10, 200, 200, 2, 2);
    p->setTexture(gubbTx);
    GameEngine::addSprite(p);

    GameEngine::run();
    pause();

    SDL_DestroyTexture(gubbTx);
    return 0;
}
 