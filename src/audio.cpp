#include "header/audio.h"

void Audio::loadSoundChunk(const std::string &_fname,
                           Mix_Chunk **a_sound)
{
  //load a wav file
  *a_sound = Mix_LoadWAV(_fname.c_str());
  //test to see if the file is imported correctly
  if(*a_sound == NULL)
  {
    std::cerr << "Not able to load audio file:  " << Mix_GetError() << "\n";
  }
}




