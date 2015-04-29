#include "header/FPSCounter.h"
#include "header/scene.h"



/* need to zero out the ticklist array before starting */
/* average will ramp up until the buffer is full */
/* returns average ticks per frame over the MAXSAMPPLES last frames */


void FPS::CalcAverageTick()
{
  ++NumFrames;
  Uint32 elapsedMS = SDL_GetTicks() - startTime;
  if (elapsedMS) { // Skip this the first frame
    double elapsedSeconds = elapsedMS / 1000.0; // Convert to seconds
    frameCount = NumFrames / elapsedSeconds; // FPS is Frames / Seconds
  }
  SDL_Delay(1.0/60.0);
}

void FPS::drawFPS()
{
  GLint matrix;
  glGetIntegerv(GL_MATRIX_MODE, &matrix);

  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0,1,0,1);
    glMatrixMode(GL_MODELVIEW);
      glPushMatrix();
      glLoadIdentity();
      glPushAttrib(GL_COLOR_BUFFER_BIT);
        glColor3f(0,1.0f,0);
        glRasterPos3f(0.9, 0.95, 0);
        std::stringstream strm;
        strm << "FPS = " << frameCount;
        std::string text = strm.str();
        for(std::string::iterator it = text.begin(); it != text.end(); ++it)
        {
          glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *it);
        }
        glPopAttrib();
     glPopMatrix();

   glMatrixMode(GL_PROJECTION);

  glPopMatrix();
  glMatrixMode(matrix);
}
