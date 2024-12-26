#include "Vector.h"
#include <math.h>
#include <iostream>
namespace reng
{
    Vector::Vector(int x, int y) : x(x), y(y){
      
    }
    Vector Vector::operator+(const Vector& a) const{
         return Vector(x+a.x,y+a.y);
    }
     Vector Vector::operator-(const Vector& a) const{
         return Vector(x-a.x,y-a.y);
    }
    void Vector::operator*(float a) {
        x = x*a;
        y = y*a;
    }
    void Vector::rotate(float theta){
        x = std::cos(theta);
        y = std::sin(theta);
    }
    int Vector::size(){
        return std::sqrt(x*x+y*y);
    }
    Vector Vector::direction(){
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
    int Vector::getX(){
        return x;
    }
    int Vector::getY(){
        return y;
    }
   
}  
