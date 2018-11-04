#ifndef __HandleUserEvent__
#define __HandleUserEvent__

#include <iostream>
#include <SDL.h>
#include "GameLogic.h"
#include "soundHandler/SoundHandler.h"

class HandleUserEvent
{
    public:
        
        static HandleUserEvent* Instance()
        {
            if(smileHandleUserEvent == 0)
            {
                smileHandleUserEvent = new HandleUserEvent();
            }
            
            return smileHandleUserEvent;
        }


        void updateUserInput();
    private:

        static HandleUserEvent* smileHandleUserEvent;

};
typedef HandleUserEvent smileHandleUserEvent;
#endif

