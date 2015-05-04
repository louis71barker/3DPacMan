#include "header/audio.h"

void Audio::loadSoundChunk(const std::string &_fname,
                           Mix_Chunk **_sound)
{
  *_sound = Mix_LoadWAV(_fname.c_str());
  if(*_sound == NULL)
  {
    std::cerr << "Not able to load audio file:  " << Mix_GetError() << "\n";
  }
}




