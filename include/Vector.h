#ifndef VECTOR_H
#define VECTOR_H
namespace reng
{
   class Vector{
    public:
     Vector(int x, int y);
     void rotate(float theta);
     Vector operator+(const Vector& a) const;
     Vector operator-(const Vector& y) const;
     void operator*(float a);
     void setX(int newX);
     void setY(int newY);
     int getX();
     int getY();
     int getNormal();
     Vector direction();
     int size();
     private:
     int x;
     int y;
   }; 
};

#endif