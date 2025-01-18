#include "Hitbox.h"
#include <math.h>
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
    float Hitbox::size() const {
        return std::sqrt(width*width+height*height);
    }
   
}