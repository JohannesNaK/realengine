#ifndef SPRITE_H
#define SPRITE_H
#include "Hitbox.h"
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
        bool canBounceFromObjects() const { return bounceObjects; }
        bool canBounceFromBoundary() const { return bounceBoundary; }
        void setBounceFromObjects(bool b){ bounceObjects = b; }
        void setBounceFromBoundary(bool b){ bounceBoundary = b; }
        bool encapsulates(Vector point);
        void move();
        virtual void tick() {}
        void addToPosition(Vector otherPosition);
        void setPosition(Vector newPosition);
        void setVelocity(Vector newVelocity);
        Hitbox getHitBox() const;
        Vector getPosition() const;
        Vector getVelocity() const;
        int getWidth() const;
        int getHeight() const;
     
        void setToRemove(){ removed = true; }
        bool isRemoved() const { return removed; }
        void setTexture(std::string txName);
        SDL_Rect& getRect() { return rect; }

    protected:
        Sprite(int x, int y, int w, int h);
        Vector position;
        Vector velocity;
        SDL_Rect rect;
        SDL_Texture* texture;
        Hitbox hitBox;
        bool removed = false;

        
    private:
        Sprite(const Sprite& other) = delete;
        const Sprite& operator=(const Sprite& other) = delete;

        bool bounceObjects;
        bool bounceBoundary;
    };
}

#endif