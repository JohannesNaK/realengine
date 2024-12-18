#include <iostream>
#include <SDL2/SDL.h>
#include "GameEngine.h"
#include "RectSprite.h"
<<<<<<< Updated upstream

void pause(){
=======
#include <exception>
#include <cstdlib>
#include "Event.h"
#include "SpriteMove.h"
 void pause(){
>>>>>>> Stashed changes
     std::cout << "Press Enter to exit...";
    
    std::cin.get();
}
 
 bool te(reng::SpriteMove& sp){
    std::cout << sp.getSprite().getRect()->w << "lol suck nuts" << std::endl;
 }
int main(int argc, char* argv[]){
   
   
 
          GameEngine eng;
    eng.init();
      reng::RectSprite rect(20,20,20,20,{255,0,0,0});
     eng.addSprite(&rect);
     if (eng.getPhysicsEngine() == nullptr)
        std::cout << "is null";
    if (&rect == nullptr)
        std::cout << "rect is null";
    reng::Event<reng::SpriteMove> ev("w",{},{});
        
    eng.getPhysicsEngine()->setMoveEvent(&ev);
    ev.addListener(&te);
    if (eng.getPhysicsEngine() == nullptr)
       std::cout << "game eng2 is bad";
    std::cout << "calling mov req" << std::endl;
    eng.getPhysicsEngine()->moveRequest(rect,reng::Vector(2,2));
    std::cout << "attempting to call listeners" << std::endl;
      ev.notifyListeners();
   
   eng.run();
   
      pause();
      system("pause");
    return 0;
}
 