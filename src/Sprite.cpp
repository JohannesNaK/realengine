#include "Sprite.h"
#include <SDL2/SDL.h>
namespace reng{
    

    Sprite::Sprite(int x, int y, int w, int h): rect{x, y, w, h} {}
    Sprite::~Sprite(){}
     SDL_Rect *Sprite::getRect()
    {
        return &rect;
    }
}