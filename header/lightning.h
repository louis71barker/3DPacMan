/// INCLUDE GUARD CHANGE TO NAME OF FILE BELOW
#ifndef LIGHTNING_H__
#define LIGHTNING_H__

///Here are all the includes that are needed
#include <SDL2/SDL.h>
#include "header/scene.h"
#include "header/audio.h"

class Lightning
{
public:

  Audio au;
  Mix_Chunk *a_Thunder;
  Lightning()
  {
    lightningTrig = false;
  }
  ~Lightning()
  {
    //------------------------------------------------------------------------------------------------------------------
    ///Here is the free function to clear the memory saved for the music file
    //------------------------------------------------------------------------------------------------------------------
    Mix_FreeChunk(a_Thunder);
  }

  void lightningAudio() { au.loadSoundChunk("sounds/Thunder.wav", &a_Thunder); }

  void drawLightning();
  bool lightningTrig;



private:
  void setTimer();


};







#endif
