#include "Vector.h"
#include <math.h>
#include <iostream>
namespace reng
{
    Vector::Vector(float  x, float y) : x(x), y(y) {}

    // Default constructor added here
    Vector::Vector() : x(0), y(0) {}
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
    const Vector& Vector::operator*=(float a) {
       x *= a;
       y *= a;
       return *this;
    }
    void Vector::rotate(float theta){
        x = std::cos(theta);
        y = std::sin(theta);
    }
    float Vector::size() const{
        return std::sqrt(x*x+y*y);
    }
    Vector Vector::direction() const{
 
       return  size() != 0.0 ? Vector(x/size(),y/size()) : Vector(0,0);
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
