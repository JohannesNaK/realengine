#ifndef BALL_H
#define BALL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Projectile.h"

namespace reng {

    class Ball : public Projectile {
    public:
        static Ball* getInstance(int x, int y, int w, int h, int xSpeed, int ySpeed);
        //Listener 
        virtual ~Ball() = default;
    
    protected:
        Ball(int x, int y, int w, int h, int xSpeed, int ySpeed);
    };
}

#endif