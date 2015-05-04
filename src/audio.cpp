#include "header/audio.h"

void Audio::loadSoundChunk(const std::string &_fname,
                           Mix_Chunk **a_sound)
{
  *a_sound = Mix_LoadWAV(_fname.c_str());
  if(*a_sound == NULL)
  {
    std::cerr << "Not able to load audio file:  " << Mix_GetError() << "\n";
  }
}




