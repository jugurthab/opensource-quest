
#ifndef __StateMachineDriver__
#define __StateMachineDriver__
#include <iostream>
#include <vector>
#include "GeneralStateMachine.h"

class StateMachineDriver{
    public:
        static StateMachineDriver* Instance(){
            if(stateMachineDriver==NULL)
                stateMachineDriver = new StateMachineDriver();      
            return stateMachineDriver;
        } 

        void addState(GeneralStateMachine *statMachine);
        void switchState(GeneralStateMachine *statMachine);
        void removeState();

        void updateMachine();
        void renderMachine();

        void handleEventStateMachines();

    private:
        StateMachineDriver(){};
        ~StateMachineDriver(){};
        static StateMachineDriver *stateMachineDriver;
 
        std::vector<GeneralStateMachine*> stateMachines;

};
typedef StateMachineDriver SmileStateMachine;

#endif 
