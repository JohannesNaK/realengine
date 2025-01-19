#include <string>
#include <SDL2/SDL.h>
#include "GameEngine.h"
#include "ResourceHandler.h"
#include <stdexcept>

namespace reng{
    void ResourceHandler::addTexture(std::string name, std::string url){
        SDL_Texture* tx = IMG_LoadTexture(GameEngine::getInstance()->getRenderer(), url.c_str() );
        if (!tx)
            SDL_Log("Failed to load texture: %s", SDL_GetError());
        
        if(textures.count(name))
            throw std::invalid_argument("Can't have two textures with same name!");

        textures[name] = tx;
    }

    void ResourceHandler::removeTexture(std::string name){
        //Framtid kanske checka om används

        SDL_Texture* toRemove = textures[name];
        textures.erase(name);
        SDL_DestroyTexture(toRemove);
    }

    SDL_Texture* ResourceHandler::getTexture(std::string name){
        return textures[name];
    }

    ResourceHandler::~ResourceHandler(){
        for(auto t: textures)
            SDL_DestroyTexture(t.second);
    }


    void ResourceHandler::addFont(std::string name, int size, std::string url){
        TTF_Font* font = TTF_OpenFont(url.c_str(), size);
        if(fonts.count(name))
            throw std::invalid_argument("Can't have two textures with same name!");

        fonts[name] = font;
    }

    void ResourceHandler::removeFont(std::string name){
        TTF_Font* toRemove = fonts[name];
        fonts.erase(name);
        TTF_CloseFont(toRemove);
    }

    TTF_Font* ResourceHandler::getFont(std::string name){
        return fonts[name];
    }

    ResourceHandler::~ResourceHandler(){
        for(auto t: textures)
            SDL_DestroyTexture(t.second);
        for(auto f: fonts)
            TTF_CloseFont(f.second);
    }
}