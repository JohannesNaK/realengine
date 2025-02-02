#include "Ball.h"
#include "GameEngine.h"
#include "Player.h"
#include <SDL2/SDL_image.h>
#include "Constants.h"  
#include "Projectile.h"

namespace reng {

    Ball::Ball(int x, int y, int w, int h, int xSpeed, int ySpeed, Sprite* source)
        : Projectile(x, y, w, h, xSpeed, ySpeed, source) {
            setBounceFromBoundary(true);
            setBounceFromObjects(true);
        }
  
    Ball* Ball::getInstance(int x, int y, int w, int h, int xSpeed, int ySpeed, Sprite* spriteSource) {
        return new Ball(x, y, w, h, xSpeed, ySpeed, spriteSource);
    }

    //RANDOM SPEED?
}