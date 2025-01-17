#include "Entity.h"

namespace reng{
    Entity::Entity(const std::string name, int x, int y, int w, int h, int hp) : Sprite(x,y,w,h,name), name(name), hp (hp){}

    void Entity::tick(){
        if(hp <= 0)
            setToRemove();
    }

    Entity* Entity::getInstance(const std::string name, int x, int y, int w, int h, int hp){
        return new Entity(name, x, y, w, h, hp);
    }
}