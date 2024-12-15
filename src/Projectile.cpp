#include "Projectile.h"
#include "Sprite.h"

namespace reng{
    Projectile::Projectile(int x, int y, int w, int h, int xSpeed, int ySpeed): Sprite(x, y, w, h), velocity(xSpeed, ySpeed) {}

    void Projectile::tick(){
        rect.x += velocity.getX();
        rect.y += velocity.getY();
    }
}
