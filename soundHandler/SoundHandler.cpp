#include "SoundHandler.h"

SoundHandler* SoundHandler::soundManager = NULL;

SoundHandler::SoundHandler(){
    Mix_OpenAudio(22050, AUDIO_S16, 2, 4096);
}

bool SoundHandler::loadSound(std::string soundFileName, std::string soundID,choice_sound type){
     if(type == SOUND_MUSIC){
        Mix_Music *mMusic = NULL;

        mMusic = Mix_LoadMUS(soundFileName.c_str());
    
        if(mMusic==NULL){
            fprintf(stderr, "Cannot load music %s\n", SDL_GetError());
            return false;
        }

        m_music[soundID] = mMusic;

     }
     else{
        Mix_Chunk *mChunk = NULL;
        mChunk = Mix_LoadWAV(soundFileName.c_str());

        if(mChunk==NULL){
            fprintf(stderr, "Cannot load chunk %s\n", SDL_GetError());
            return false;
        }
        
        m_chunk[soundID] = mChunk;

     }   

     return true;    
}

void SoundHandler::playBackMusic(std::string soundID, int looping){
    Mix_PlayMusic(m_music[soundID], looping);   
}

void SoundHandler::playEffectMusic(std::string soundID, int looping){
    Mix_PlayChannel(-1, m_chunk[soundID], looping);
}

SoundHandler::~SoundHandler(){
    Mix_CloseAudio();
}

