#ifndef AUDIO_H__
#define AUDIO_H__

#include <SDL2/SDL_mixer.h>
#include <stdio.h>
#include <iostream>
#include <string>


class Audio
{
public:
  Audio() : audioSuccess(false)
  {

  }


  void loadSoundChunk(const std::string &_fname, Mix_Chunk **_sound);
  bool audioSuccess;



private:



};





#endif
