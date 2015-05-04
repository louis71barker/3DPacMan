#include "header/lightning.h"
#include "SDL2/SDL_timer.h"

#ifdef LINUX
  #include <GL/gl.h>
#endif
#ifdef DARWIN
  #include <OpenGL/gl.h>
#endif




void Lightning::drawLightning()
{
  GLfloat lightningPos[] = { 10, 0, 10 , 1.0f };
  GLfloat lightningCol[] = {5.0f,5.0f,5.0f,1.0f};
  GLfloat  ambientLight[] = { 0.5f, 0.5f, 0.5f, 1.0f};
  GLfloat  specular[] = { 1.0f, 1.0f, 1.0f, 1.0f};

  if (lightningTrig == true)
  {
    std::cout<<"lightning trigger \n";

//          glEnable(GL_LIGHTING);
          glEnable(GL_LIGHT3);
          glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
          glLightfv(GL_LIGHT3, GL_DIFFUSE, lightningCol);
          glLightfv(GL_LIGHT3,GL_SPECULAR,specular);
          glLightfv(GL_LIGHT3, GL_POSITION, lightningPos);

          Mix_VolumeChunk(a_Thunder, MIX_MAX_VOLUME * 0.9);

          Mix_PlayChannel(-1, a_Thunder, 0);
   }
  else
   glDisable(GL_LIGHT3);



}
