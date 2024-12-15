#include "Vector.h"
#include <math.h>
namespace reng
{
    Vector::Vector(int x, int y) {
        this->x = x;
        this->y = y;
    }
    Vector Vector::operator+(const Vector& a) const{
         return Vector(x+a.x,y+a.y);
    }
     Vector Vector::operator-(const Vector& a) const{
         return Vector(x-a.x,y-a.y);
    }
    int Vector::size(){
        return std::sqrt(x*x+y*y);
    }
    float Vector::direction(){
        return 0;
    }
     int Vector::getNormal(){
        return 0;
    }
    int Vector::getX(){
        return x;
    }
    int Vector::getY(){
        return x;
    }
    Vector::~Vector(){
        delete this;
    }
}  