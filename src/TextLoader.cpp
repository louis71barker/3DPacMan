#include "scene.h"
#include <SDL/SDL_image.h>
#include <GL/gl.h>

void textLoader(const std::string &_fname, GLuint &_tid)
{
  SDL_Surface *text;

  // load support for the JPG and PNG image formats
//  int flags=IMG_INIT_JPG|IMG_INIT_PNG;
//  int initted=IMG_Init(flags);
//  if((initted && flags != flags))
//  {
//      printf("IMG_Init: Failed to init required jpg and png support!\n");
//      printf("IMG_Init: %s\n", IMG_GetError());
//      // handle error
//  }
  text = IMG_Load(_fname.c_str());
  if (!(text = IMG_Load(_fname.c_str())))
  {
    std::cerr<<"Could not load texture  " << _fname<<"  "<<IMG_GetError()<< "\n";
    exit(EXIT_FAILURE);
  }

  glGenTextures(1, &_tid);
  glBindTexture(GL_TEXTURE_2D, _tid);
  glTexImage2D(GL_TEXTURE_2D,
               0,
               GL_RGB,
               text->w,
               text->h,
               0,
               GL_RGB,
               GL_UNSIGNED_BYTE,
               text->pixels);

  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  SDL_FreeSurface(text);


}
