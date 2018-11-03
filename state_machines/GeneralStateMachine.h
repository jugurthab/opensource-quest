
#include <iostream>

class GeneralStateMachine{
   public:
        virtual void updateState() = 0;
        virtual void renderState() = 0;
        
        virtual void onEnterState() = 0;
        virtual void onExitState() = 0;

        virtual void addState() = 0;
        virtual void switchState() = 0;
        virtual void removeState() = 0;

    private:

        std::vector<GeneralStateMachine*> smileGameState;

}
