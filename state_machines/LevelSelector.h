#ifndef __LevelSelector__
#define __LevelSelector__
#include <iostream>
#include <tinyxml2.h>
#include "GeneralStateMachine.h"
#include "../game_objects/MenuObject.h"
#include "../game_objects/TextObject.h"
#include "GameScene.h"

#define NB_MAX_LEVELS 5

class LevelSelector : public GeneralStateMachine
{
    public:
        void updateState();
        void renderState();

        bool onEnterState();
        bool onExitState();

        void handleEvent();

        std::string getStateName() const { return selectorStateID; }
        void clearObjectsFromScene();

    private:
        static const std::string selectorStateID;
        
        MenuObject *levelButtons[NB_MAX_LEVELS];

        TextObject *text;

        int selectedGameLevel = 0;
};

#endif
