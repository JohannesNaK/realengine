#include "Projectile.h"
#include "Sprite.h"

namespace reng{
    
    Projectile::Projectile(int x, int y, int w, int h, int xSpeed, int ySpeed): Sprite(x, y, w, h){
        velocity = Vector(xSpeed, ySpeed);
    }
    Projectile* Projectile::getInstance(int x, int y, int w, int h, int xSpeed, int ySpeed){
        return new Projectile(x, y, w, h, xSpeed, ySpeed);
    }

    void Projectile::tick(){
        move();
    }
}
