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

void Camera::enableSpotLight()
{

  //add two more lights for the spot light to give a better look to the edges of the torch

  // Light values and coordinates
  GLfloat  m_lightPos[] = { m_playerXpos, -1.0f, m_playerZpos , 1.0f };
  GLfloat  m_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f};
  GLfloat  m_specref[] =  { 1.0f, 1.0f, 1.0f, 1.0f };
  GLfloat  m_ambientLight[] = { 0.5f, 0.5f, 0.5f, 1.0f};
  GLfloat  m_ambientLight2[] = { 0.3f, 0.3f, 0.3f, 1.0f};
  GLfloat  m_ambientLight3[] = { 0.1f, 0.1f, 0.1f, 1.0f};

    glEnable(GL_DEPTH_TEST);

    glShadeModel(GL_SMOOTH);
    glEnable(GL_COLOR_MATERIAL);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, m_ambientLight);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, m_ambientLight2);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, m_ambientLight3);

    //Centre of the spot light
    // The light is composed of just diffuse and specular components
    glLightfv(GL_LIGHT0,GL_DIFFUSE,m_ambientLight);
    glLightfv(GL_LIGHT0,GL_SPECULAR,m_specular);
    glLightfv(GL_LIGHT0,GL_POSITION,m_lightPos);
    glLightf(GL_LIGHT0,GL_SPOT_CUTOFF,2.0f);

    //middle spot light
    // The light is composed of just diffuse and specular components
    glEnable(GL_LIGHT1);
    glLightfv(GL_LIGHT1,GL_DIFFUSE,m_ambientLight2);
    glLightfv(GL_LIGHT1,GL_SPECULAR,m_specular);
    glLightfv(GL_LIGHT1,GL_POSITION,m_lightPos);
    glLightf(GL_LIGHT1,GL_SPOT_CUTOFF,4.0f);

    //outer light
    // The light is composed of just diffuse and specular components
    glEnable(GL_LIGHT2);
    glLightfv(GL_LIGHT2,GL_DIFFUSE,m_ambientLight3);
    glLightfv(GL_LIGHT2,GL_SPECULAR,m_specular);
    glLightfv(GL_LIGHT2,GL_POSITION,m_lightPos);
    glLightf(GL_LIGHT2,GL_SPOT_CUTOFF,6.0f);


    // sets specular reflectivity to full to give shiny effect
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,m_specref);
    glMateriali(GL_FRONT_AND_BACK, GL_SHININESS,120);

}

void Camera::CameraSet()
{

  glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //rotate the camera around the y axis
    glRotatef(m_yRot,0.0,1.0,0.0);
  //move the player using these values
  glTranslated(-m_playerXpos,0,-m_playerZpos);

}

void Camera::displayCamera()
{
  //clear the buffers
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  //set the camera to it pos
  CameraSet();
  //turn on the spot light
  enableSpotLight();

  //tests to see if rotation is at max of 360 or min of 0 and reverts them to their opposites if they are
  if (m_yRot > 360)
  {
    m_yRot=0;
  }
  if (m_yRot < 0)
  {
    m_yRot = 360;
  }


}


void Camera::cameraStrafe(const std::vector<std::vector<int> > &m_matrix)
{

  //this the 'a' key is pressed
  if (m_strafeLeft == true)
  {
    float _yRotRad;
    //old player position
    m_oldxPos = m_playerXpos;
    m_oldzPos = m_playerZpos;
    //calculate rotation value
    _yRotRad = (m_yRot / 180 * M_PI);
    m_playerXpos -= float(cos(_yRotRad)) * 0.2;
    m_playerZpos -= float(sin(_yRotRad)) * 0.2;
    //check for player collisions
    playerCollisions(m_matrix);
  }

  //if the 'd' key is pressed
  if (m_strafeRight == true)
  {
    float yRotRad;
    //old player pos
    m_oldxPos = m_playerXpos;
    m_oldzPos = m_playerZpos;
    //calculate rotation value
    yRotRad = (m_yRot / 180 * M_PI);
    m_playerXpos += float(cos(yRotRad)) * 0.2;
    m_playerZpos += float(sin(yRotRad)) * 0.2;
    //check for player collisions
    playerCollisions(m_matrix);
  }

  //if the 's' key is pressed
  if (m_moveBackward == true)
  {
    float  _yRotRad;
    //old player pos
    m_oldxPos = m_playerXpos;
    m_oldzPos = m_playerZpos;
    //calculate rotation value
    _yRotRad = (m_yRot / 180 * M_PI);
    m_playerXpos -= float(sin(_yRotRad)/5);
    m_playerZpos += float(cos(_yRotRad)/5);
    //check for player collisions
    playerCollisions(m_matrix);
  }

  //if the 'w' key is pressed
  if (m_moveForward == true)
  {
    float _yRotRad;
    m_oldxPos = m_playerXpos;
    m_oldzPos = m_playerZpos;
    //calculate rotation value
    _yRotRad = (m_yRot / 180 * M_PI);
    m_playerXpos += float(sin(_yRotRad)/5);
    m_playerZpos -= float(cos(_yRotRad)/5);
    //check for player collisions
    playerCollisions(m_matrix);
  }
}


void Camera::mouseMovementCapture(const int _x, const int _y)
{
  //calculates the rotation value for the camera
  m_diffx = _x-m_lastPlayerPosx;
  m_diffy = _y-m_lastPlayerPosy;
  m_lastPlayerPosx = _x;
  m_lastPlayerPosy = _y;
  m_xRot += (float)m_diffy;
  m_yRot += (float)m_diffx;
}


void Camera::setPlayer(const std::vector<std::vector<int> > &m_matrix)
{
  for(int i = 0; i < (int)m_matrix.size(); ++i)
  {
    for(int j = 0; j < (int)m_matrix[0].size(); ++j)
    {
      //tests to find players spawn location
      if(m_matrix[i][j] == 3)
      {
        //defines the position that the player spawn location is at
        float _spawnCentreX = (i * CUBESIZE);
        float _spawnCentreZ = (((int)m_matrix[0].size() * CUBESIZE) - (j * CUBESIZE));
        //moves the player camera to the spawn
          m_playerXpos = _spawnCentreX;
          m_playerZpos = _spawnCentreZ;
      }
    }
  }
}

//this is what is called int the main
void Camera::cameraUpdate(std::vector<std::vector<int> > m_matrix, int m_x, int m_y)
{
  //updates the camera rotation movement
  mouseMovementCapture(m_x,m_y);
  //updates the key moveing movement
  cameraStrafe(m_matrix);
  displayCamera();
  //tests to make sure that the player has been spawned
  if (m_playerSet == false)
  {
    setPlayer(m_matrix);
    m_playerSet = true;
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
        //find the centre of the collised grig cube to use simple AABB detection method
        float _cubeCentreX = (i * 4);
        float _cubeCentreZ = (((int)m_matrix[0].size() * 4) - (j * 4));
        float _cubeMinX, _cubeMaxX, _cubeMinZ, _cubeMaxZ, _distX;
        _cubeMinX = _cubeCentreX - 2.8f;
        _cubeMaxX = _cubeCentreX + 2.8f;
        _cubeMinZ = _cubeCentreZ - 2.8f;
        _cubeMaxZ = _cubeCentreZ + 2.8f;
        //find the distance away from the centre
        _distX = m_playerXpos - _cubeCentreX;
        static float _distZ = m_playerZpos - _cubeCentreZ;
        //AABB collision box
        if (m_playerXpos > _cubeMinX && m_playerXpos < _cubeMaxX && m_playerZpos > _cubeMinZ && m_playerZpos < _cubeMaxZ)
        {

          //collision response
            if (_distX >= CUBESIZE/2 && _distX <= -CUBESIZE/2)
            {
              m_playerXpos  = m_oldxPos;
            }
            else{
              m_playerZpos  = m_oldzPos;
            }
            if (_distZ >= CUBESIZE/2 && _distZ <= -CUBESIZE/2)
            {
              m_playerZpos = m_oldzPos;
            }
            else{
              m_playerXpos  = m_oldxPos;
            }
        }
      }

      //Collision setting for the exterior fencing around the playable area
      // matrix vales 7 and 8 are the values of the fence depending on their rotation value
      if (m_matrix[i][j] == 7 || m_matrix[i][j] == 8)
      {
        //this is the centre of the current collision grid position for the x value
        float _cubeCentreX = (i * CUBESIZE);
        //this is the centre of the current collision grid position for the z value
        float _cubeCentreZ = (((int)m_matrix[0].size() * CUBESIZE) - (j * CUBESIZE));
        //Here are a set of local values that are needed to work about the AABB around the grid position to define the box
        float _cubeMinX, _cubeMaxX, _cubeMinZ, _cubeMaxZ;
        //this values are used to create the bounding box
        _cubeMinX = _cubeCentreX - 2.8f;
        _cubeMaxX = _cubeCentreX + 2.8f;
        _cubeMinZ = _cubeCentreZ - 2.8f;
        _cubeMaxZ = _cubeCentreZ + 2.8f;
        //this is the AABB formula to detect if the player position has collided with and of the fences within the scene
        if (m_playerXpos > _cubeMinX && m_playerXpos < _cubeMaxX && m_playerZpos > _cubeMinZ && m_playerZpos < _cubeMaxZ)
        {
          //if there is a collision, this is tested to see what value has to be freezed so that the player is unable to pass through the fence
          if (m_matrix[i][j] == 7)
          {
            //this holds the player from being able to move through the fence but not allowing the X value to change in the direction of the collison box
            m_playerXpos = m_oldxPos;
          }
          //if the collision wasnt with the fence type 7 then it must be type 8
          else
          {
            //this holds the player from being able to move through the fence but not allowing the Z value to change in the direction of the collison box
            m_playerZpos = m_oldzPos;
          }
        }
      }
    }
  }
}


