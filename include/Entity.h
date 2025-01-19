#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include "Sprite.h"

namespace reng{
    class Entity: public Sprite{
        public:            
            virtual ~Entity() = default;
            virtual void tick();
            virtual void damage(int damage);
            static Entity* getInstance(const std::string name, int x, int y, int w, int h, int hp);
        protected:
            Entity(const std::string name, int x, int y, int w, int h, int hp);
            const std::string name;
            int hp;
    };
}


#endif
