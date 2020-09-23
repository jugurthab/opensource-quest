#include "GameScene.h"
#include <cstdlib>
#include <ctime>

const std::string LevelSelector::selectorStateID = "GAME_LEVEL_SELECTOR";


void LevelSelector::updateState(){
    for(int i=0; i<stateObjects.size();i++)
        stateObjects[i]->updateObject();

}

void LevelSelector::renderState(){    
    for(int i=0; i<stateObjects.size();i++)
        stateObjects[i]->drawObject(SDL_FLIP_NONE);
}

void LevelSelector::handleEvent(){
    SDL_Event event = smileHandleUserEvent::Instance()->updateUserInput();

    switch(event.type){
        
        case SDL_KEYDOWN:
                        
            break;


        case SDL_MOUSEMOTION:
                for(int i = 0;i < NB_MAX_LEVELS; i++){
                    if(event.motion.x > levelButtons[i]->getImgXPos() && event.motion.x < levelButtons[i]->getImgXPos()+levelButtons[i]->getImgWidth() && event.motion.y > levelButtons[i]->getImgYPos() && event.motion.y < levelButtons[i]->getImgYPos()+levelButtons[i]->getImgHeight())
                        levelButtons[i]->setObjectState(1);

                    else{
                        levelButtons[i]->setObjectState(0);   
                    }
                }    
            break;

        case SDL_MOUSEBUTTONDOWN:
                for(int i = 0;i < NB_MAX_LEVELS; i++){
                    if(event.button.x > levelButtons[i]->getImgXPos() && event.button.x < levelButtons[i]->getImgXPos() + levelButtons[i]->getImgWidth() && event.button.y > levelButtons[i]->getImgYPos() && event.button.y < levelButtons[i]->getImgYPos() + levelButtons[i]->getImgHeight()){
                        levelButtons[i]->setObjectState(2);

                        selectedGameLevel = i+1;
                        SmileStateMachine::Instance()->switchState(new GameScene(selectedGameLevel));
                        break;
                    }
                }
            break;

        default:
            break;

    }
}

bool LevelSelector::onEnterState(){
    text = new TextObject(50, {0,0,255}, "Select a level");
    text->loadObject("assets/fonts/Deutsch.ttf", "gameLevelSelector", -1, 30, 200, 120, -1, -1);    
    for(int i = 0;i < NB_MAX_LEVELS; i++){
        levelButtons[i] = new MenuObject();
        char buttonID[20] = "Level";
        sprintf(buttonID, "%s%d", buttonID, i);
        levelButtons[i]->loadObject("assets/game_level.bmp", buttonID, 120, 100 + (i * 75), 400, 50, 0, i);

        stateObjects.push_back(levelButtons[i]);  
    }
    
    SmileSoundHandler::Instance()->loadSound("assets/music/bensound-birthofahero.mp3", "back", SOUND_MUSIC);
    SmileSoundHandler::Instance()->playBackMusic("back", -1);

    stateObjects.push_back(text);
    
    return true;
}

bool LevelSelector::onExitState(){
    clearObjectsFromScene();
    return true;
}

void LevelSelector::clearObjectsFromScene(){
    for (std::vector<GlobalGameObjectBlueprint*>::iterator it = stateObjects.begin() ; it != stateObjects.end(); ++it)
    {
        delete (*it);
    } 
    stateObjects.clear(); 
    gameImgManager::Instance()->clearMapTextureObjects(); 
    SmileSoundHandler::Instance()->clearMapSoundRessources();
}

