#include <iostream>
#include <SDL2/SDL.h>
#include "GameEngine.h"
#include "RectSprite.h"
#include "Event.h"
#include "SpriteMoveTrigger.h"
void pause(){
     std::cout << "Press Enter to exit...";
    
    std::cin.get();
}
const char keyName(SDL_KeyboardEvent* key){
    return *SDL_GetKeyName(key->keysym.sym);
}
 
int main(int argc, char* argv[]){
   
 
    GameEngine eng;
    eng.init();
    reng::RectSprite rect(20,20,20,20,{255,0,0,0});
    eng.addSprite(&rect);
    //höhöhö black magiccc
    eng.getPhysicsEngine()->move(rect, reng::Vector(10,3));
    eng.run();
    pause();
    return 0;
}
 