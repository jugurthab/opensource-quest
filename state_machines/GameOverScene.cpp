#include "EntryMenu.h"

const std::string GameOverScene::gameOverStateID = "GAME_OVER_STATE";


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
                    SmileStateMachine::Instance()->removeState();
                }
                
            break;
    }
}

bool GameOverScene::onEnterState(){
    currentFra =0;
    std::cout << "onEnter GameOverScene" << std::endl;
    startbutton = new MenuObject();
    text = new TextObject(40,{0,255,0});    
    text->loadObject("assets/fonts/PTC55F.ttf", "font", 20, 30, 200, 120, -1, -1);    
    startbutton->loadObject("assets/gameover.bmp", "gameoveranimate", 250, 250, 190, 30, currentFra, 0);
        
    SmileSoundHandler::Instance()->loadSound("assets/music/game_over.mp3", "gameover", SOUND_MUSIC);
    SmileSoundHandler::Instance()->playBackMusic("gameover", 0);



    stateObjects.push_back(startbutton);
    stateObjects.push_back(text);        

    return true;
}
bool GameOverScene::onExitState(){
    std::cout << "onExit GameOverScene" << std::endl;
    return true;
}



