#ifndef WINDOW_H__
#define WINDOW_H__

#include <SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>



#ifdef LINUX
  #include <GL/gl.h>
#endif
#ifdef DARWIN
  #include <OpenGL/gl.h>
#endif



void SDLErrorExit(const std::string &_err);
SDL_GLContext createOpenGLContext(SDL_Window *_win);



class Window
{
public:
  double screenW,screenH;
  int quit;
  static void SDLInit();
  static void Input();
  void ReshapeScreen();


protected:


};




#endif
