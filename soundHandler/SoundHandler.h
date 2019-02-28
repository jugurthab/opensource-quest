#ifndef __SoundHandler__
#define __SoundHandler__

#include <iostream>
#include <map>
#include <SDL_mixer.h>
enum choice_sound {
    SOUND_MUSIC = 0,
    SOUND_EFFECT = 1    
};


class SoundHandler{

    public:
        static SoundHandler* Instance(){
            if(soundManager==NULL)
                soundManager = new SoundHandler();

            return soundManager;
        } 

       
        bool loadSound(std::string soundFileName, std::string soundID, choice_sound type);

        void playBackMusic(std::string soundID, int looping);

        void playEffectMusic(std::string soundID, int looping);
        void clearMapSoundRessources();

    private:
        static SoundHandler *soundManager;
        
        SoundHandler();
        ~SoundHandler();


        std::map<std::string, Mix_Music*> m_music;
        std::map<std::string, Mix_Chunk*> m_chunk;        

};
typedef SoundHandler SmileSoundHandler;
#endif
