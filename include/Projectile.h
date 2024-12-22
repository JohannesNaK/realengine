#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SDL2/SDL.h>
#include "Sprite.h"
#include "Vector.h"

namespace reng{
    class Projectile: public Sprite{
        public:
            static Projectile* getInstance(int x, int y, int w, int h, int xSpeed, int ySpeed);
            virtual void tick();

            Vector& getVelocity() { return velocity; }

        protected:
            Vector velocity;
            Projectile(int x, int y, int w, int h, int xSpeed, int ySpeed);
            
    };
}

#endif