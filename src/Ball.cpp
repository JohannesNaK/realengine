#include "Ball.h"
#include "GameEngine.h"
#include "Player.h"
#include <cstdlib>  // For random number generation
#include <SDL2/SDL_image.h>
#include "Constants.h"  
#include "Sprite.h"

namespace reng {

    // Constructor for Ball (sets initial position and velocity)
    Ball::Ball(int x, int y, int w, int h, int xSpeed, int ySpeed)
        : Sprite(x, y, w, h, "ball") {
        velocity = Vector(xSpeed, ySpeed);
    }

    // Static method to get a new Ball instance with random initial speed
    Ball* Ball::getInstance(int x, int y, int w, int h) {
        int xSpeed = 2;
        int ySpeed = 2; 
        return new Ball(x, y, w, h, xSpeed, ySpeed);
    }

    void Ball::tick() {
        auto* engine = GameEngine::getInstance();
        Vector currentVelocity = getVelocity();

        if (velocity.getX() != 0 || velocity.getY() != 0) {
            engine->getPhysicsEngine()->move(*this, currentVelocity);
        }
    }
}