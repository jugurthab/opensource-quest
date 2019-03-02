#ifndef __GlobalGameObjectBlueprint__
#define __GlobalGameObjectBlueprint__
#include <iostream>
#include <SDL.h>

class GlobalGameObjectBlueprint {
    public:
        virtual void loadObject(std::string imgFileNameP, std::string imageIDP, int imgXPosP, int imgYPosP, int imgWidthP, int imgHeightP, int currentFrameP, int currentRowP)=0;

        virtual void updateObject()=0;
        
        virtual void drawObject(SDL_RendererFlip flip)=0;

        int getImgXPos(){return imgXPos;}
        void setImgXPos(int imgPosX){imgXPos = imgPosX;}
        int getImgYPos(){return imgYPos;}
        void setImgYPos(int imgPosY){imgYPos = imgPosY;}

        std::string getObjectType(){return objectType;}
        void setObjectType(std::string objectTypeUser){objectType = objectTypeUser;}

        std::string getImgID(){return imageID;}
        int getImgWidth(){return imgWidth;}
        int getImgHeight(){return imgHeight;}

        int getCurrentFrame(){return currentFrame;}
        void setCurrentFrame(int currentFrameUser){currentFrame = currentFrameUser;}
        int getCurrentRow(){return currentRow;}
        void setCurrentRow(int currentRowUser){currentRow = currentRowUser;}

        void setFlipDirection(SDL_RendererFlip flipUser){flip = flipUser;}
    protected:

        int imgXPos;
        int imgYPos;

        int imgWidth;
        int imgHeight;

        std::string imageID;
        int currentFrame;
        int currentRow;
        std::string objectType;
        SDL_RendererFlip flip;
};


#endif 
