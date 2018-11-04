
#ifndef __StateMachineDriver__
#define __StateMachineDriver__
#include <iostream>
#include <vector>
#include "GeneralStateMachine.h"

class StateMachineDriver{
    public:
        void addState(GeneralStateMachine *statMachine);
        void switchState(GeneralStateMachine *statMachine);
        void removeState();

        void updateMachine();
        void renderMachine();

    private:
        std::vector<GeneralStateMachine*> stateMachines;

};


#endif 
