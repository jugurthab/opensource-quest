
#include "GameLogic.h" 

GameLogic* GameLogic::g_lInstance = NULL;

bool GameLogic::initGameLogic(){
    if(SDL_Init(SDL_INIT_VIDEO)<0){
        fprintf(stderr, "Cannot Init SDL %s\n", SDL_GetError());
        return false;
    }

    smileWindow = SDL_CreateWindow("OpenSource Quest", 12, 12, 640, 480 , SDL_WINDOW_SHOWN);

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
    
    SmileStateMachine::Instance()->switchState(new EntryMenu());

    setGameRunning(true);

    return true;
    
}

void GameLogic::handleUserInput(){
    SmileStateMachine::Instance()->handleEventStateMachines();
}

void GameLogic::updateGameLogic(){
    SmileStateMachine::Instance()->updateMachine();

}

void GameLogic::renderSceneGameLogic(){
    SDL_RenderClear(smileRenderer);
    SmileStateMachine::Instance()->renderMachine();
    SDL_RenderPresent(smileRenderer);
    
}

void GameLogic::cleanGameScene(){
    setGameRunning(false);
    SDL_DestroyWindow(smileWindow);
    SDL_DestroyRenderer(smileRenderer);
    SDL_Quit();
    
}
