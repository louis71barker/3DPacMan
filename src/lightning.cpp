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
  //lighting location and setting
  GLfloat lightningPos[] = { 10, 0, 10 , 1.0f };
  GLfloat lightningCol[] = {5.0f,5.0f,5.0f,1.0f};
  GLfloat  ambientLight[] = { 0.5f, 0.5f, 0.5f, 1.0f};
  GLfloat  specular[] = { 1.0f, 1.0f, 1.0f, 1.0f};

  //once the timer has triggered in seperate thread
  if (m_lightningTrig == true)
  {
    //light 3 is for the lightning
    glEnable(GL_LIGHT3);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT3, GL_DIFFUSE, lightningCol);
    glLightfv(GL_LIGHT3,GL_SPECULAR,specular);
    glLightfv(GL_LIGHT3, GL_POSITION, lightningPos);
    //sets the sound of thunder on high volume
    Mix_VolumeChunk(a_Thunder, MIX_MAX_VOLUME * 0.9);
    //plays the sound of thunder
    Mix_PlayChannel(-1, a_Thunder, 0);
   }
  else
    //disable the lighning light when timer is not full
   glDisable(GL_LIGHT3);
}
