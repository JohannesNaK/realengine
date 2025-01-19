#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Event.h"
#include "KeyboardTrigger.h"
#include "Vector.h"
#include <string>
#include <unordered_map>
#include "Label.h"
namespace reng {
    class Player : public Entity {
        public:
            virtual ~Player() = default;
             virtual void tick() override;
            int getHP() const;
            void setHP(int newHP);
            void setUpKey();
            void setDownKey();
            void setLeftKey();
            void setRightKey();

            //Method to enable certain keys
            void enableKey(char key, bool enable);
            
            void setTextLabel(std::string text);
            Label* getLabel(){
                return label;
            }
            int getHeight() const;
            int getWidth() const;

            static Player* getInstance(std::string  name, int x, int y, int w, int h, int hp, Label* label);
            static Player* getInstance( std::string  name, int x, int y, int w, int h, int hp, char up, char down, char left, char right, Label* label);        

        protected:
            Player( std::string  name, int x, int y, int w, int h, int hp,Label* label);
            Player( std::string  name, int x, int y, int w, int h, int hp, char up, char down, char left, char right, Label* label);

        private:
     
  
            int h;
            int w;

            char up,down,left,right;
            void onUp(KeyboardTrigger& keyTrigger);
            void onDown(KeyboardTrigger& keyTrigger);
            void onLeft(KeyboardTrigger& keyTrigger);
            void onRight(KeyboardTrigger& keyTrigger);
            static Event<KeyboardTrigger> keys;
        
            //Map for key enabling
            std::unordered_map<char, bool> keyEnabled;
            Label* label;
    };
};
#endif