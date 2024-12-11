#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>

namespace reng
{
    class Sprite
    {
    public:
        virtual ~Sprite();

        virtual void mouseDown(const SDL_Event& eve) {}
        virtual void mouseUp(const SDL_Event& eve) {}
        virtual void keyDown(const SDL_Event& eve) {}
        virtual void keyUp(const SDL_Event& eve) {}

        virtual void draw() const = 0;
        virtual void tick() {}

        const SDL_Rect& getRect() const { return rect; }

    protected:
        Sprite(int x, int y, int w, int h);

    private:
        SDL_Rect rect;
        
        Sprite(const Sprite& other) = delete;
        const Sprite& operator=(const Sprite& other) = delete;
    };
};

#endif