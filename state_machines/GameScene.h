#ifndef __GameScene__
#define __GameScene__
#include <iostream>
#include <tinyxml2.h>
#include "GeneralStateMachine.h"
#include "../game_objects/MenuObject.h"
#include "../game_objects/TextObject.h"
#include "../game_objects/PlayerUser.h"
#include "../game_objects/Enemy.h"
#include "../game_objects/Block.h"
#include "../game_objects/Users.h"
#include "GameOverScene.h"

class GameScene : public GeneralStateMachine
{
    public:

        GameScene(int gameLevel);
        void updateState();
        void renderState();

        bool onEnterState();
        bool onExitState();

        void handleEvent();

        bool parseXMLLevel();
        std::string getStateName() const { return gameStateID; }
        void clearObjectsFromScene();
        char* setTimeLeftText();
        void setLivesSavedText(int savedLivesCounter);

    private:
        static const std::string gameStateID;
        TextObject *GameSceneText;
        TextObject *savedLives;
        PlayerUser *pUser;
        int playerUserCurrentFrame = 0;
        int playerUserCurrentRow = 0;
        int nbOfSavedLives = 0;
        int nbOfLivesToSave = 0;
        long timeStart = 0;
        long timeEllapsedToUpdate = 0;

        long timeStartGameTimer = 0;
        long timeEllapsedTimer = 0;
        int dx = 0, dy = 0;
        int delta = 0;
        int directionChooser = 0;
        unsigned int timeLeft = 0;

        int gameLevel = 0;
};

#endif
