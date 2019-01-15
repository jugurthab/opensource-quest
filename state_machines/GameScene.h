#ifndef __GameScene__
#define __GameScene__
#include <iostream>
#include <tinyxml2.h>
#include "GeneralStateMachine.h"
#include "../game_objects/MenuObject.h"
#include "../game_objects/TextObject.h"
#include "GameOverScene.h"
class GameScene : public GeneralStateMachine{
    public:
        void updateState();
        void renderState();
        
        bool onEnterState();
        bool onExitState();

        void handleEvent();

        bool parseXMLLevel();
        std::string getStateName() const { return gameStateID; }

    private:
        static const std::string gameStateID;
        MenuObject *startbutton;
        TextObject *GameSceneText;

        
};


#endif
