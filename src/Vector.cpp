#include "Vector.h"
#include <math.h>
#include <iostream>
namespace reng
{
    Vector::Vector(int x, int y) : x(x), y(y){
      
    }
    bool Vector::operator==(const Vector& otherVec) const{
        return x == otherVec.x && y == otherVec.y;
    }
    Vector Vector::operator+(const Vector& otherVec) const{
         return Vector(x+otherVec.x,y+otherVec.y);
    }
     Vector Vector::operator-(const Vector& otherVec) const{
         return Vector(x-otherVec.x,y-otherVec.y);
    }
    Vector Vector::operator*(float a) {
       return Vector(x*a,y*a);
    }
    void Vector::rotate(float theta){
        x = std::cos(theta);
        y = std::sin(theta);
    }
    int Vector::size() const{
        return std::sqrt(x*x+y*y);
    }
    Vector Vector::direction() const{
       return Vector(x/size(),y/size());
    }
     int Vector::getNormal(){
        return 0;
    }
    void Vector::setX(int newX){
        x = newX;
    }
    void Vector::setY(int newY){
        y = newY;
    }
    int Vector::getX() const{
        return x;
    }
    int Vector::getY() const{
        return y;
    }
   
}  
