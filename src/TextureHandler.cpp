#include <string>
#include <SDL2/SDL.h>
#include "GameEngine.h"
#include "TextureHandler.h"
#include <stdexcept>

namespace reng{
    void TextureHandler::addTexture(std::string name, std::string url){
        SDL_Texture* tx = IMG_LoadTexture(GameEngine::getInstance()->getRenderer(), url.c_str() );
        if (!tx)
            SDL_Log("Failed to load texture: %s", SDL_GetError());
        
        if(textures[name])
            throw std::invalid_argument("Can't have two textures with same name!");

        textures[name] = tx;
    }

    void TextureHandler::removeTexture(std::string name){
        //Framtid kanske checka om används

        SDL_Texture* toRemove = textures[name];
        textures.erase(name);
        SDL_DestroyTexture(toRemove);
    }

    SDL_Texture* TextureHandler::getTexture(std::string name){
        return textures[name];
    }

    TextureHandler::~TextureHandler(){
        for(auto t: textures){
            delete t.second;
        }
    }
}