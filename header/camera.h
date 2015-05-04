/// INCLUDE GUARD CHANGE TO NAME OF FILE BELOW
#ifndef CAMERA_H__
#define CAMERA_H__

///Here are all the includes that are needed
#include <math.h>
#include "header/scene.h"
#include <vector>
#include "walls.h"

#ifndef M_PI
#define M_PI 3.141592654
#endif

/// \Louis Barker
/// \Version 1.0
/// 04/05/2015

//------------------------------------------------------------------------------------------------------------------
/// @brief
/// The Camera class
/// This is the class that controls everything to do with the player camera.
/// It is where the player movement is calculated and sorted.
/// Player collisions are also calculated here.
/// The spawning of the player location is also located here.
///
/// @todo
/// Move the collision workings into the player class.
/// Get collisions to work so the player is able to slide along all surfaces rather then the grabbing method.
//------------------------------------------------------------------------------------------------------------------
class Camera
{
public:
  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// Within the constructor of this Camera class, all the dephault values for the bool's and floats are given to all
  /// the variables used within the class
  //------------------------------------------------------------------------------------------------------------------
  Camera()
  {
    strafeLeft = false;
    strafeRight = false;
    moveForward = false;
    moveBackward = false;
    playerSet = false;
    playerXpos = 0.0f;
    playerZpos = 0.0f;
    lastPlayerPosx = 0.0f;
    lastPlayerPosy = 0.0f;
    xRot = 0.0f;
    yRot = 0.0f;
    diffx = 0.0f;
    diffy = 0.0f;
    oldxPos = 0.0f;
    oldzPos = 0.0f;
  }
  ~Camera() {}

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// strafeLeft is a bool that is used to state that the 'a' key is pressed so the player needs to be moveing left.
  /// @brief
  /// strafeRight is a bool that is used to say state the 'd' key is pressed to indecate that the player needs to move
  /// right.
  /// @brief
  /// moveForward is a bool that is used to state that the 'w' key is pressed so the player needs to move forward.
  /// @brief
  /// moveBackward is a bool that is used to state that the 's' key is pressed so the player needs to move backwards.
  //------------------------------------------------------------------------------------------------------------------
  bool strafeLeft,strafeRight,moveForward,moveBackward;

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// playerSet is a bool that is set when the player has been placed at the spawn location so the game is able to
  /// start properly.
  //------------------------------------------------------------------------------------------------------------------
  bool playerSet;

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// mouseInScreen is a bool to test if the mouse is within the screen so that the mouse cursor is able to be hidden
  /// so that it doesnt interfere with the game.
  //------------------------------------------------------------------------------------------------------------------
  bool mouseInScreen;

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// playerXpos is the coordinates for the player on the X axis. These are the values that are changed to move the
  /// player around the map.
  /// @brief
  /// playerZpos is the coordinates for the player on the Z axis. These are the values that are changed to move the
  /// player around the map.
  //------------------------------------------------------------------------------------------------------------------
  float playerXpos,playerZpos;

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// lastPlayerPosx is the last position of the player before the current
  //------------------------------------------------------------------------------------------------------------------
  float lastPlayerPosx,lastPlayerPosy;

  //------------------------------------------------------------------------------------------------------------------
  /// \brief xRot
  //------------------------------------------------------------------------------------------------------------------
  float xRot,yRot;

  //------------------------------------------------------------------------------------------------------------------
  /// \brief diffx
  //------------------------------------------------------------------------------------------------------------------
  float diffx,diffy;

  //------------------------------------------------------------------------------------------------------------------
  /// \brief oldxPos
  //------------------------------------------------------------------------------------------------------------------
  float oldxPos,oldzPos;

  //------------------------------------------------------------------------------------------------------------------
  /// \brief cameraUpdate
  /// \param matrix
  /// \param x
  /// \param y
  //------------------------------------------------------------------------------------------------------------------
  void cameraUpdate(std::vector<std::vector<int> > matrix, int x, int y);



private:
    void collisionDistance(float cubeX, float cubeZ);
    void cameraStrafe(const std::vector<std::vector<int> > &m_matrix);
    void enableScene();
    void displayCamera();
    void CameraSet();
    void mouseMovementCapture(int x, int y);
    void WidowSetting();
    void spotLight();
    void playerCollisions(const std::vector<std::vector<int> > &m_matrix);
    void detectingNormals(float m_cubeXcentre, float m_cubeZcentre);
    void setPlayer(const std::vector<std::vector<int> > &_matrix);

};







#endif
