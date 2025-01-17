#ifndef TEXTUREHANDLER_H
#define TEXTUREHANDLER_H

#include <unordered_map>
#include <string>
#include <SDL2/SDL.h>

namespace reng{
    class TextureHandler{
        public:
            void addTexture(std::string name, std::string url);
            void removeTexture(std::string name);
            SDL_Texture* getTexture(std::string name);

            ~TextureHandler();
        private:
            std::unordered_map<std::string, SDL_Texture*> textures;
            //map med counts??
    };
}

#endif