#ifndef __GameOverScene__
#define __GameOverScene__
#include <iostream>
#include "GeneralStateMachine.h"
#include "../game_objects/MenuObject.h"
#include "../game_objects/TextObject.h"
#include "EntryMenu.h"

class GameOverScene : public GeneralStateMachine{
    public:
        GameOverScene(bool gameWon = false);
        void updateState();
        void renderState();
        
        bool onEnterState();
        bool onExitState();

        void handleEvent();
        std::string getStateName() const { return gameOverStateID; }

        void goToMainMenu();

        void exitGame();
        void clearObjectsFromScene();

    private:
        static const std::string gameOverStateID;
        MenuObject *gameOverButton;
        MenuObject *restartbutton;
        TextObject *textGameOver;

        int currentFra;
        bool userWinGame;
};


#endif
