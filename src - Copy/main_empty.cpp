#include <iostream>
#include <SDL2/SDL.h>
#include "GameEngine.h"
#include "RectSprite.h"
 void pause(){
     std::cout << "Press Enter to exit...";
    
    std::cin.get();
}
const char keyName(SDL_KeyboardEvent* key){
    return *SDL_GetKeyName(key->keysym.sym);
}
int main(int argc, char* argv[]){
   
 /*
     SDL_Init(SDL_INIT_EVENTS);
    SDL_Window* window = SDL_CreateWindow("Game Engine", 200,200,700,800,0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window,-1,0);
    bool run = true;
    float velocity = 2.5;
    SDL_Rect rect = {0,0,50,50};
    SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );
    SDL_RenderFillRect(renderer,&rect);
    SDL_RenderClear(renderer);
      SDL_SetRenderDrawColor( renderer, 0, 0, 0, 0 );
    SDL_RenderPresent(renderer);
  
    while (run){
  
        SDL_Event ev;
        while (SDL_PollEvent(&ev)){
            if (ev.type == SDL_KEYDOWN){
                if (keyName(&ev.key) == 'W'){
                        std::cout << "Pressed " << keyName(&ev.key) << std::endl;
                   rect.x += velocity;
                }
            
            } else if (ev.type == SDL_KEYUP) {
                if (keyName(&ev.key) == 'W'){
                        std::cout << "Released " << keyName(&ev.key)  << std::endl;
                }
            }
        }
      SDL_SetRenderDrawColor(renderer, 0, 0, 20, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &rect);
        SDL_RenderPresent(renderer);
    }
 */
    GameEngine eng;
    eng.init();
    reng::RectSprite rect(20,20,20,20,{255,0,0,0});
    eng.addSprite(&rect);
    eng.run();
    pause();
    return 0;
}
 