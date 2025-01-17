#ifndef SPRITE_H
#define SPRITE_H

#include "Vector.h"
#include <string>
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

        virtual void draw(SDL_Renderer* renderer);
        virtual bool canBounce() const { return false; } //Make default for Sprite to not be able to bounce
        void move();
        virtual void tick() {}
        void addToPosition(Vector otherPosition);
        void setPosition(Vector newPosition);
        void setVelocity(Vector newVelocity);
        Vector getPosition() const;
        Vector getVelocity() const;
        int getWidth() const;
        int getHeight() const;
     
        void setToRemove(){ removed = true; }
        bool isRemoved() const { return removed; }
        void setTexture(SDL_Texture* tx);
        SDL_Rect& getRect() { return rect; }

    protected:
        Sprite(int x, int y, int w, int h, std::string id);
        Vector position;
        Vector velocity;
        std::string id;
       
        SDL_Rect rect;
        SDL_Texture* texture;
        bool removed = false;

    private:
        Sprite(const Sprite& other) = delete;
        const Sprite& operator=(const Sprite& other) = delete;
    };
};

#endif