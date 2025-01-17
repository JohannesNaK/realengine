#include "Ball.h"
#include "GameEngine.h"
#include "Player.h"
#include <SDL2/SDL_image.h>
#include "Constants.h"  
#include "Projectile.h"

namespace reng {

    Ball::Ball(int x, int y, int w, int h, int xSpeed, int ySpeed)
        : Projectile(x, y, w, h, xSpeed, ySpeed) {}

    Ball* Ball::getInstance(int x, int y, int w, int h, int xSpeed, int ySpeed) {
        return new Ball(x, y, w, h, xSpeed, ySpeed);
    }

    //RANDOM SPEED?
}