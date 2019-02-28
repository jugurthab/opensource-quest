
#ifndef __GeneralStateMachine__
#define __GeneralStateMachine__

#include <iostream>
#include <SDL.h>
#include <vector>
#include "../game_objects/GlobalGameObjectBlueprint.h"
class GeneralStateMachine{
   public:
        virtual void updateState() = 0;
        virtual void renderState() = 0;
        
        virtual bool onEnterState() = 0;
        virtual bool onExitState() = 0;


        virtual void handleEvent() = 0;
        virtual std::string getStateName() const = 0;
        virtual void clearObjectsFromScene() = 0;

    protected:

        std::vector<GlobalGameObjectBlueprint*> stateObjects;
        
        

};

#endif
