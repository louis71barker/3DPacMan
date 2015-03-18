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

  // Somewhere in the initialization part of your program…
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);

  // Create light components
  GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
  GLfloat diffuseLight[] = { 0.8f, 0.8f, 0.8, 1.0f };
  GLfloat specularLight[] = { 0.5f, 0.5f, 0.5f, 1.0f };
  GLfloat position[] = { -1.5f, 15.0f, -4.0f, 0.5f };

  // Assign created components to GL_LIGHT0
  glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
  glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
  glLightfv(GL_LIGHT0, GL_POSITION, position);
  glEnable (GL_DEPTH_TEST);//enables depth testing
  glEnable(GL_LIGHTING);//enables the lights
  glEnable(GL_LIGHT0);//enables light0
  glShadeModel(GL_SMOOTH);//sets the shader to smooth
}

void Camera::CameraSet()
{
  float xRVal = 0.0f, yRVal = 0.0f, playerPosx = 0.0f, playerPosy = 0.0f, height = 0.0f, rotVal = 0.0f;
  if (firstPersonCam == true)
  {
    xRVal = 0.0f;
    yRVal = 1.0f;
    playerPosx = -playerXpos;
    playerPosy = -playerZpos;
    height = -0.0f;
    rotVal = yRot;

    rotationNum = 0;
  }
  if (thirdPersonCam == true && rotationNum <= 0.5)
  {
    xRVal = 1.0f;
    yRVal = 0.0f;
    playerPosx = 0;
    playerPosy = 0;
    height = 20.0f;
    rotVal = 45.0f;

    rotationNum++;


  }
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glRotatef(rotVal,xRVal,yRVal,0.0);
  glTranslated(playerPosx,height,playerPosy);

//  glRotatef(yRot,0.0,1.0,0.0);
//  glTranslated(-playerXpos,0,-playerZpos);
}

void Camera::displayCamera()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  //glLoadIdentity();
  CameraSet();
  enableScene();
  angle++;

}


void Camera::cameraStrafe()
{
  if (strafeLeft == true)
  {
    float yRotRad;
    yRotRad = (yRot / 180 * M_PI);
    playerXpos -= float(cos(yRotRad)) * 0.2;
    playerZpos -= float(sin(yRotRad)) * 0.2;

  }
  if (strafeRight == true)
  {
    float yRotRad;
    yRotRad = (yRot / 180 * M_PI);
    playerXpos += float(cos(yRotRad)) * 0.2;
    playerZpos += float(sin(yRotRad)) * 0.2;
  }
  if (moveBackward == true)
  {
    float xRotRad,yRotRad;
    yRotRad = (yRot / 180 * M_PI);
    xRotRad = (xRot / 180 * M_PI);
    playerXpos -= float(sin(yRotRad)/2);
    playerZpos += float(cos(yRotRad)/2);
  }
  if (moveForward == true)
  {
    float xRotRad,yRotRad;
    yRotRad = (yRot / 180 * M_PI);
    xRotRad = (xRot / 180 * M_PI);
    playerXpos += float(sin(yRotRad)/2);
    playerZpos -= float(cos(yRotRad)/2);

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


//this is what is called int the main
void Camera::cameraUpdate(int x, int y)
{
  mouseMovementCapture(x,y);
  cameraStrafe();
  displayCamera();


}

void Camera::thirdPerson()
{
  glRotatef(90,1.0,0.0,0.0);
  glTranslated(0,20,0);
}
