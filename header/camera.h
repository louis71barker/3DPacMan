#ifndef CAMERA_H__
#define CAMERA_H__
#include <math.h>
#include <SDL.h>

#ifndef M_PI
#define M_PI 3.1215926535
#endif

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

    camYaw = 0.0f;
    camPitch = 0.0f;
  }
  void setCamera();
  void cameraUpdate();
  void cameraMouse();
  void cameraStrafe();
  void cameraMovement(float, float);
  void lockCamera();
  void moveCameraUp(float,float);
  void camerControl(float, float, bool, float WinWidth, float WinHeight, SDL_Window *win);
  void cameraRender(int WinWidth, int WinHeight, SDL_Window*win);
  bool strafeLeft,strafeRight,moveForward,moveBackward,mouseInScreen;
  Vec3 camEye;
  Vec3 camCentre;
  Vec3 camUp;
  Vec3 camCoor;
  float camYaw,camPitch;



private:
};







#endif
