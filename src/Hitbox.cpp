#include "Hitbox.h"

namespace reng {
    Hitbox::Hitbox(int width, int  height)
    : width(width), height(height) {

    }
      int Hitbox::getWidth() const {
        return width;
    }
    int Hitbox::getHeight() const{
        return height;
    }
   
}