#include <stdlib.h>
#include <iostream>
#include "header/camera.h"
#include <SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <vector>
#include <math.h>


#ifdef LINUX
  #include <GL/gl.h>
#endif
#ifdef DARWIN
  #include <OpenGL/gl.h>
#endif

void Camera::enableScene()
{

  //add two more lights for the spot light to give a better look to the edges of the torch

  // Light values and coordinates
  GLfloat  lightPos[] = { playerXpos, -1.0f, playerZpos , 1.0f };
  GLfloat  specular[] = { 1.0f, 1.0f, 1.0f, 1.0f};
  GLfloat  specref[] =  { 1.0f, 1.0f, 1.0f, 1.0f };
  GLfloat  ambientLight[] = { 0.5f, 0.5f, 0.5f, 1.0f};
  GLfloat  ambientLight2[] = { 0.3f, 0.3f, 0.3f, 1.0f};
  GLfloat  ambientLight3[] = { 0.1f, 0.1f, 0.1f, 1.0f};

    glEnable(GL_DEPTH_TEST);

    glShadeModel(GL_SMOOTH);
    glEnable(GL_COLOR_MATERIAL);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight2);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight3);

    //Centre of the spot light
    // The light is composed of just diffuse and specular components
    glLightfv(GL_LIGHT0,GL_DIFFUSE,ambientLight);
    glLightfv(GL_LIGHT0,GL_SPECULAR,specular);
    glLightfv(GL_LIGHT0,GL_POSITION,lightPos);

    // Specific spot effects
    // Cut off angle is 60 degrees
    glLightf(GL_LIGHT0,GL_SPOT_CUTOFF,2.0f);

    //middle spot light
    // The light is composed of just diffuse and specular components
    glEnable(GL_LIGHT1);
    glLightfv(GL_LIGHT1,GL_DIFFUSE,ambientLight2);
    glLightfv(GL_LIGHT1,GL_SPECULAR,specular);
    glLightfv(GL_LIGHT1,GL_POSITION,lightPos);

    // Specific spot effects
    // Cut off angle is 60 degrees
    glLightf(GL_LIGHT1,GL_SPOT_CUTOFF,4.0f);

    //outer light
    // The light is composed of just diffuse and specular components
    glEnable(GL_LIGHT2);
    glLightfv(GL_LIGHT2,GL_DIFFUSE,ambientLight3);
    glLightfv(GL_LIGHT2,GL_SPECULAR,specular);
    glLightfv(GL_LIGHT2,GL_POSITION,lightPos);

    // Specific spot effects
    // Cut off angle is 60 degrees
    glLightf(GL_LIGHT2,GL_SPOT_CUTOFF,6.0f);


    // All materials hereafter have full specular reflectivity
    // with a high shine
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,specref);
    glMateriali(GL_FRONT_AND_BACK, GL_SHININESS,120);

}

void Camera::CameraSet()
{

  glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRotatef(yRot,0.0,1.0,0.0);
  glTranslated(-playerXpos,0,-playerZpos);

}

void Camera::displayCamera()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  //glLoadIdentity();
  CameraSet();
  enableScene();


  if (yRot > 360)
  {
    yRot=0;
  }
  if (yRot < 0)
  {
    yRot = 360;
  }


}


void Camera::cameraStrafe(const std::vector<std::vector<int> > &m_matrix)
{
  if (strafeLeft == true)
  {
    float yRotRad;
    oldxPos = playerXpos;
    oldzPos = playerZpos;
    yRotRad = (yRot / 180 * M_PI);
    playerXpos -= float(cos(yRotRad)) * 0.2;
    playerZpos -= float(sin(yRotRad)) * 0.2;
    playerCollisions(m_matrix);

  }
  if (strafeRight == true)
  {
    float yRotRad;
    oldxPos = playerXpos;
    oldzPos = playerZpos;
    yRotRad = (yRot / 180 * M_PI);
    playerXpos += float(cos(yRotRad)) * 0.2;
    playerZpos += float(sin(yRotRad)) * 0.2;
    playerCollisions(m_matrix);
  }
  if (moveBackward == true)
  {
    float xRotRad,yRotRad;
    oldxPos = playerXpos;
    oldzPos = playerZpos;
    yRotRad = (yRot / 180 * M_PI);
    xRotRad = (xRot / 180 * M_PI);
    playerXpos -= float(sin(yRotRad)/5);
    playerZpos += float(cos(yRotRad)/5);
    playerCollisions(m_matrix);
  }
  if (moveForward == true)
  {
    float xRotRad,yRotRad;
    oldxPos = playerXpos;
    oldzPos = playerZpos;
    yRotRad = (yRot / 180 * M_PI);
    xRotRad = (xRot / 180 * M_PI);
    playerXpos += float(sin(yRotRad)/5);
    playerZpos -= float(cos(yRotRad)/5);
    playerCollisions(m_matrix);

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
//  std::cout<<playerXpos<<"  "<<playerZpos<<"\n";


}


void Camera::setPlayer(const std::vector<std::vector<int> > &m_matrix)
{
  for(int i = 0; i < (int)m_matrix.size(); ++i)
  {
    for(int j = 0; j < (int)m_matrix[0].size(); ++j)
    {
      if(m_matrix[i][j] == 3)
      {
        float spawnCentreX = (i * CUBESIZE);
        float spawnCentreZ = (((int)m_matrix[0].size() * CUBESIZE) - (j * CUBESIZE));
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
  cameraStrafe(matrix);
  displayCamera();
//  playerCollisions(matrix);
  if (playerSet == false)
  {
    setPlayer(matrix);
    playerSet = true;
  }



}


void Camera::playerCollisions(const std::vector<std::vector<int> > &m_matrix)
{
  for(int i = 0; i < (int)m_matrix.size(); ++i)
  {
    for(int j = 0; j < (int)m_matrix[0].size(); ++j)
    {
      if(m_matrix[i][j] == 1 || m_matrix[i][j] == 9 || m_matrix[i][j] == 10 || m_matrix[i][j] == 15 || m_matrix[i][j] == 10 || m_matrix[i][j] == 9)
      {
                  float cubeCentreX = (i * 4);
                  float cubeCentreZ = (((int)m_matrix[0].size() * 4) - (j * 4));
                  float cubeMinX, cubeMaxX, cubeMinZ, cubeMaxZ, distX;
                  cubeMinX = cubeCentreX - 2.8f;
                  cubeMaxX = cubeCentreX + 2.8f;
                  cubeMinZ = cubeCentreZ - 2.8f;
                  cubeMaxZ = cubeCentreZ + 2.8f;
                  distX = playerXpos - cubeCentreX;
                  static int distZ = playerZpos - cubeCentreZ;
        if (playerXpos > cubeMinX && playerXpos < cubeMaxX && playerZpos > cubeMinZ && playerZpos < cubeMaxZ)
        {

          std::cout << playerXpos << ", 0 ," << playerZpos << std::endl;

            if (distX >= CUBESIZE/2 && distX <= -CUBESIZE/2)
            {
              playerXpos  = oldxPos;
              std::cout<<"Xhit \n";
            }
            else{
              playerZpos  = oldzPos;
              std::cout<<"Xhit \n";
            }
            if (distZ >= CUBESIZE/2 && distZ <= -CUBESIZE/2)
            {
              playerZpos = oldzPos;
               std::cout<<"Zhit \n";
            }
            else{
              playerXpos  = oldxPos;
              std::cout<<"Xhit \n";
            }
        }
      }

      ///Collision setting for the exterior fencing around the playable area
      /// matrix vales 7 and 8 are the values of the fence depending on their rotation value
      if (m_matrix[i][j] == 7 || m_matrix[i][j] == 8)
      {
        //this is the centre of the current collision grid position for the x value
        float cubeCentreX = (i * CUBESIZE);
        //this is the centre of the current collision grid position for the z value
        float cubeCentreZ = (((int)m_matrix[0].size() * CUBESIZE) - (j * CUBESIZE));
        //Here are a set of local values that are needed to work about the AABB around the grid position to define the box
        float cubeMinX, cubeMaxX, cubeMinZ, cubeMaxZ;
        //this values are used to create the bounding box
        cubeMinX = cubeCentreX - 2.8f;
        cubeMaxX = cubeCentreX + 2.8f;
        cubeMinZ = cubeCentreZ - 2.8f;
        cubeMaxZ = cubeCentreZ + 2.8f;
        //this is the AABB formula to detect if the player position has collided with and of the fences within the scene
        if (playerXpos > cubeMinX && playerXpos < cubeMaxX && playerZpos > cubeMinZ && playerZpos < cubeMaxZ)
        {
          //if there is a collision, this is tested to see what value has to be freezed so that the player is unable to pass through the fence
          if (m_matrix[i][j] == 7)
          {
            //this holds the player from being able to move through the fence but not allowing the X value to change in the direction of the collison box
            playerXpos = oldxPos;
          }
          //if the collision wasnt with the fence type 7 then it must be type 8
          else
          {
            //this holds the player from being able to move through the fence but not allowing the Z value to change in the direction of the collison box
            playerZpos = oldzPos;
          }
        }
      }
    }
  }
}


