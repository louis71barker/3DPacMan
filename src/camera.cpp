#include <stdlib.h>
#include <iostream>
#include "header/camera.h"
#include <SDL.h>
//#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <vector>

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

  // Light values and coordinates
  GLfloat  lightPos[] = { playerXpos, -1.0f, playerZpos , 1.0f };
  GLfloat  specular[] = { 1.0f, 1.0f, 1.0f, 1.0f};
  GLfloat  specref[] =  { 1.0f, 1.0f, 1.0f, 1.0f };
  GLfloat  ambientLight[] = { 0.5f, 0.5f, 0.5f, 1.0f};
//  GLfloat  spotDir[] = { 1, yRot, -1};

//  std::cout<<xRot<<"      "<<yRot<<"\n";

    glEnable(GL_DEPTH_TEST);
    //glFrontFace(GL_CW);       // Counterclockwise polygons face out
    glEnable(GL_CULL_FACE);    // Do not try to display the back sides

    glShadeModel(GL_SMOOTH);
    glEnable(GL_COLOR_MATERIAL);


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
    glLightf(GL_LIGHT0,GL_SPOT_CUTOFF,5.0f);

    // Fairly shiny spot
//    glLightf(GL_LIGHT0,GL_SPOT_EXPONENT,1000.0f);

    // Enable this light in particular
//    glEnable(GL_LIGHT0);

    // Enable color tracking
//    glEnable(GL_COLOR_MATERIAL);

    // Set Material properties to follow glColor values
//    glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);

    // All materials hereafter have full specular reflectivity
    // with a high shine
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,specref);
    glMateriali(GL_FRONT_AND_BACK, GL_SHININESS,128);

    glPushMatrix();

//            glRotatef(-yRot, 0.0f, 1.0f, 0.0f);
            //glRotatef(0, 0.0f, 1.0f, 0.0f);
//            spotDir[0] = asinf(-yRot / 180 * M_PI);
//            spotDir[2] = acosf(-yRot / 180 * M_PI);

            // Specify new position and direction in rotated coords.
//            glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
//            glLightfv(GL_LIGHT0,GL_SPOT_DIRECTION,spotDir);

//             Draw a red cone to enclose the light source
//            glRGB(255,0,0);

            // Translate origin to move the cone out to where the light
            // is positioned.
            //glTranslatef(lightPos[0],0,lightPos[2]);
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

  glPushMatrix();
  glPointSize(10);
  glColor3f(1,0,0);
  glBegin(GL_POINTS);
    glColor3f(1,0,0);
    glVertex3f(playerXpos + 5, -1.0f, playerZpos );
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);
//    std::cout<<yRot<<"\n";
    glRotatef(0, 0.0f, 1.0f, 0.0f);
  glEnd();
  glPopMatrix();


//  std::cout<<xRot<<"\n";


}

void Camera::CameraSet()
{
//  float xRVal = 0.0f, yRVal = 0.0f, playerPosx = 0.0f, playerPosy = 0.0f, height = 0.0f, rotVal = 0.0f;
//  if (firstPersonCam == true)
//  {
//    xRVal = 0.0f;
//    yRVal = 1.0f;
//    playerPosx = -playerXpos;
//    playerPosy = -playerZpos;
//    height = -0.0f;
//    rotVal = yRot;

//    rotationNum = 0;
//  }
//  if (thirdPersonCam == true && rotationNum <= 0.5)
//  {
//    xRVal = 1.0f;
//    yRVal = 0.0f;
//    playerPosx = 0;
//    playerPosy = 0;
//    height = 20.0f;
//    rotVal = 45.0f;

//    rotationNum++;


//  }
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
//  glRotatef(rotVal,xRVal,yRVal,0.0);
//  glTranslated(playerPosx,height,playerPosy);

  glRotatef(yRot,0.0,1.0,0.0);
  glTranslated(-playerXpos,0,-playerZpos);
}

void Camera::displayCamera()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  //glLoadIdentity();
  CameraSet();
  enableScene();
  angle++;
  if (yRot > 360)
  {
    yRot=0;
  }
  if (yRot < 0)
  {
    yRot = 360;
  }


}


void Camera::cameraStrafe()
{
  if (strafeLeft == true  && playerMoveing == true)
  {
    float yRotRad;
    oldxPos = playerXpos;
    oldzPos = playerZpos;
    yRotRad = (yRot / 180 * M_PI);
    playerXpos -= float(cos(yRotRad)) * 0.2;
    playerZpos -= float(sin(yRotRad)) * 0.2;

  }
  if (strafeRight == true  && playerMoveing == true)
  {
    float yRotRad;
    oldxPos = playerXpos;
    oldzPos = playerZpos;
    yRotRad = (yRot / 180 * M_PI);
    playerXpos += float(cos(yRotRad)) * 0.2;
    playerZpos += float(sin(yRotRad)) * 0.2;
  }
  if (moveBackward == true && playerMoveing == true)
  {
    float xRotRad,yRotRad;
    oldxPos = playerXpos;
    oldzPos = playerZpos;
    yRotRad = (yRot / 180 * M_PI);
    xRotRad = (xRot / 180 * M_PI);
    playerXpos -= float(sin(yRotRad)/5);
    playerZpos += float(cos(yRotRad)/5);
  }
  if (moveForward == true && playerMoveing == true)
  {
    float xRotRad,yRotRad;
    oldxPos = playerXpos;
    oldzPos = playerZpos;
    yRotRad = (yRot / 180 * M_PI);
    xRotRad = (xRot / 180 * M_PI);
    playerXpos += float(sin(yRotRad)/5);
    playerZpos -= float(cos(yRotRad)/5);

  }



}


void Camera::mouseMovementCapture(int x, int y)
{
  diffx = x-lastPlayerPosx;
  diffy = y-lastPlayerPosy;
  lastPlayerPosx = x;
  lastPlayerPosy = y;
  xRot += (float) diffy;
  yRot += (float) diffx;
  std::cout<<playerXpos<<"  "<<playerZpos<<"\n";


}


void Camera::setPlayer(std::vector<std::vector<int> > _matrix)
{
  for(int i = 0; i < (int)_matrix.size(); ++i)
  {
    for(int j = 0; j < (int)_matrix[0].size(); ++j)
    {
      if(_matrix[i][j] == 3)
      {
        float spawnCentreX = (i * 4);
        float spawnCentreZ = (((int)_matrix[0].size() * 4) - (j * 4));
          playerXpos = spawnCentreX;
          playerZpos = spawnCentreZ;
        std::cout<<" player Spawn "<<"\n";
      }
    }
  }
}

//this is what is called int the main
void Camera::cameraUpdate(std::vector<std::vector<int> > matrix,int x, int y)
{
  mouseMovementCapture(x,y);
  cameraStrafe();
  displayCamera();
  playerCollisions(matrix);
  if (playerSet == false)
  {
    setPlayer(matrix);
    playerSet = true;
  }



}

void Camera::thirdPerson()
{
  glRotatef(90,1.0,0.0,0.0);
  glTranslated(0,20,0);
}

void Camera::playerCollisions(std::vector<std::vector<int> > matrix)
{
  for(int i = 0; i < (int)matrix.size(); ++i)
  {
    for(int j = 0; j < (int)matrix[0].size(); ++j)
    {
      if(matrix[i][j] == 1)
      {
//                  glTranslatef((_x)*4, -1, ((int)_matrix[0].size() * 4) - (_y)*4);
//                  float cubeCentreX = (-30 + (i+0.5)*4);
//                  float cubeCentreZ = (30 - (j+0.5)*4);
                  float cubeCentreX = (i * 4);
                  float cubeCentreZ = (((int)matrix[0].size() * 4) - (j * 4));
                  float cubeMinX, cubeMaxX, cubeMinZ, cubeMaxZ, normalx, normalz;
                  cubeMinX = cubeCentreX - 2.8f;
                  cubeMaxX = cubeCentreX + 2.8f;
                  cubeMinZ = cubeCentreZ - 2.8f;
                  cubeMaxZ = cubeCentreZ + 2.8f;
        if (playerXpos > cubeMinX && playerXpos < cubeMaxX && playerZpos > cubeMinZ && playerZpos < cubeMaxZ)
        {
          std::cout<<"boom boom bang bang \n";
//          detectingNormals(cubeCentreX, cubeCentreZ);
          if (playerXpos > playerZpos)
          {
            if(playerXpos - (cubeCentreX + (CUBESIZE /2 )) < 0)
            {
              normalx = 1.0f;
              normalz = 0.0f;
              playerZpos = oldzPos-0.5;
              std::cout<<"Front Side \n";
            }
            else
            {
              normalx = -1.0f;
              normalz = 0.0f;
              playerZpos = oldzPos+0.5;
              std::cout<<"back Side \n";
            }
          }
          else
            {
              if (playerZpos - (cubeCentreZ + (CUBESIZE /2 )) < 0.0f)
              {
                normalx = 0.0f;
                normalz = 1.0f;
                playerZpos = oldzPos-0.5;
                std::cout<<"right Side \n";
              }
              else
              {
                normalx = 0.0f;
                normalz = -1.0f;
//                if (playerZpos > 0)
                playerZpos = oldzPos+0.5;
                std::cout<<"left Side \n";
              }
            }


        }
        else
        {
          normalx = 0.0f;
          normalz = 0.0f;
        }
//        std::cout<< playerZpos - (cubeCentreZ + (CUBESIZE /2 )) << "\n";

        }
      }
    }
  }
//}


void Camera::collisionDistance(float cubeX, float cubeZ)
{
  if (diffx > 0.0f)
  {
    xInvEntry =  cubeX - (playerXpos + 0.5);
    xInvExit = (cubeX + (CUBESIZE /2)) - cubeX;
  }
  else
  {
    xInvEntry =  (cubeX + (CUBESIZE/2)) - playerXpos;
    xInvExit = cubeX - (playerXpos + 0.5);
  }
  if (diffy > 0.0f)
  {
    yInvEntry = cubeZ - (playerZpos + 0.5);
    yInvExit = (cubeZ - (CUBESIZE/2) - playerZpos);
  }
  else
  {
    yInvEntry = (cubeZ + (CUBESIZE/2) ) - 0.5;
    yInvExit = cubeZ - (playerZpos + 0.5);
  }

  //finding the time of each collision and time of leaving the collision

  if (diffx == 0.0f)
  {
    xEntry = -std::numeric_limits<float>::infinity();
    xExit = std::numeric_limits<float>::infinity();
  }
  else
  {
    xEntry = xInvEntry / diffx;
    xExit = xInvExit / diffx;
  }
  if (diffy == 0.0f)
  {
    yEntry = -std::numeric_limits<float>::infinity();
    yExit = std::numeric_limits<float>::infinity();
  }
  else
  {
    yEntry = yInvEntry / diffy;
    yExit = yInvExit / diffy;
  }

  //finding the earliest and latest time of collisions
  entryTime = std::max(xEntry,yEntry);
  exitTime = std::min(xExit,yExit);
}
