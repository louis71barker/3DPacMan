#include <stdlib.h>
#include <iostream>
#include "header/camera.h"
#include <SDL.h>
//#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
#include <math.h>



#ifdef LINUX
  #include <GL/gl.h>
#endif
#ifdef DARWIN
  #include <OpenGL/gl.h>
#endif

void Camera::enableScene()
{
  glEnable (GL_DEPTH_TEST);//enables depth testing
  glEnable(GL_LIGHTING);//enables the lights
  glEnable(GL_LIGHT0);//enables light 0
  glShadeModel(GL_SMOOTH);//sets the shader to smooth
}

void Camera::CameraSet()
{
  glRotatef(yRot,0.0,1.0,0.0);
  glTranslated(-playerXpos,0,-playerZpos);
}

void Camera::displayCamera()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  CameraSet();
  glutSwapBuffers();
  angle++;
}


void Camera::cameraStrafe()
{
  if (strafeLeft == true)
  {
    float yRotRad;
    yRotRad = (playerYpos / 180 * M_PI);
    playerXpos -= float(cos(yRotRad)) * 0.2;
    playerXpos -= float(sin(yRotRad)) * 0.2;

  }
  if (strafeRight == true)
  {
    float yRotRad;
    yRotRad = (playerYpos / 180 * M_PI);
    playerXpos += float(cos(yRotRad)) * 0.2;
    playerZpos += float(sin(yRotRad)) * 0.2;
  }
  if (moveBackward == true)
  {
    float xRotRad,yRotRad;
    yRotRad = (playerYpos / 180 * M_PI);
    xRotRad = (playerXpos / 180 * M_PI);
    playerXpos -= float(sin(yRotRad));
    playerZpos += float(cos(yRotRad));
  }
  if (moveForward == true)
  {
    float xRotRad,yRotRad;
    yRotRad = (playerYpos / 180 * M_PI);
    xRotRad = (playerXpos / 180 * M_PI);
    playerXpos += float(sin(yRotRad));
    playerZpos -= float(cos(yRotRad));

  }

}


void Camera::mouseMovementCapture(int x, int y)
{
  int diffx = x-lastPlayerPosx;
  int diffy = y-lastPlayerPosy;
  lastPlayerPosx = x;
  lastPlayerPosy = y;
  xRot += (float) diffy;
  yRot += (float) diffx;
}



void Camera::cameraUpdate()
{


}

void Camera::WidowSetting()
{


}
