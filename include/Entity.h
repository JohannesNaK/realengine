#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include "Sprite.h"

namespace reng{
    class Entity: public Sprite{
        public:
            Entity(const std::string name, int x, int y, int w, int h, int hp);
            virtual ~Entity() = default;

            virtual void tick();
        protected:
          const std::string name;
          int hp;
           
    };
}


#endif
