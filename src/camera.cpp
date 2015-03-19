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

////   Somewhere in the initialization part of your program…
//  glEnable(GL_LIGHTING);
//  glEnable(GL_LIGHT0);

//  // Create light components
//  GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
//  GLfloat diffuseLight[] = { 0.8f, 0.8f, 0.8, 1.0f };
//  GLfloat specularLight[] = { 0.5f, 0.5f, 0.5f, 1.0f };
//  GLfloat position[] = { -playerXpos, 5.0f, -playerZpos, 0.5f };
//  GLfloat spot_direction[] = { 1.0, 0.0, 1.0, 1.0f};
//  std::cout<<playerXpos<<"      "<<playerZpos<<"\n";

//  // Assign created components to GL_LIGHT0
//  glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
//  glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
//  glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
//  glLightfv(GL_LIGHT0, GL_POSITION, position);
//  glLightfv(GL_LIGHT0,GL_SPOT_DIRECTION, spot_direction);

//  glEnable (GL_DEPTH_TEST);//enables depth testing
//  glEnable(GL_LIGHTING);//enables the lights
//  glEnable(GL_LIGHT0);//enables light0
//  glShadeModel(GL_SMOOTH);//sets the shader to smooth

//    glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 45.0);
//    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
//    glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 2.0);

  // Light values and coordinates
  GLfloat  lightPos[] = { playerXpos, 0.0f, playerZpos + 75.0f, 1.0f };
  GLfloat  specular[] = { 1.0f, 1.0f, 1.0f, 1.0f};
  GLfloat  specref[] =  { 1.0f, 1.0f, 1.0f, 1.0f };
  GLfloat  ambientLight[] = { 0.5f, 0.5f, 0.5f, 1.0f};
  GLfloat  spotDir[] = { -0, -0, -1.0f };

  // This function does any needed initialization on the rendering
  // context.  Here it sets up and initializes the lighting for
  // the scene.


    glEnable(GL_DEPTH_TEST);   // Hidden surface removal
    glFrontFace(GL_CCW);       // Counterclockwise polygons face out
    glEnable(GL_CULL_FACE);    // Do not try to display the back sides

    // Enable lighting
    glEnable(GL_LIGHTING);

    // Set up and enable light 0
    // Supply a slight ambient light so the objects can be seen
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);

    // The light is composed of just diffuse and specular components
    glLightfv(GL_LIGHT0,GL_DIFFUSE,ambientLight);
    glLightfv(GL_LIGHT0,GL_SPECULAR,specular);
    glLightfv(GL_LIGHT0,GL_POSITION,lightPos);

    // Specific spot effects
    // Cut off angle is 60 degrees
    glLightf(GL_LIGHT0,GL_SPOT_CUTOFF,60.0f);

    // Fairly shiny spot
    glLightf(GL_LIGHT0,GL_SPOT_EXPONENT,100.0f);

    // Enable this light in particular
    glEnable(GL_LIGHT0);

    // Enable color tracking
    glEnable(GL_COLOR_MATERIAL);

    // Set Material properties to follow glColor values
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    // All materials hereafter have full specular reflectivity
    // with a high shine
    glMaterialfv(GL_FRONT, GL_SPECULAR,specref);
    glMateriali(GL_FRONT, GL_SHININESS,128);

    glPushMatrix();

            glRotatef(xRot, 1.0f, 0.0f, 0.0f);
            glRotatef(-yRot, 0.0f, 1.0f, 0.0f);

            // Specify new position and direction in rotated coords.
            glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
            glLightfv(GL_LIGHT0,GL_SPOT_DIRECTION,spotDir);

            // Draw a red cone to enclose the light source
//            glRGB(255,0,0);

            // Translate origin to move the cone out to where the light
            // is positioned.
            glTranslatef(lightPos[0],lightPos[1],lightPos[2]);
//            auxSolidCone(4.0f,6.0f);

            // Draw a smaller displaced sphere to denote the light bulb
            // Save the lighting state variables
            glPushAttrib(GL_LIGHTING_BIT);

                    // Turn off lighting and specify a bright yellow sphere
                    glDisable(GL_LIGHTING);
//                    glRGB(255,255,0);
//                    auxSolidSphere(3.0f);

            // Restore lighting state variables
            glPopAttrib();
        glPopMatrix();


  std::cout<<xRot<<"\n";


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

void Camera::spotLight()
{

}
