#ifndef RECTSPRITE_H
#define RECTSPRITE_H
#include "Sprite.h"
#include <SDL2/SDL.h>

namespace reng
{
    class RectSprite : public Sprite
    {
        public:
            void draw(SDL_Renderer* renderer)  override;
            static RectSprite* getInstance(int x, int y, int w, int h, SDL_Color color);

        private:
            RectSprite(int x, int y, int w, int h, SDL_Color color)
                : Sprite(x, y, w, h), rectColor(color) {}
            SDL_Color rectColor; 
    };
}

#endif