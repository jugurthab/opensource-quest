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
        
bool EntryMenu::onEnterState(){
    std::cout << "onEnter Menu" << std::endl;
    startbutton = new MenuObject();
    startbutton->loadObject("assets/animate.bmp", "animate", 250, 250, 128, 83, 0, 0);
    text = new TextObject();
    text->loadObject("assets/fonts/PTC55F.ttf", "font", 20, 30, 200, 120, -1, -1);
    SmileSoundHandler::Instance()->loadSound("assets/music/backMusic.mp3", "back", SOUND_MUSIC);
    SmileSoundHandler::Instance()->playBackMusic("back", -1);



    stateObjects.push_back(startbutton);
    stateObjects.push_back(text);        

    return true;
}
bool EntryMenu::onExitState(){
    std::cout << "onExit Menu" << std::endl;
    return true;
}



