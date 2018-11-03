
#ifndef __GameLogic__
#define __GameLogic__

#include <iostream>
#include <SDL.h>
#include "game_objects/PlayerUser.h" 
#include "EntryMenu.h"

class GameLogic{
    public:
    static GameLogic* Instance(){
        if(g_lInstance==NULL){
            g_lInstance = new GameLogic();
        }
        return g_lInstance;
    }    


    bool initGameLogic();

    void handleUserInput();

    void updateGameLogic();

    void renderSceneGameLogic();

    void cleanGameScene();

    SDL_Renderer* getRenderer() const {return  smileRenderer;} 

    void setGameRunning(bool gameStat){
        gameRunning = gameStat;
    }
    
    bool getGameRunning(){
        return gameRunning;
    }

    private:
        GameLogic() {}
        ~GameLogic() {}


    static GameLogic* g_lInstance;

    SDL_Window *smileWindow;
    SDL_Renderer *smileRenderer;
    PlayerUser *p;
    bool gameRunning;
    EntryMenu *m;

};
typedef GameLogic SmileGameLogic;

#endif
