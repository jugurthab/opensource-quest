
#include "GameLogic.h" 

GameLogic* GameLogic::g_lInstance = NULL;

bool GameLogic::initGameLogic(){
    if(SDL_Init(SDL_INIT_VIDEO)<0){
        fprintf(stderr, "Cannot Init SDL %s\n", SDL_GetError());
        return false;
    }

    smileWindow = SDL_CreateWindow("Smile Quest To openSource World", 12, 12, 640, 480 , SDL_WINDOW_SHOWN);

    if(smileWindow==NULL){
        fprintf(stderr, "Cannot Create Window %s\n", SDL_GetError());
        return false;
    }


    smileRenderer = SDL_CreateRenderer(smileWindow, -1, 0);
    if(smileRenderer==NULL){
        fprintf(stderr, "Cannot Create Renderer %s\n", SDL_GetError());
        return false;
    }
    
    
    SDL_SetRenderDrawColor(smileRenderer, 255, 255, 255, 255);
    p = new PlayerUser();
    p->loadObject("assets/rider.bmp", "rider", 0, 0, 128, 83, -1, -1);
    
    setGameRunning(true);

    return true;
    
}

void GameLogic::handleUserInput(){
    SDL_Event event;
    SDL_WaitEvent(&event);

    switch(event.type){
        case SDL_QUIT: setGameRunning(false); break;
            
        default:
            break;

    }
}

void GameLogic::updateGameLogic(){


}

void GameLogic::renderSceneGameLogic(){
    SDL_RenderClear(smileRenderer);
    p->drawObject(SDL_FLIP_NONE);   
    SDL_RenderPresent(smileRenderer);
    
}

void GameLogic::cleanGameScene(){
    SDL_DestroyWindow(smileWindow);
    SDL_DestroyRenderer(smileRenderer);
    SDL_Quit();
}
