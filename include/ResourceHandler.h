#ifndef RESOURCEHANDLER_H
#define RESOURCEHANDLER_H

#include <unordered_map>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

namespace reng{
    class ResourceHandler{
        public:
            void addTexture(std::string name, std::string url);
            void removeTexture(std::string name);
            SDL_Texture* getTexture(std::string name);
            void addFont(std::string name, int size, std::string url);
            void removeFont(std::string name);
            TTF_Font* getFont(std::string name);

            ~ResourceHandler();
        private:
            std::unordered_map<std::string, SDL_Texture*> textures;
            std::unordered_map<std::string, TTF_Font*> fonts;
    };
}

#endif