#ifndef CAMERA_H
#define CAMERA_H
#include "Sprite.h"
#include <SDL2/SDL.h>
namespace reng {
    class Camera {
        public:
        Camera(SDL_Renderer* renderer,  Sprite* sprite);
         Sprite* getSprite() ;
        void setSprite(Sprite* newSprite);
        bool update();
        void setUpdate(bool newState);
        Vector getOrgin();
        void setOrgin(Vector newOrgin);
        void render();
        private:
        bool state = false;
        Sprite* sprite;
        Vector orgin;
        SDL_Renderer* renderer;
          
    };
};
#endif