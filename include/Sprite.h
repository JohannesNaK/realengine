#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Vector.h"
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
        virtual void draw(SDL_Renderer* renderer);
        void move();
        virtual void tick() {}
        void setPosition(Vector newPosition);
        void setVelocity(Vector newVelocity);
        Vector getPosition();
        Vector getVelocity();
        bool isRemoved(){ return removed; }
        void setTexture(SDL_Texture* tx);
        SDL_Rect& getRect() { return rect; }

    protected:
        Sprite(int x, int y, int w, int h);
        Vector position;
        Vector velocity;
        SDL_Rect rect;
        SDL_Texture* texture;
        bool removed = false;

    private:
        Sprite(const Sprite& other) = delete;
        const Sprite& operator=(const Sprite& other) = delete;
    };
};

#endif