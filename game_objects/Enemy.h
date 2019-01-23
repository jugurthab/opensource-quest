
#ifndef __ENEMY__
#define __ENEMY__
#include "GlobalGameObjectBlueprint.h"
 #include "../image_manager/ImgManager.h"
class Enemy : public GlobalGameObjectBlueprint {
    public:
        Enemy(){};
        void loadObject(std::string imgFileNameP, std::string imageIDP, int imgXPosP, int imgYPosP, int imgWidthP, int imgHeightP, int currentFrameP, int currentRowP);

        void updateObject();
        
        void drawObject(SDL_RendererFlip flip);  
    

};


#endif
