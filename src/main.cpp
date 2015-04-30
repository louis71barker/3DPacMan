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
#include "header/camera.h"
#include "header/walls.h"
#include "header/lights.h"
#include "header/skyDome.h"
#include "header/barn.h"
#include "header/fence.h"
#include "header/helicopter.h"
#include "header/FPSCounter.h"
#include "header/lightning.h"


#ifdef LINUX
  #include <GL/gl.h>
#endif
#ifdef DARWIN
  #include <OpenGL/gl.h>
#endif

Lightning li;
Uint32 timerCallback(Uint32 interval, void *) {

    if(li.lightningTrig == false)
    {
      li.lightningTrig = true;
      SDL_Delay(100);
      li.lightningTrig = false;
    }
    return interval;
}

int main(int argc, char** argv)
{
  if(SDL_Init(SDL_INIT_VIDEO)<0)
  {
    SDLErrorExit("Unable to init SDL");
  }

  glutInit(&argc, argv);
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Init(SDL_INIT_TIMER);

  //this grabs the screen size's
  SDL_Rect _rect;
  SDL_GetDisplayBounds(0, &_rect);


  SDL_Window *win;
  Window w;
  w.screenH = _rect.w;
  w.screenH = _rect.h;
  win=SDL_CreateWindow("Pacnesia", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _rect.w, _rect.h, SDL_WINDOW_OPENGL);

  if (!win)
  {
    SDLErrorExit("Unable to create a window");
  }

  SDL_GLContext gl=createOpenGLContext(win);
  if(!gl)
  {
    SDLErrorExit("Problem creating OpenGL Context");
  }


  SDL_TimerID timerID = SDL_AddTimer(15000, /*elapsed time in milliseconds*/
                                   timerCallback, /*callback function*/
                                   (void*) NULL /*parameters (none)*/);

  Walls wa;
  Arena a(wa.matrix);
  Camera cam;
  Ghost gho(wa.matrix);
  Player p;
  Collecable col(wa.matrix);
  Lights l;
  skyDome sd;
  Barn ba(wa.matrix);
  Heli he(wa.matrix);
  Fence fe(wa.matrix);


//  wa.initMaze(wa.matrix);
  a.ground(wa.matrix);
//  sd.sky();








  SDL_GL_MakeCurrent(win,gl);
  SDL_GL_SetSwapInterval(1);

  glMatrixMode(GL_PROJECTION);
  gluPerspective(45.0f,float(_rect.w)/_rect.h,0.5,500.0);
  glMatrixMode(GL_MODELVIEW);

  glEnable(GL_NORMALIZE);

  glClearColor(0,0,0,1);




  w.Lighting();



  int quit = 0;
  while(!quit)
  {

    SDL_ShowCursor(SDL_DISABLE);
    SDL_SetWindowGrab(win, SDL_TRUE);
    int mouseX,mouseY;
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
                            case SDLK_i : glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); break;
                            case SDLK_k : glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); break;
                            case SDLK_w : cam.moveForward=true; break;
                            case SDLK_s : cam.moveBackward=true; break;
                            case SDLK_a : cam.strafeLeft=true; break;
                            case SDLK_d : cam.strafeRight=true; break;
                            case SDLK_p : cam.mouseInScreen=false; SDL_ShowCursor(SDL_ENABLE); break;
                            case SDLK_1 : if (cam.thirdPersonCam == true) {cam.firstPersonCam = true; cam.thirdPersonCam = false;} break;
                            case SDLK_2 : if (cam.firstPersonCam == true) {cam.firstPersonCam = false; cam.thirdPersonCam = true;} break;

                            }
                          }break;
       case SDL_KEYUP : {
                        switch(e.key.keysym.sym)
                        {
                        case SDLK_w : cam.moveForward=false; break;
                        case SDLK_s : cam.moveBackward=false; break;
                        case SDLK_a : cam.strafeLeft=false; break;
                        case SDLK_d : cam.strafeRight=false; break;
                        }
       }break;
       case SDL_MOUSEBUTTONDOWN:
           {
               if(e.button.button == SDL_BUTTON_LEFT)
               {
                  cam.mouseInScreen = true;
                  SDL_ShowCursor(SDL_DISABLE);
                  break;
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

    frameStart();

    cam.cameraUpdate(wa.matrix,mouseX,mouseY);
    col.drawCollectable(wa.matrix,cam.playerXpos,cam.playerZpos);


    sd.drawSky();
    gho.updater();
    wa.draw();
    a.drawArena(wa.matrix);
    ba.drawBarn();
    fe.drawFence();
    he.drawHeli();
    li.drawLightning();


    l.distanceCal(wa.matrix);

    frameEnd(GLUT_BITMAP_HELVETICA_10, 1.0 , 0.0 , 0.0 , 0.85 , 0.95);

    SDL_GL_SwapWindow(win);

  }


  // Disable our timer
  SDL_RemoveTimer(timerID);

  SDL_DestroyWindow(win);

  SDL_Quit();
  return 0;
}

