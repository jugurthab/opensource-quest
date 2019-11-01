#include "EntryMenu.h"

const std::string GameOverScene::gameOverStateID = "GAME_OVER_STATE";

GameOverScene::GameOverScene(bool gameWon){
    userWinGame = gameWon;
}

void GameOverScene::updateState(){
    currentFra = (SDL_GetTicks()/20) %2;
    for(int i=0; i<stateObjects.size();i++)
        stateObjects[i]->updateObject();    
        
}
void GameOverScene::renderState(){
    
    for(int i=0; i<stateObjects.size();i++)
        stateObjects[i]->drawObject(SDL_FLIP_NONE);

}
        

void GameOverScene::handleEvent(){
    SDL_Event event = smileHandleUserEvent::Instance()->updateUserInput();

    switch(event.type){
        
        case SDL_KEYDOWN:
                if(event.key.keysym.sym==SDLK_ESCAPE){
                    std::cout << "GameScene" <<std::endl;
                    //SmileStateMachine::Instance()->removeState();
                    SmileStateMachine::Instance()->switchState(new EntryMenu());
                }
                
            break;


        case SDL_MOUSEMOTION:
                if(event.motion.x > restartbutton->getImgXPos() && event.motion.x<restartbutton->getImgXPos()+restartbutton->getImgWidth() && event.motion.y > restartbutton->getImgYPos() && event.motion.y<restartbutton->getImgYPos()+restartbutton->getImgHeight())
                    restartbutton->setObjectState(1);
        
                /*else if(event.motion.x > exitButton->getImgXPos() && event.motion.x < exitButton->getImgXPos()+ exitButton->getImgWidth() && event.motion.y > exitButton->getImgYPos() && event.motion.y< exitButton->getImgYPos()+ exitButton->getImgHeight())
                    exitButton->setObjectState(1);*/

                else{
                    restartbutton->setObjectState(0);
                  //  exitButton->setObjectState(0);   
                 }       
            break;

        case SDL_MOUSEBUTTONDOWN:
                if(event.button.x > restartbutton->getImgXPos() && event.button.x<restartbutton->getImgXPos()+restartbutton->getImgWidth() && event.button.y > restartbutton->getImgYPos() && event.button.y<restartbutton->getImgYPos()+restartbutton->getImgHeight()){
                    restartbutton->setObjectState(2);
                    goToMainMenu();
                }

/*                else if(event.button.x > exitButton->getImgXPos() && event.button.x < exitButton->getImgXPos()+ exitButton->getImgWidth() && event.button.y > exitButton->getImgYPos() && event.button.y < exitButton->getImgYPos()+ exitButton->getImgHeight()){
                    exitButton->setObjectState(2);
                    exitGame();
                }*/
            break;

        default:
            break;

    }
}

bool GameOverScene::onEnterState(){
    currentFra =0;
    if(userWinGame){
        textGameOver = new TextObject(40, {255, 255, 0}, "Well done!");
    } else {
        textGameOver = new TextObject(40, {0, 255, 0}, "Do not loose hope!");
    }

    textGameOver->loadObject("assets/fonts/Deutsch.ttf", "gameoverfont", -1, 30, 200, 120, -1, -1);
    std::cout << "onEnter GameOverScene" << std::endl;
    gameOverButton = new MenuObject();
        
    restartbutton = new MenuObject();
    restartbutton->loadObject("assets/restart_button.bmp", "restartButton", 220, 150, 200, 100, 0, 0);
    
    gameOverButton->loadObject("assets/gameover.bmp", "gameoveranimate", 230, 350, 190, 30, currentFra, 0);
        
    SmileSoundHandler::Instance()->loadSound("assets/music/game_over.mp3", "gameover", SOUND_MUSIC);
    SmileSoundHandler::Instance()->playBackMusic("gameover", 0);

    stateObjects.push_back(gameOverButton);
    stateObjects.push_back(restartbutton);
    stateObjects.push_back(textGameOver);        

    return true;
}
bool GameOverScene::onExitState(){
    std::cout << "onExit GameOverScene" << std::endl;
    clearObjectsFromScene();
    return true;
}

void GameOverScene::goToMainMenu(){
    SmileStateMachine::Instance()->switchState(new EntryMenu());   
}

void GameOverScene::exitGame(){
    GameLogic::Instance()->cleanGameScene();
}

void GameOverScene::clearObjectsFromScene(){
    for (std::vector<GlobalGameObjectBlueprint*>::iterator it = stateObjects.begin() ; it != stateObjects.end(); ++it)
    {
        delete (*it);
    } 
    stateObjects.clear(); 
    gameImgManager::Instance()->clearMapTextureObjects(); 
    SmileSoundHandler::Instance()->clearMapSoundRessources();
}

