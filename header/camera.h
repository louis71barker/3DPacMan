#ifndef CAMERA_H__
#define CAMERA_H__
#include <math.h>
#include "header/scene.h"


#ifndef M_PI
#define M_PI 3.141592654
#endif








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
    firstPersonCam = true;
    thirdPersonCam = false;

    angle = 0.0f;
    playerXpos = 0.0f;
    playerYpos = 0.0f;
    playerZpos = 0.0f;
    lastPlayerPosx = 0.0f;
    lastPlayerPosy = 0.0f;
    xRot = 0.0f;
    yRot = 0.0f;
    rotationNum = 1.0f;

  }
  void cameraUpdate(int x, int y);
  void cameraStrafe();
  void enableScene();
  void displayCamera();
  void CameraSet();
  void mouseMovementCapture(int x, int y);
  void WidowSetting();
  void thirdPerson();
  void spotLight();


  bool strafeLeft,strafeRight,moveForward,moveBackward,mouseInScreen,firstPersonCam,thirdPersonCam;
  Vec3 camEye;
  Vec3 camCentre;
  Vec3 camUp;
  Vec3 camCoor;

  float angle,playerXpos,playerYpos,playerZpos,lastPlayerPosx,lastPlayerPosy,xRot,yRot,rotationNum;



private:
};







#endif
