#include "Sprite.h"
#include <SDL2/SDL.h>
namespace reng{
    Sprite::Sprite(int x, int y, int w, int h): rect{x, y, w, h}, texture(nullptr) {}
    Sprite::~Sprite(){}

    void Sprite::draw(SDL_Renderer* renderer){
        if(texture)
            SDL_RenderCopy(renderer, texture, NULL, &getRect());
    }

    void Sprite::setTexture(SDL_Texture* tx){
        texture = tx;
    }
}