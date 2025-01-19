#ifndef LABEL_H
#define LABEL_H

#include <string>
#include <SDL2/SDL.h>
#include "Sprite.h"

namespace reng
{
    class Label: public Sprite{
    public:
        static Label* getInstance(int x, int y, int w, int h, std::string txt, std::string font);
        std::string getText() const;
        void setText(std::string newText);
        virtual ~Label() = default;
        
    protected:
        Label(int x, int y, int w, int h, std::string txt, std::string font);

    private:
        std::string text;
        TTF_Font* font;
    };
};

#endif