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
#include "header/collectables.h"
#include "header/ghost.h"
#include "header/arena.h"
#include "header/window.h"
#include "header/camera.h"
#include "header/walls.h"
#include "header/barn.h"
#include "header/fence.h"
#include "header/helicopter.h"
#include "header/FPSCounter.h"
#include "header/lightning.h"
#include "header/geoDome.h"
#include "header/audio.h"



#ifdef LINUX
  #include <GL/gl.h>
#endif
#ifdef DARWIN
  #include <OpenGL/gl.h>
#endif

//call the lighting class so it is able to start with the timer on a seperate thread
Lightning li;
//when the timer triggers
Uint32 timerCallback(Uint32 timer, void *)
{
    if(li.m_lightningTrig == false)
    {
      li.m_lightningTrig = true;
      SDL_Delay(70);
      li.m_lightningTrig = false;
      SDL_Delay(100);
      li.m_lightningTrig = true;
      SDL_Delay(100);
      li.m_lightningTrig = false;
    }
    return timer;
}

//start of the main
int main(int argc, char** argv)
{
  //init all the SDL required and the Audio class
  Audio au;
  if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO)<0)
  {
    SDLErrorExit("Unable to init SDL");
  }

  //initialize SDL_mixer
  if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
  {
   std::cout<< "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << "\n";
   au.m_audioSuccess = false;
  }

  //initialize glut
  glutInit(&argc, argv);
  //bind the thunder sound file now mixer is initialized
  li.lightningAudio();

  //this grabs the screen size's
  SDL_Rect _rect;
  SDL_GetDisplayBounds(0, &_rect);


  SDL_Window *win;
  Window w;
  //set screen width and height
  w.m_screenH = _rect.w;
  w.m_screenH = _rect.h;
  //create the window
  win=SDL_CreateWindow("Pacnesia", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _rect.w, _rect.h, SDL_WINDOW_OPENGL);

  //error check to make sure window is open
  if (!win)
  {
    SDLErrorExit("Unable to create a window");
  }

  SDL_GLContext gl=createOpenGLContext(win);
  //error check for SDL
  if(!gl)
  {
    SDLErrorExit("Problem creating OpenGL Context");
  }

  //start the time with 15 secs
  SDL_TimerID timerID = SDL_AddTimer(15000, timerCallback, (void*) NULL);

  //construct all the remaining classes
  Walls wa;
  Arena a;
  Camera cam;
  Ghost gho(wa.m_matrix);
  Collectable col(wa.m_matrix);
  Barn ba(wa.m_matrix);
  Heli he(wa.m_matrix);
  Fence fe(wa.m_matrix);
  geoDome gd;

  SDL_GL_MakeCurrent(win,gl);
  SDL_GL_SetSwapInterval(1);

  glMatrixMode(GL_PROJECTION);
  gluPerspective(45.0f,float(_rect.w)/_rect.h,0.5,500.0);
  glMatrixMode(GL_MODELVIEW);

  glEnable(GL_NORMALIZE);

  glClearColor(0,0,0,1);

  //set the lighting for the scene
  w.Lighting();

  int quit = 0;
  while(!quit)
  {
//    grabs the mouse to keep inside window, not the best method atm as no mouse border detection working
//    SDL_ShowCursor(SDL_DISABLE);
//    SDL_SetWindowGrab(win, SDL_TRUE);
    int _mouseX, _mouseY;
    //get the mouse pos
    SDL_GetMouseState(&_mouseX, &_mouseY);
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
                            case SDLK_w : cam.m_moveForward=true; break;
                            case SDLK_s : cam.m_moveBackward=true; break;
                            case SDLK_a : cam.m_strafeLeft=true; break;
                            case SDLK_d : cam.m_strafeRight=true; break;
                            case SDLK_p : cam.m_mouseInScreen=false; SDL_ShowCursor(SDL_ENABLE); break;

                            }
                          }break;
       //set values back the key is released
       case SDL_KEYUP : {
                        switch(e.key.keysym.sym)
                        {
                        case SDLK_w : cam.m_moveForward=false; break;
                        case SDLK_s : cam.m_moveBackward=false; break;
                        case SDLK_a : cam.m_strafeLeft=false; break;
                        case SDLK_d : cam.m_strafeRight=false; break;
                        }
       }break;
       case SDL_MOUSEBUTTONDOWN:
           {
               if(e.button.button == SDL_BUTTON_LEFT)
               {
                 //checks to see if the mouse is inside to screen to disable the pointer
                  cam.m_mouseInScreen = true;
                  SDL_ShowCursor(SDL_DISABLE);
                  break;
               }
            }
         break;
       }
    }
    //starts the frame timer
    frameStart();

    //calls the display lists and value editors from all the classes
    cam.cameraUpdate(wa.m_matrix,_mouseX,_mouseY);
    col.drawCollectable(wa.m_matrix,cam.m_playerXpos,cam.m_playerZpos);
    gho.updater(wa.m_matrix);
    wa.draw();
    a.drawArena();
    ba.drawBarn();
    fe.drawFence();
    he.drawHeli();
    li.drawLightning();
    gd.drawdome();


    //end of the frame timer
    frameEnd(GLUT_BITMAP_HELVETICA_10, 1.0 , 0.0 , 0.0 , 0.85 , 0.95);

    //swap the buffer
    SDL_GL_SwapWindow(win);

  }


  // Disable the timer
  SDL_RemoveTimer(timerID);

  //destroy the window when closing
  SDL_DestroyWindow(win);

  //quit sdl at end of program
  SDL_Quit();

  //quit Mixer at end of program
  Mix_Quit();
  return 0;
}

