#include "RectSprite.h"
#include <SDL2/SDL.h>
namespace reng
{
    void RectSprite::draw(SDL_Renderer* renderer) {            
                // Set the draw color
                SDL_SetRenderDrawColor(renderer, rectColor.r, rectColor.g, rectColor.b, rectColor.a);
                SDL_RenderFillRect(renderer, &getRect());
        }
} // namespace name
