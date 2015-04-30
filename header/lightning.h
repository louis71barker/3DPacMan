#ifndef LIGHTNING_H__
#define LIGHTNING_H__
#include <SDL2/SDL.h>
#include "header/scene.h"


class Lightning
{
public:
  Lightning()
  {
    lightningTrig = false;

  }

  void drawLightning();
  bool lightningTrig;



private:
  void setTimer();


};







#endif
