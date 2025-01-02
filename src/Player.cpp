#include "Player.h"
#include "Vector.h"
#include "GameEngine.h"
#include "KeyboardTrigger.h"
namespace reng {
    Player::Player(const std::string& name, int x, int y, int w, int h, int hp = 1) : Entity(name, x,y,w,h, hp){
        GameEngine& engine = *GameEngine::getInstance();
           engine.addKeyListener([this](KeyboardTrigger& keyTrigger) {
            onW(keyTrigger);
            onA(keyTrigger);
            onS(keyTrigger);
            onD(keyTrigger);
    });
    }
    void Player::tick()
    {
          if (velocity.getX() != 0 || velocity.getY() != 0)
            GameEngine::getInstance()->getPhysicsEngine()->move(*this,velocity);

        if(hp <= 0)
            setToRemove();
    }
    void Player::onW(KeyboardTrigger &keyTrigger)
    {
        if (keyTrigger.getKey() == 'W') {
            if (keyTrigger.getKeyState() == KeyboardTrigger::KeyState::PRESSED) {
                 velocity.setY(-5);
            }else {
                velocity.setY(0);
            }
        }
              
    }
    void Player::onA(KeyboardTrigger& keyTrigger){
        if (keyTrigger.getKey() == 'A') {
             if (keyTrigger.getKeyState() == KeyboardTrigger::KeyState::PRESSED) {
                velocity.setX(-5);
            }else {
                velocity.setX(0);
            }
        }
              
    }
    void Player::onS(KeyboardTrigger& keyTrigger){
        if (keyTrigger.getKey() == 'S'){
             if (keyTrigger.getKeyState() == KeyboardTrigger::KeyState::PRESSED) {
                 velocity.setY(5);
            }else {
                velocity.setY(0);
            }
        }
    }
    void Player::onD(KeyboardTrigger& keyTrigger){
        if (keyTrigger.getKey() == 'D'){
             if (keyTrigger.getKeyState() == KeyboardTrigger::KeyState::PRESSED) {
                 velocity.setX(5);
            }else {
                velocity.setX(0);
            }
        }
    }
}