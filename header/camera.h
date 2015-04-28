#ifndef CAMERA_H__
#define CAMERA_H__
#include <math.h>
#include "header/scene.h"
#include <vector>
#include "walls.h"



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
    playerMoveing = true;
    xTrue = false;
    zTrue = false;
    playerSet = false;


    angle = 0.0f;
    playerXpos = 0.0f;
    playerYpos = 0.0f;
    playerZpos = 0.0f;
    lastPlayerPosx = 0.0f;
    lastPlayerPosy = 0.0f;
    xRot = 0.0f;
    yRot = 0.0f;
    rotationNum = 1.0f;
    xInvEntry = 0.0f;
    yInvEntry = 0.0f;
    xInvExit = 0.0f;
    yInvExit = 0.0f;
    diffx = 0.0f;
    diffy = 0.0f;
    xEntry = 0.0f;
    yEntry = 0.0f;
    xExit = 0.0f;
    yExit = 0.0f;
    entryTime = 0.0f;
    exitTime = 0.0f;
    oldxPos = 0.0f;
    oldzPos = 0.0f;



  }
  void cameraUpdate(std::vector<std::vector<int> > matrix, int x, int y);

  bool strafeLeft,strafeRight,moveForward,moveBackward,mouseInScreen,firstPersonCam,thirdPersonCam, playerMoveing, xTrue, zTrue;

  Vec3 camEye;
  Vec3 camCentre;
  Vec3 camUp;
  Vec3 camCoor;

  float playerSet,angle,playerXpos,playerYpos,playerZpos,lastPlayerPosx,lastPlayerPosy,xRot,yRot,rotationNum,xInvEntry,yInvEntry,xInvExit,yInvExit,diffx,diffy,xEntry,yEntry,xExit,yExit,entryTime,exitTime,oldxPos,oldzPos;



private:
    void collisionDistance(float cubeX, float cubeZ);
    void cameraStrafe();
    void enableScene();
    void displayCamera();
    void CameraSet();
    void mouseMovementCapture(int x, int y);
    void WidowSetting();
    void thirdPerson();
    void spotLight();
    void playerCollisions(const std::vector<std::vector<int> > matrix);
    void detectingNormals(float cubeXcentre, float cubeZcentre);
    void setPlayer(const std::vector<std::vector<int> > _matrix);

};







#endif
