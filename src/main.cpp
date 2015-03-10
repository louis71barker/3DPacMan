#include <cstdlib>
#include <cmath>
#include <SDL.h>
#include <iostream>
#include <string>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <vector>
#include <time.h>
#include "header/player.h"
#include "header/collectables.h"
#include "header/ghost.h"
#include "header/arena.h"
#include "header/window.h"


#ifdef LINUX
  #include <GL/gl.h>
#endif
#ifdef DARWIN
  #include <OpenGL/gl.h>
#endif


int main()
{
  if(SDL_Init(SDL_INIT_VIDEO)<0)
  {
    SDLErrorExit("Unable to init SDL");
  }

  static int mouseX,mouseY;


  //this grabs the screen size's
  SDL_Rect _rect;

  SDL_GetDisplayBounds(0, &_rect);


  SDL_Window *win;
  Window w;
  w.screenH = _rect.w;
  w.screenH = _rect.h;
  win=SDL_CreateWindow("3D Maze Man", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _rect.w/2, _rect.w/2, SDL_WINDOW_OPENGL);

  if (!win)
  {
    SDLErrorExit("Unable to create a window");
  }

  SDL_GLContext gl=createOpenGLContext(win);
  if(!gl)
  {
    SDLErrorExit("Problem creating OpenGL Context");
  }
  Arena a;

  SDL_GL_MakeCurrent(win,gl);
  SDL_GL_SetSwapInterval(1);
  float zCam = 0.5f;

  glMatrixMode(GL_PROJECTION);
  gluPerspective(150.0f,float(_rect.w)/_rect.h,0.1,100.0);
  glMatrixMode(GL_MODELVIEW);
  gluLookAt(0,0,zCam,0,0,0,0,1,0);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_NORMALIZE);
  // Enable lighting
//  glEnable(GL_LIGHTING);
//  glEnable(GL_LIGHT0);
  glClearColor(0,222,222,1);






  int quit = 0;
  while(!quit)
  {
    SDL_GetMouseState(&mouseX, &mouseY);
    SDL_Event e;

    while(SDL_PollEvent(&e))
    {
       switch(e.type)
       {
        case SDL_WINDOWEVENT : {int w,h;
                                SDL_GetWindowSize(win, &w, &h);
                                glViewport(0,0,w,h);
                               }break;

        case SDL_QUIT:quit = 1;break;

        case SDL_KEYDOWN : {
                            switch(e.key.keysym.sym)
                            {
                            case SDLK_ESCAPE : quit = 1; break;
                            case SDLK_w : glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); break;
                            case SDLK_s : glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); break;

                            }
                          }break;
       case SDL_MOUSEBUTTONDOWN:
           {
               if(e.button.button == SDL_BUTTON_LEFT)
               {
                zCam++;
                std::cout<<"bomaihjslakjd\n"<<zCam;
               }
               if(e.button.button == SDL_BUTTON_RIGHT)
               {

               }
            }
         break;

       case SDL_MOUSEBUTTONUP:
       {
         if (e.button.button == SDL_BUTTON_LEFT)
         {


         }
       }
         break;

       }




    }


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);




    a.drawArena();




    SDL_GL_SwapWindow(win);





  }






  SDL_Quit();
  return 0;
}

