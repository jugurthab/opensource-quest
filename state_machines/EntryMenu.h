#ifndef __EntryMenu__
#define __EntryMenu__
#include <iostream>
#include "GeneralStateMachine.h"
#include "../game_objects/MenuObject.h"
class EntryMenu : public GeneralStateMachine{
    public:
        void updateState();
        void renderState();
        
        bool onEnterState();
        bool onExitState();

        
        std::string getStateName() const { return menuStateID; }

    private:
        static const std::string menuStateID;
        MenuObject *startbutton;
};


#endif
