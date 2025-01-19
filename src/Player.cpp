#include "Player.h"
#include "Vector.h"
#include "GameEngine.h"
#include "KeyboardTrigger.h"
#include "Entity.h"

namespace reng {

    Player::Player( std::string name, int x, int y, int w, int h, int hp) : Player(name,x,y,w,h,hp,'W','S','A','D') {    }
    
    Player::Player( std::string name, int x, int y, int w, int h, int hp, char up, char down, char left, char right) :  Entity(name, x,y,w,h, hp),  up(up),down(down),left(left),right(right)
    {
        GameEngine& engine = *GameEngine::getInstance();
        engine.addKeyListener([this](KeyboardTrigger& keyTrigger) {
        onUp(keyTrigger);
        onDown(keyTrigger);
        onLeft(keyTrigger);
        onRight(keyTrigger);
    });
        //Initialize key states, all enabled by default
        keyEnabled[up] = true;
        keyEnabled[down] = true;
        keyEnabled[left] = true;
        keyEnabled[right] = true;
    }
  
    void Player::tick() {
        auto* engine = GameEngine::getInstance();
        engine->getPhysicsEngine()->move(*this, velocity);
        if (hp <= 0) {
            setToRemove();
        }
    }
    void Player::onUp(KeyboardTrigger &keyTrigger)
    {
        if (keyTrigger.getKey() == up) {
            
            if (keyTrigger.getKeyState() == KeyboardTrigger::KeyState::PRESSED && keyEnabled[up]) {
                 velocity.setY(-5);
            }else {
                velocity.setY(0);
            }
        }
              
    }

    void Player::onDown(KeyboardTrigger& keyTrigger){
        if (keyTrigger.getKey() == down){
             if (keyTrigger.getKeyState() == KeyboardTrigger::KeyState::PRESSED && keyEnabled[down]) {
                 velocity.setY(5);
            }else {
                velocity.setY(0);
            }
        }
    }

    void Player::onLeft(KeyboardTrigger& keyTrigger){
        if (keyTrigger.getKey() == left) {
             if (keyTrigger.getKeyState() == KeyboardTrigger::KeyState::PRESSED && keyEnabled[left]) {
                velocity.setX(-5);
            }else {
                velocity.setX(0);
            }
        }
              
    }
 
    void Player::onRight(KeyboardTrigger& keyTrigger){
        if (keyTrigger.getKey() == right){
             if (keyTrigger.getKeyState() == KeyboardTrigger::KeyState::PRESSED && keyEnabled[right]) {
                 velocity.setX(5);
            }else {
                velocity.setX(0);
            }
        }
    }

    int Player::getHeight() const {
        return h;
    }

    int Player::getWidth() const {
        return w;
    }

    //Enable key
    void Player::enableKey(char key, bool enable) {
        if(keyEnabled.find(key) != keyEnabled.end()) {
            keyEnabled[key] = enable;
        }
    }

    Player* Player::getInstance(std::string  name, int x, int y, int w, int h, int hp){
        return new Player(name, x, y, w, h, hp);
    }
    Player* Player::getInstance( std::string  name, int x, int y, int w, int h, int hp, char up, char down, char left, char right){
        return new Player(name, x, y, w, h, hp, up, down, left, right);
    }
}