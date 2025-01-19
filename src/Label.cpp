#include "GameEngine.h"
#include "Label.h"
#include <SDL2/SDL_ttf.h>
#include "Sprite.h"

namespace reng
{

    Label* Label::getInstance(int x, int y, int w, int h, std::string txt, std::string font){ return new Label(x, y, w, h, txt, font); }

    Label::Label(int x, int y, int w, int h, std::string txt, std::string f): Sprite(x, y, w, h), text(txt), color({0U, 0U, 0U}) {
        setCollidable(false);
        font = GameEngine::getInstance()->getResourceHandler()->getFont(f);
        updateTexture();
    }

    std::string Label::getText() const { return text; }
    void Label::setText(std::string newText){
        text = newText;
        updateTexture();
    }

    void Label::setColor(Uint8 r, Uint8 g, Uint8 b){
        color = {r, g, b};
        updateTexture();
    }

    void Label::updateTexture(){
        if(texture)
            SDL_DestroyTexture(texture);

        SDL_Surface* surf = TTF_RenderText_Solid(font, text.c_str(), {color});
        texture = SDL_CreateTextureFromSurface(GameEngine::getInstance()->getRenderer(), surf);
        SDL_FreeSurface(surf);
    }

    Label::~Label()
    {
        SDL_DestroyTexture(texture);
    }
};