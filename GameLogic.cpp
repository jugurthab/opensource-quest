
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
    stateMachineDriver = new StateMachineDriver();
    stateMachineDriver->switchState(new EntryMenu());

    setGameRunning(true);

    return true;
    
}

void GameLogic::handleUserInput(){
    HandleUserEvent::Instance()->updateUserInput();
}

void GameLogic::updateGameLogic(){
    stateMachineDriver->updateMachine();

}

void GameLogic::renderSceneGameLogic(){
    SDL_RenderClear(smileRenderer);
    stateMachineDriver->renderMachine();
    SDL_RenderPresent(smileRenderer);
    
}

void GameLogic::cleanGameScene(){
    SDL_DestroyWindow(smileWindow);
    SDL_DestroyRenderer(smileRenderer);
    SDL_Quit();
}
