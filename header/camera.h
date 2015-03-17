#ifndef CAMERA_H__
#define CAMERA_H__
#include <math.h>
#include <SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#ifndef M_PI
#define M_PI 3.141592654
#endif




typedef struct {
  GLfloat x;
  GLfloat y;
  GLfloat z;
}Vector3;

Vector3 NormalizeVec3(Vector3 Vector);

class Vec3
{
public:
  Vec3(float _x=0.0f,float _y=0.0f, float _z=0.0f) :
    m_x(_x), m_y(_y), m_z(_z){}

  struct
  {
    float m_x;
    float m_y;
    float m_z;
  };

};



class Camera
{
public:


  Camera() :
    camEye(0, 0, 2),
    camCentre(0, 0, 0),
    camUp(0, 1, 0),
    camCoor(0, 0, 0)
  {
    strafeLeft = false;
    strafeRight = false;
    moveForward = false;
    moveBackward = false;
    mouseInScreen = false;

    angle = 0.0f;
    playerXpos = 0.0f;
    playerYpos = 0.0f;
    playerZpos = 0.0f;
    lastPlayerPosx = 0.0f;
    lastPlayerPosy = 0.0f;
    xRot = 0.0f;
    yRot = 0.0f;

  }
  void cameraUpdate();
  void cameraStrafe();
  void enableScene();
  void displayCamera();
  void CameraSet();
  void mouseMovementCapture(int x, int y);
  void WidowSetting();


  bool strafeLeft,strafeRight,moveForward,moveBackward,mouseInScreen;
  Vec3 camEye;
  Vec3 camCentre;
  Vec3 camUp;
  Vec3 camCoor;

  float angle,playerXpos,playerYpos,playerZpos,lastPlayerPosx,lastPlayerPosy,xRot,yRot;



private:
};







#endif
