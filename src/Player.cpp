#include "Player.h"
#include "Vector.h"
#include "GameEngine.h"
#include "KeyboardTrigger.h"
#include "Entity.h"
namespace reng {
    Player::Player(const std::string name, int x, int y, int w, int h, int hp) : Player(name,x,y,w,h,hp,'W','S','A','D')
    {
      
    }
    Player::Player(const std::string name, int x, int y, int w, int h, int hp, char up, char down, char left, char right) :  Entity(name, x,y,w,h, hp),  up(up),down(down),left(left),right(right)
    {
       GameEngine& engine = *GameEngine::getInstance();
           engine.addKeyListener([this](KeyboardTrigger& keyTrigger) {
            onUp(keyTrigger);
            onDown(keyTrigger);
            onLeft(keyTrigger);
            onRight(keyTrigger);
    });
    }
    void Player::tick()
    {
          if (velocity.getX() != 0 || velocity.getY() != 0)
            GameEngine::getInstance()->getPhysicsEngine()->move(*this,velocity);

        if(hp <= 0)
            setToRemove();
    }
    void Player::onUp(KeyboardTrigger &keyTrigger)
    {
        if (keyTrigger.getKey() == up) {
            if (keyTrigger.getKeyState() == KeyboardTrigger::KeyState::PRESSED) {
                 velocity.setY(-5);
            }else {
                velocity.setY(0);
            }
        }
              
    }
    void Player::onDown(KeyboardTrigger& keyTrigger){
        if (keyTrigger.getKey() == down){
             if (keyTrigger.getKeyState() == KeyboardTrigger::KeyState::PRESSED) {
                 velocity.setY(5);
            }else {
                velocity.setY(0);
            }
        }
    }
    void Player::onLeft(KeyboardTrigger& keyTrigger){
        if (keyTrigger.getKey() == left) {
             if (keyTrigger.getKeyState() == KeyboardTrigger::KeyState::PRESSED) {
                velocity.setX(-5);
            }else {
                velocity.setX(0);
            }
        }
              
    }
 
    void Player::onRight(KeyboardTrigger& keyTrigger){
        if (keyTrigger.getKey() == right){
             if (keyTrigger.getKeyState() == KeyboardTrigger::KeyState::PRESSED) {
                 velocity.setX(5);
            }else {
                velocity.setX(0);
            }
        }
    }
}