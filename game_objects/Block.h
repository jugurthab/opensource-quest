#include "GlobalGameObjectBlueprint.h"
 #include "../image_manager/ImgManager.h"
#ifndef __Block__
#define __Block__

class Block : public GlobalGameObjectBlueprint {
    public:
        Block(){};
        void loadObject(std::string imgFileNameP, std::string imageIDP, int imgXPosP, int imgYPosP, int imgWidthP, int imgHeightP, int currentFrameP, int currentRowP);

        void updateObject();
        
        void drawObject(SDL_RendererFlip flip);  
    
        int getObjectState(){return currentFrame;}
        
        void setObjectState(int oState){currentFrame = oState;}

    

};


#endif

