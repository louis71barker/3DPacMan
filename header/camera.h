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
/// - This is the class that controls everything to do with the player camera.
/// - It is where the player movement is calculated and sorted.
/// - Player collisions are also calculated here.
/// - The spawning of the player location is also located here.
///
/// @todo
/// - Move the collision workings into the player class.
/// - Get collisions to work so the player is able to slide along all surfaces rather then the grabbing method.
/// - Make it so that when the mouse pointer hits the screen bourdary, it resets to allow for the camera to rotate
/// freely
//------------------------------------------------------------------------------------------------------------------
class Camera
{
public:
  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// - Within the constructor of this Camera class, all the dephault values for the bool's and floats are given to all
  /// the variables used within the class
  //------------------------------------------------------------------------------------------------------------------
  Camera()
  {
    m_strafeLeft = false;
    m_strafeRight = false;
    m_moveForward = false;
    m_moveBackward = false;
    m_playerSet = false;
    m_playerXpos = 0.0f;
    m_playerZpos = 0.0f;
    m_lastPlayerPosx = 0.0f;
    m_lastPlayerPosy = 0.0f;
    m_xRot = 0.0f;
    m_yRot = 0.0f;
    m_diffx = 0.0f;
    m_diffy = 0.0f;
    m_oldxPos = 0.0f;
    m_oldzPos = 0.0f;
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
  bool m_strafeLeft, m_strafeRight, m_moveForward, m_moveBackward;

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// playerSet - This is a bool that is set when the player has been placed at the spawn location so the game is able to
  /// start properly.
  //------------------------------------------------------------------------------------------------------------------
  bool m_playerSet;

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// mouseInScreen - This is a bool to test if the mouse is within the screen so that the mouse cursor is able to be hidden
  /// so that it doesnt interfere with the game.
  //------------------------------------------------------------------------------------------------------------------
  bool m_mouseInScreen;

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// playerXpos - This is the coordinates for the player on the X axis. These are the values that are changed to move the
  /// player around the map.
  /// @brief
  /// playerZpos - This is the coordinates for the player on the Z axis. These are the values that are changed to move the
  /// player around the map.
  //------------------------------------------------------------------------------------------------------------------
  float m_playerXpos,m_playerZpos;

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// lastPlayerPosx - This is the last position of the mouse pointer before the current position, this is used to calculate
  /// the amount of rotation is needed with the camera so it follows the mouse accordingly on the x axis.
  /// @brief
  /// lastPlayerPosy - This is the last position of the mouse pointer before the current position, this is used to calculate
  /// the amount of rotation is needed with the camera so it follows the mouse accordingly on the y axis.
  //------------------------------------------------------------------------------------------------------------------
  float m_lastPlayerPosx,m_lastPlayerPosy;

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// xRot - This is the value that is applied to the rotation of the camera to allow the camera to rotate along with
  /// the mouse on the x axis
  /// @brief
  /// yRot - This is the value that is applied to the rotation of the camera to allow the camera to rotate along with
  /// the mouse on the y axis
  //------------------------------------------------------------------------------------------------------------------
  float m_xRot,m_yRot;

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// diffx - This is the value of the difference between the lastPlayerPosx and the current x value of the mouse.
  /// @brief
  /// diffy - This is the value of the difference between the lastPlayerPosy and the current y value of the mouse.
  //------------------------------------------------------------------------------------------------------------------
  float m_diffx,m_diffy;

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// oldxPos - This is the last location of the player inside of the game. This is used for the collisions by setting
  /// the playerXpos back to this positions once a collision has occured.
  /// @brief
  /// oldzPos - This is the last location of the player inside of the game. This is used for the collisions by setting
  /// the playerZpos back to this positions once a collision has occured.
  //------------------------------------------------------------------------------------------------------------------
  float m_oldxPos,m_oldzPos;

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// cameraUpdate - This is the function that is called within the main which is used to apply the update to the
  /// camera each frame. It also tests to see if the player is set before it allows the player to be able to move
  /// @param
  /// m_matrix - This is passed in so that the player is able to spawn in the correct locations that is allocated
  /// in the map matrix
  /// @param
  /// m_x - This is the value that is passed in from the main which hold the current x position of the mouse on the
  /// screen. This is what is used to calculate the rotation needed for the camera
  /// @param
  /// m_y - This is the value that is passed in from the main which holds the current y position of the mouse pointer
  /// on the screen. This is what is used to calculate the rotation needed for the camera to work.
  ///
  ///
  //------------------------------------------------------------------------------------------------------------------
  void cameraUpdate(std::vector<std::vector<int> > m_matrix, int m_x, int m_y);



private:
  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// cameraStrafe - This is the function that is used to detect when the camera needs to move around the map as the
  /// player. If either 'a','w','s','d' is pressed this this is triggered to to move the player accordingly
  /// @param
  /// m_matrix - This is passed in to so it can be passed to the collison detection system to make sure that the
  /// player isnt colliding with any areas of the grid they are not supposed to.
  //------------------------------------------------------------------------------------------------------------------
  void cameraStrafe(const std::vector<std::vector<int> > &m_matrix);

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// enableSpotLight - This is the function that turns on the spot light and sets it location. There are three
  /// seperate lights that are used in the function to give the torch effect
  //------------------------------------------------------------------------------------------------------------------
  void enableSpotLight();

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// displayCamera - This is the function that is used to show the spot light in the camera on the screen. It is also
  /// used to make sure that when the rotation value reachs 360 or 0, they are reset back to their opposites
  //------------------------------------------------------------------------------------------------------------------
  void displayCamera();

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// CameraSet - This is were the rotation to the camera is implemented and applied to the glmatrix so allow for the
  /// camera to rotate properly
  //------------------------------------------------------------------------------------------------------------------
  void CameraSet();

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// mouseMovementCapture - This is the function that takes in the movement of the mouse and actually calculates and
  /// rotates the camera according to the mouse movement and position.
  /// @param
  /// _x - This is the mouse x value that is passed in to update the camera rotation
  /// @param
  /// _y - This is the mouse y value that is passed in to update the camera rotation
  //------------------------------------------------------------------------------------------------------------------
  void mouseMovementCapture(const int _x, const int _y);

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// playerCollisions - This is the function that deals with the collisions of the player(camera) with objects within
  /// the game that are not able to be passed through such as the exterior fence and the maze walls.
  /// @param
  /// m_matrix - This is the map matrix that is passed in so the collisions are able to be calculated for all the
  /// areas of the map that the player is unable to go. This is all defined in this matrix
  //------------------------------------------------------------------------------------------------------------------
  void playerCollisions(const std::vector<std::vector<int> > &m_matrix);

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// setPlayer - This is the simple function that finds the spawn location within the game maze and moves the player
  /// position to this location at the start of the game
  /// @param
  /// m_matrix - This is the map maze that is brought in to allow for the player spawn location to be located
  //------------------------------------------------------------------------------------------------------------------
  void setPlayer(const std::vector<std::vector<int> > &m_matrix);

};







#endif
