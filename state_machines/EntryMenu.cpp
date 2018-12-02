#include "EntryMenu.h"

const std::string EntryMenu::menuStateID = "MENU_STATE";


void EntryMenu::updateState(){
    
    for(int i=0; i<stateObjects.size();i++)
        stateObjects[i]->updateObject();

    
        
}
void EntryMenu::renderState(){
    
    for(int i=0; i<stateObjects.size();i++)
        stateObjects[i]->drawObject(SDL_FLIP_NONE);

}
        

void EntryMenu::handleEvent(){
    SDL_Event event = smileHandleUserEvent::Instance()->updateUserInput();

    switch(event.type){
        
        case SDL_KEYDOWN:
                if(event.key.keysym.sym==SDLK_ESCAPE){
                    
                    exitGame();
                }
                        
            break;


        case SDL_MOUSEMOTION:
                if(event.motion.x > playbutton->getImgXPos() && event.motion.x<playbutton->getImgXPos()+playbutton->getImgWidth() && event.motion.y > playbutton->getImgYPos() && event.motion.y<playbutton->getImgYPos()+playbutton->getImgHeight())
                    playbutton->setObjectState(1);
        
                else if(event.motion.x > exitButton->getImgXPos() && event.motion.x < exitButton->getImgXPos()+ exitButton->getImgWidth() && event.motion.y > exitButton->getImgYPos() && event.motion.y< exitButton->getImgYPos()+ exitButton->getImgHeight())
                    exitButton->setObjectState(1);

                else{
                    playbutton->setObjectState(0);
                    exitButton->setObjectState(0);   
                 }       
            break;

        case SDL_MOUSEBUTTONDOWN:
                if(event.button.x > playbutton->getImgXPos() && event.button.x<playbutton->getImgXPos()+playbutton->getImgWidth() && event.button.y > playbutton->getImgYPos() && event.button.y<playbutton->getImgYPos()+playbutton->getImgHeight()){
                    playbutton->setObjectState(2);
                    startGame();
                }

                else if(event.button.x > exitButton->getImgXPos() && event.button.x < exitButton->getImgXPos()+ exitButton->getImgWidth() && event.button.y > exitButton->getImgYPos() && event.button.y < exitButton->getImgYPos()+ exitButton->getImgHeight()){
                    exitButton->setObjectState(2);
                    exitGame();
                }
            break;

        default:
            break;

    }
}

bool EntryMenu::onEnterState(){
    std::cout << "onEnter Menu" << std::endl;
    text = new TextObject(50, {0,0,255}, "Welcome to OpenSource Quest");
    text->loadObject("assets/fonts/Deutsch.ttf", "gameTitle", 35, 30, 200, 120, -1, -1);    
    playbutton = new MenuObject();
    exitButton = new MenuObject();
    playbutton->loadObject("assets/play_button.bmp", "playButton", 120, 150, 400, 100, 0, -1);
    exitButton->loadObject("assets/exit.bmp", "exitButton", 120, 290, 400, 100, 0, -1); 
    SmileSoundHandler::Instance()->loadSound("assets/music/backMusic.mp3", "back", SOUND_MUSIC);
    SmileSoundHandler::Instance()->playBackMusic("back", -1);



    stateObjects.push_back(playbutton);
    stateObjects.push_back(exitButton);
    stateObjects.push_back(text);        

    return true;
}
bool EntryMenu::onExitState(){
    std::cout << "onExit Menu" << std::endl;
    return true;
}


void EntryMenu::startGame(){
    SmileStateMachine::Instance()->switchState(new GameScene());   
}

void EntryMenu::exitGame(){
    GameLogic::Instance()->cleanGameScene();
}
