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
  GLfloat lightningPos[] = { 40, 20, 10 , 1.0f };
  GLfloat lightningCol[] = {1.0f,1.0f,1.0f,1.0f};


//  for (int i = 0; i<=100; i++)
//  {
//    for (int j = 0; j<=100; j++)
//    {
//      if (i <= 50)
//      {
//        glEnable(GL_LIGHTING);
//        glEnable(GL_LIGHT7);
//        glLightfv(GL_LIGHT7, GL_DIFFUSE, lightningCol);
//        glLightfv(GL_LIGHT7, GL_POSITION, lightningPos);
//      }
//      else
//      {
//        glDisable(GL_LIGHT7);
//      }
//    }
//  }
  std::cout<<"lightning trigger \n";
}
