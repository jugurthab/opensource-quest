#ifndef __EntryMenu__
#define __EntryMenu__

class EntryMenu : public GeneralStateMachine{
    public:
        void updateState();
        void renderState();
        
        void onEnterState();
        void onExitState();

        void addState();
};


#endif
