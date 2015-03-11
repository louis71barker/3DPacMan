#include <stdlib.h>
#include <iostream>
#include "header/camera.h"
#include <SDL.h>
//#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <math.h>



#ifdef LINUX
  #include <GL/gl.h>
#endif
#ifdef DARWIN
  #include <OpenGL/gl.h>
#endif



void Camera::cameraStrafe()
{
  if (strafeLeft == true)
  {
    camCentre.m_x += 0.1;
    camEye.m_x += 0.1;
    std::cout << "left pressed \n";
  }
  if (strafeRight == true)
  {
    camCentre.m_x -= 0.1;
    camEye.m_x -= 0.1;
  }
  if (moveBackward == true)
  {
    camCentre.m_z -= 0.1;
    camEye.m_z -= 0.1;
  }
  if (moveForward == true)
  {
    camCentre.m_z += 0.1;
    camEye.m_z += 0.1;
  }

}

void Camera::cameraMouse()
{

}

void Camera::lockCamera()
{
  if (camPitch > 90)
  {
    camPitch = 90;
  }
  if (camPitch < -90)
  {
    camPitch = -90;
  }
  if (camYaw <0.0f)
  {
    camYaw += 360.0;
  }
  if (camYaw > 360.0f)
  {
    camYaw -= 360.0f;
  }
}

void Camera::cameraMovement(float dist, float dir)
{
   float rad = (camYaw + dir)*M_PI/180;
   camCoor.m_x -= sin(rad)*dist;
   camCoor.m_z -= cos(rad)*dist;
}

void Camera::moveCameraUp(float dist, float dir)
{
  float rad = (camPitch + dir)*M_PI/180;
  camCoor.m_y += sin(rad)*dist;
}

void Camera::camerControl(float moveVel, float mouseVel, bool MInS, float WinWidth, float WinHeight, SDL_Window *win)
{
  if (MInS)
  {
    int midX = WinWidth/2;
    int midY = WinHeight/2;
    SDL_ShowCursor(SDL_DISABLE);
    int mouseX,mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    camYaw += mouseVel*(midX-mouseX);
    camPitch += mouseVel*(midY-mouseY);
    //SDL_WarpMouseInWindow(win, midX, midY);
    lockCamera();

    if (moveForward == true)
    {
      if (camPitch !=90 && camPitch !=-90)
      {
        cameraMovement(moveVel,0.0);
      }
      moveCameraUp(moveVel,0.0);
    }
    if (moveBackward == true)
    {
      if (camPitch !=90 && camPitch !=-90)
      {
        cameraMovement(moveVel,180.0);
      }
      moveCameraUp(moveVel,180.0);
    }
    if (strafeLeft == true)
    {
      cameraMovement(moveVel,90.0);
    }
    if (strafeRight == true)
    {
      cameraMovement(moveVel, 270.0);
    }


  }

  glRotatef(-camPitch,1.0,0.0,0.0);
  glRotatef(-camYaw,0.0,1.0,0.0);
}

void Camera::cameraRender(int WinWidth, int WinHeight, SDL_Window *win)
{
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  camerControl(0.01,0.01,mouseInScreen,WinWidth/2,WinHeight/2,win);
  cameraUpdate();
  float pos[]={-1.0,1.0,-2.0-1.0};
  glLightfv(GL_LIGHT0,GL_POSITION,pos);

}


void Camera::cameraUpdate()
{
  glTranslatef(-camCoor.m_x,-camCoor.m_y,-camCoor.m_z);
//  glLoadIdentity();
//  gluLookAt(camEye.m_x, camEye.m_y, camEye.m_z,
//            camCentre.m_x, camCentre.m_y, camCentre.m_z,
//            camUp.m_x, camUp.m_y, camUp.m_z);
//  cameraStrafe();

}
