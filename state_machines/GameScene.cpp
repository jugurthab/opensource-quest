#include "EntryMenu.h"

const std::string GameScene::gameStateID = "GAME_STATE";


void GameScene::updateState(){
    
    for(int i=0; i<stateObjects.size();i++)
        stateObjects[i]->updateObject();

    
        
}
void GameScene::renderState(){
    
    for(int i=0; i<stateObjects.size();i++)
        stateObjects[i]->drawObject(SDL_FLIP_NONE);

}
        

void GameScene::handleEvent(){
    SDL_Event event = smileHandleUserEvent::Instance()->updateUserInput();

    switch(event.type){
        
        case SDL_KEYDOWN:
                if(event.key.keysym.sym==SDLK_ESCAPE){
                    std::cout << "GameScene" <<std::endl;
                    SmileStateMachine::Instance()->switchState(new GameOverScene());
                }
                
            break;
    }
}

bool GameScene::onEnterState(){
    std::cout << "onEnter GameScene" << std::endl;
    startbutton = new MenuObject();
    startbutton->loadObject("assets/animate.bmp", "animate", 250, 250, 128, 83, 0, 0);
    text = new TextObject(40, {255,0,255});
    text->loadObject("assets/fonts/PTC55F.ttf", "font", 20, 30, 200, 120, -1, -1);
    SmileSoundHandler::Instance()->loadSound("assets/music/backMusic.mp3", "back", SOUND_MUSIC);
    SmileSoundHandler::Instance()->playBackMusic("back", -1);



    stateObjects.push_back(startbutton);
    stateObjects.push_back(text);        

    return true;
}
bool GameScene::onExitState(){
    std::cout << "onExit GameScene" << std::endl;
    return true;
}



