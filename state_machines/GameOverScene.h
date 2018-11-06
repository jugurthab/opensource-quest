#ifndef __GameOverScene__
#define __GameOverScene__
#include <iostream>
#include "GeneralStateMachine.h"
#include "../game_objects/MenuObject.h"
#include "../game_objects/TextObject.h"
class GameOverScene : public GeneralStateMachine{
    public:
        void updateState();
        void renderState();
        
        bool onEnterState();
        bool onExitState();

        void handleEvent();
        std::string getStateName() const { return gameOverStateID; }

    private:
        static const std::string gameOverStateID;
        MenuObject *startbutton;
        TextObject *text;

        int currentFra;
};


#endif
