#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>
    class GameEngine;
namespace reng
{
    class PhysicsEngine;
 
    class Sprite
    {
    public:
        virtual ~Sprite();

        virtual void mouseDown(const SDL_Event& eve) {}
        virtual void mouseUp(const SDL_Event& eve) {}
        virtual void keyDown(const SDL_Event& eve) {}
        virtual void keyUp(const SDL_Event& eve) {}
        virtual void draw(SDL_Renderer* renderer){};
        virtual void tick() {}

         SDL_Rect* getRect();

    protected:
        Sprite(int x, int y, int w, int h);
    private:
        PhysicsEngine * physicsEngine = nullptr;
        SDL_Rect rect;
        Sprite(const Sprite& other) = delete;
        const Sprite& operator=(const Sprite& other) = delete;
    };
};

#endif