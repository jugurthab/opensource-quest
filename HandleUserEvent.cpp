#include "HandleUserEvent.h"

HandleUserEvent* HandleUserEvent::smileHandleUserEvent = NULL;
void HandleUserEvent::updateUserInput(){
    
    SDL_Event event;
    SDL_WaitEvent(&event);

    switch(event.type){
        case SDL_QUIT: 
            std::cout << "done" << std::endl;
            SmileGameLogic::Instance()->setGameRunning(false);
        break;

        case SDL_MOUSEBUTTONDOWN:

        break;

        case SDL_MOUSEMOTION:


        break;


        case SDL_KEYDOWN:

        break;    
    }

}


