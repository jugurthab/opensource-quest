#include "GlobalGameObjectBlueprint.h"
 #include "../image_manager/ImgManager.h"
#ifndef __MenuObject__
#define __MenuObject__

class MenuObject : public GlobalGameObjectBlueprint {
    public:
        MenuObject(){};
        void loadObject(std::string imgFileNameP, std::string imageIDP, int imgXPosP, int imgYPosP, int imgWidthP, int imgHeightP, int currentFrameP, int currentRowP);

        void updateObject();
        
        void drawObject(SDL_RendererFlip flip);  
    

};


#endif

