#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include "Sprite.h"

namespace reng{
    class Entity: public Sprite{
        public:
            Entity(const std::string& name, int x, int y, int w, int h, int hp = 1);
            virtual ~Entity();

            virtual void tick();
        protected:
            int hp;
            const std::string name;
    };
}


#endif
