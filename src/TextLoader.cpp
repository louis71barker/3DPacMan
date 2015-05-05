#include "scene.h"
//#include <SDL_image.h>
#include <SDL2/SDL_image.h>
#include <GL/gl.h>

void textLoader(const std::string &_fname, GLuint &_tid)
{
  SDL_Surface *text;
  text = IMG_Load(_fname.c_str());
  //checks to make sure texture is loaded properly
  if (!(text = IMG_Load(_fname.c_str())))
  {
    std::cerr<<"Could not load texture  " << _fname<<"  "<<IMG_GetError()<< "\n";
    exit(EXIT_FAILURE);
  }
  glGenTextures(1, &_tid);
  glBindTexture(GL_TEXTURE_2D, _tid);
  glTexImage2D(GL_TEXTURE_2D,
               0,
               (text->format->BytesPerPixel == 4 ? GL_RGBA : GL_RGB),
               text->w,
               text->h,
               0,        
               (text->format->BytesPerPixel == 4 ? GL_RGBA : GL_RGB),
               GL_UNSIGNED_BYTE,
               text->pixels);

  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  SDL_FreeSurface(text);


}
