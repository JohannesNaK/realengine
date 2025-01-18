#ifndef VECTOR_H
#define VECTOR_H
namespace reng
{
   class Vector{
    public:
    
     Vector(float x, float y);
     Vector();
     void rotate(float theta);
     bool operator==(const Vector& otherVec) const;
     Vector operator+(const Vector& otherVec) const;
     Vector operator-(const Vector& otherVec) const;
     Vector operator*(float a);
     const Vector& operator*=(float a);
     void setX(int newX);
     void setY(int newY);
     int getX() const;
     int getY() const;
     int getNormal();
     Vector direction() const;
     float size() const;
     private:
      float x,y;
   }; 
};

#endif