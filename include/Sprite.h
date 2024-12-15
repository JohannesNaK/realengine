#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

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
        virtual void draw(SDL_Renderer* renderer);
        virtual void tick() {}

        void setTexture(SDL_Texture* tx);
        const SDL_Rect& Sprite::getRect() const{ return rect; }

    protected:
        Sprite(int x, int y, int w, int h);
        SDL_Rect rect;

    private:
        PhysicsEngine* physicsEngine = nullptr;
        SDL_Texture* texture;

        Sprite(const Sprite& other) = delete;
        const Sprite& operator=(const Sprite& other) = delete;
    };
};

#endif