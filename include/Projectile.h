#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SDL2/SDL.h>
#include "Sprite.h"
#include "Vector.h"

namespace reng{
    class Projectile: public Sprite{
        public:
            static Projectile* getInstance(int x, int y, int w, int h, int xSpeed, int ySpeed, Sprite* source);
            virtual void tick();
            
            virtual ~Projectile() = default;
              Sprite* getSource() const;
        protected:
            Sprite* source;
            Projectile(int x, int y, int w, int h, int xSpeed, int ySpeed, Sprite* source);          
    };
}

#endif