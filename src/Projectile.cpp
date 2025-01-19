#include "Projectile.h"
#include "Sprite.h"
#include "GameEngine.h"
namespace reng{
    
    Projectile::Projectile(int x, int y, int w, int h, int xSpeed, int ySpeed, Sprite* source): Sprite(x, y, w, h), source(source){
        velocity = Vector(xSpeed, ySpeed);
    }
    Projectile* Projectile::getInstance(int x, int y, int w, int h, int xSpeed, int ySpeed,Sprite* spriteSource){
        return new Projectile(x, y, w, h, xSpeed, ySpeed, spriteSource);
    }
    const Sprite* Projectile::getSource() const{
        return source;
    }
    void Projectile::tick(){
       GameEngine::getInstance()->getPhysicsEngine()->move(*this,velocity);
    }
}
