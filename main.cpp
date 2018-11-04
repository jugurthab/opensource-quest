#include <iostream>
#include "GameLogic.h"


int main(int arg, char *argv[]){
    

    if(!SmileGameLogic::Instance()->initGameLogic()){
        return -1;
    }


    while(SmileGameLogic::Instance()->getGameRunning()){

        SmileGameLogic::Instance()->handleUserInput();
        
        SmileGameLogic::Instance()->updateGameLogic();

        SmileGameLogic::Instance()->renderSceneGameLogic();    


        SDL_Delay(10);        
    }



    SmileGameLogic::Instance()->cleanGameScene();

    return 0;
}
