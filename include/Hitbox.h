
#ifndef HITBOX_H
#define HITBOX_H
#include "Vector.h"
namespace reng
{
  class Hitbox {
    public:
        Hitbox(int width, int height);
        int getWidth() const;
        int getHeight() const;
        float size() const;
    private:
        int width,  height;

  };
};

#endif