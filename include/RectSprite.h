#ifndef RECTSPRITE_H
#define RECTSPRITE_H
#include "Sprite.h"
#include <SDL2/SDL.h>

namespace reng
{
    class RectSprite : public Sprite
    {
    public:
        RectSprite(int x, int y, int w, int h, SDL_Color color)
            : Sprite(x, y, w, h), rectColor(color) {}

       
        void draw(SDL_Renderer* renderer)  override;

    private:
        SDL_Color rectColor; 
    };
}

#endif