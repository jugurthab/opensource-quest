
#ifndef __ImgManager__
#define __ImgManager__

#include <iostream>
#include <SDL.h>
#include <map>
#include "../GameLogic.h"
class ImgManager{
    public:
        static ImgManager* Instance(){
            if(imgManager==NULL)
                imgManager = new ImgManager();

            return imgManager;
        }

        void loadImage(std::string imgFilename, std::string imageID);

        void drawImage(std::string imageID, int imgXPos, int imgYPos, int imgWidth, int imgHeight, SDL_RendererFlip flip=SDL_FLIP_NONE);

        void drawSpriteAnimation(std::string imageID, int imgXPos, int imgYPos, int imgWidth, int imgHeight, int currentFrame, int currentRow, SDL_RendererFlip flip=SDL_FLIP_NONE);

    private:
        ImgManager(){}
        ~ImgManager(){}
        static ImgManager* imgManager;
        std::map<std::string, SDL_Texture*> imgLoaded;
};
typedef ImgManager gameImgManager;
#endif
