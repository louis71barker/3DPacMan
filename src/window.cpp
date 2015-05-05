#include <cstdlib>
#include <iostream>
#include <string>
#include "window.h"

void SDLErrorExit(const std::string &_err)
{
  std::cerr<<_err<<"\n";
  std::cerr<<SDL_GetError()<<"\n";
  SDL_Quit();
  exit(EXIT_FAILURE);
}

SDL_GLContext createOpenGLContext(SDL_Window *_win)
{
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,2);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,1);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,16);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);

  return SDL_GL_CreateContext(_win);
}

void Window::Lighting() const
{
  //enables the all lighing elements needs throughout the game
  glEnable(GL_TEXTURE_2D);
  glEnable(GL_POINT_SPRITE);
  glEnable(GL_BLEND);
  glShadeModel(GL_SMOOTH);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_COLOR_MATERIAL);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_NORMALIZE);
  glDepthFunc(GL_LEQUAL);
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}
