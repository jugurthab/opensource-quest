#ifndef __EntryMenu__
#define __EntryMenu__
#include <iostream>
#include "GeneralStateMachine.h"
#include "../game_objects/MenuObject.h"
#include "../game_objects/TextObject.h"
#include "GameScene.h"

enum Play_Button_State {
    HOVER_NONE = 0,
    HOVER_Y = 1,
    HOVER_Y_CLICKED =2    
};

class EntryMenu : public GeneralStateMachine{
    public:
        void updateState();
        void renderState();
        
        bool onEnterState();
        bool onExitState();

        void handleEvent();
        std::string getStateName() const { return menuStateID; }
        
        void startGame();

        void exitGame();
        void clearObjectsFromScene();

    private:
        static const std::string menuStateID;
        MenuObject *playbutton;

        MenuObject *exitButton;
        TextObject *text;
};


#endif
