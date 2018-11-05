#include "GlobalGameObjectBlueprint.h"
#include "../image_manager/ImgManager.h"
#include "../font_manager/FontManager.h"

#ifndef __TextObject__
#define __TextObject__

class TextObject : public GlobalGameObjectBlueprint {
    public:
        TextObject(){};
        void loadObject(std::string imgFileNameP, std::string imageIDP, int imgXPosP, int imgYPosP, int imgWidthP, int imgHeightP, int currentFrameP, int currentRowP);

        void updateObject();
        
        void drawObject(SDL_RendererFlip flip);  
    

};


#endif

