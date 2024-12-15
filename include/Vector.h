#ifndef VECTOR_H
#define VECTOR_H
namespace reng
{
   class Vector{
    public:
     Vector(int x, int y);
     ~Vector();
     Vector operator+(const Vector& a) const;
     Vector operator-(const Vector& y) const;
     int getX();
     int getY();
     int getNormal();
     float direction();
     int size();
     const int length = 2;
     private:
     int x;
     int y;
   }; 
};

#endif