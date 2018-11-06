#include "StateMachineDriver.h"

StateMachineDriver* StateMachineDriver::stateMachineDriver = NULL;

void StateMachineDriver::addState(GeneralStateMachine *statMachine){
    stateMachines.push_back(statMachine);
    stateMachines.back()->onEnterState();
}

void StateMachineDriver::switchState(GeneralStateMachine *statMachine){
    if(!stateMachines.empty())
    {
        if(stateMachines.back()->getStateName() == statMachine->getStateName())
        {
            return; // do nothing
        }
        if(stateMachines.back()->onExitState())
        {
            delete stateMachines.back();
            stateMachines.pop_back();
        }
    }

    stateMachines.push_back(statMachine);
    // initialise it
    stateMachines.back()->onEnterState();
}

void StateMachineDriver::removeState(){
    if(!stateMachines.empty())
    {
        if(stateMachines.back()->onExitState())
        {
            delete stateMachines.back();
            stateMachines.pop_back();
        }
    }
}

void StateMachineDriver::updateMachine()
{
    if(!stateMachines.empty())
    {
        stateMachines.back()->updateState();
    }
}

void StateMachineDriver::renderMachine()
{
    if(!stateMachines.empty())
    {
        stateMachines.back()->renderState();
    }
}


void StateMachineDriver::handleEventStateMachines(){
    if(!stateMachines.empty())
    {
        stateMachines.back()->handleEvent();
    }
}
