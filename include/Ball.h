#ifndef BALL_H
#define BALL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h> 
#include "Sprite.h"  
#include "Vector.h"  

namespace reng {

    class Ball : public Sprite {
    public:
        // Constructor for the Ball class
        Ball(int x, int y, int w, int h, int xSpeed, int ySpeed);

        static Ball* getInstance(int x, int y, int w, int h);  // Static method to create a Ball instance

        virtual void tick() override;  //If the ball needs movement logic like velocity updates

        bool canBounce() const override {return true;}
    private:
        Vector velocity;
    };

}

#endif  // BALL_H