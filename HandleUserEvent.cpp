#include "HandleUserEvent.h"

HandleUserEvent* HandleUserEvent::smileHandleUserEvent = NULL;
SDL_Event HandleUserEvent::updateUserInput(){
    
    SDL_Event event;
    SDL_PollEvent(&event);

    switch(event.type){
        case SDL_QUIT: 
            std::cout << "done" << std::endl;
            SmileGameLogic::Instance()->setGameRunning(false);
        break;

        /*case SDL_MOUSEBUTTONDOWN:
            SmileSoundHandler::Instance()->loadSound("assets/music/can-to-table-1.wav", "knock", SOUND_EFFECT);
            SmileSoundHandler::Instance()->playEffectMusic("knock", 0);

        break;

        case SDL_MOUSEMOTION:


        break;


        case SDL_KEYDOWN:
            switch(event.key.keysym.sym){
                case SDLK_ESCAPE:
                        
                    break;
            }
        break; */
   
    }
    return event;

}


