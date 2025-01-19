#include "GameEngine.h"
#include "Label.h"
#include <SDL2/SDL_ttf.h>
#include "Sprite.h"

namespace reng
{

    Label* Label::getInstance(int x, int y, int w, int h, std::string txt, std::string font){ return new Label(x, y, w, h, txt, font); }

    Label::Label(int x, int y, int w, int h, std::string txt, std::string f): Sprite(x, y, w, h), text(txt) {
        font = GameEngine::getInstance()->getResourceHandler().getFont(f);
        SDL_Surface* surf = TTF_RenderText_Solid(, text.c_str(), {0, 0, 0});
        texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
        SDL_FreeSurface(surf);
    }
    
    std::string Label::getText() const { return text; }

    void Label::setText(std::string newText){
        text = newText;

        SDL_DestroyTexture(texture);
        SDL_Surface* surf = TTF_RenderText_Solid(sys.get_font(), text.c_str(), {0, 0, 0});
        texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
        SDL_FreeSurface(surf);
    }

    Label::~Label()
    {
        SDL_DestroyTexture(texture);
    }
};