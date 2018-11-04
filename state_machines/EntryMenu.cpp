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
    startbutton->loadObject("assets/animate.bmp", "animate", 250, 250, 128, 83, -1, -1);
    
    stateObjects.push_back(startbutton);
        

    return true;
}
bool EntryMenu::onExitState(){
    std::cout << "onExit Menu" << std::endl;
    return true;
}



