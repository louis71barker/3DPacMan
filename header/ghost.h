//------------------------------------------------------------------------------------------------------------------
/// INCLUDE GUARD CHANGE TO NAME OF FILE BELOW
//------------------------------------------------------------------------------------------------------------------
#ifndef GHOST_H__
#define GHOST_H__

//------------------------------------------------------------------------------------------------------------------
///Here are all the includes that are needed
//------------------------------------------------------------------------------------------------------------------
#include <boost/random.hpp>
#include <fstream>
#include "scene.h"
#include <vector>
#include <stdlib.h>
#include <iostream>

#ifdef LINUX
  #include <GL/gl.h>
#endif
#ifdef DARWIN
  #include <OpenGL/gl.h>
#endif

//------------------------------------------------------------------------------------------------------------------
/// \Louis Barker
/// \Version 1.0
/// 04/05/2015
//------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------
/// @brief
/// The Ghost class
/// This class is used to draw the ghost onto the screen and place the, in the correct locations.
///
/// @todo
/// make the ghost AI work properly
///
//------------------------------------------------------------------------------------------------------------------
class Ghost
{
public:
  void updater(const std::vector<std::vector<int> > &m_matrix);
  void drawGhosts(const std::vector<std::vector<int> > &m_matrix);

  //------------------------------------------------------------------------------------------------------------------
  /// \These are used to store the coordinate information of the objects that will be drawn in the game
  /// \These are before the constuctor and destructor as they are used in both.
  /// @m_Vertex is used to store the vertex coordinates of the Object file.
  /// @m_Normal is used to store the normal values from the object file.
  /// @m_Texture is used to store the texture coordinates of the object.
  /// @m_Index is used to store the list in which to join the vertex, normals and textures coordinates together.
  /// @m_displayList is the list which is used to actually draw the object onto the screen
  //------------------------------------------------------------------------------------------------------------------
  std::vector<Vec3> m_Vertex;
  std::vector<Vec3> m_Normal;
  std::vector<Vec3> m_Texture;
  std::vector<int> m_Index;
  std::vector<GLuint> m_displayList;
  std::vector<Vec2> m_GhostPos;

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// Ghost
  /// In the constructor the Ghost object is loaded into the vectors. Once this is done, the object is then built into
  /// the display list and relocated to the location on the map that is is assainged. The direction values for the AI
  /// are then set to their dephault values
  /// @param
  /// m_matrix
  /// This is passed in as a reference to allow for the location of the fence to be found and then moved.
  //------------------------------------------------------------------------------------------------------------------
  Ghost(const std::vector<std::vector<int> > &m_matrix) : m_ghostX(0), m_ghostZ(0)
  {
    //------------------------------------------------------------------------------------------------------------------
    /// @brief
    /// Here is a call the the OBJLoader class which loads the obj files data into the relivent vectors
    //------------------------------------------------------------------------------------------------------------------
    ObjLoader("obj/GhostObj.obj",m_Vertex,m_Normal,m_Texture,m_Index);

    //------------------------------------------------------------------------------------------------------------------
    /// @brief
    /// Here the ground is built and added to the display list so it can be drawn
    //------------------------------------------------------------------------------------------------------------------
    buildGhost(m_matrix);
    m_North = false;
    m_South = false;
    m_East = false;
    m_West = true;
  }
  ~Ghost()
  {
    //------------------------------------------------------------------------------------------------------------------
    /// @brief
    /// ~Ghost - Here are all the functions to clean and clear all the Vectors used through the .clear function
    //------------------------------------------------------------------------------------------------------------------
    m_Vertex.clear();
    std::vector<Vec3>().swap (m_Vertex);
    m_Normal.clear();
    std::vector<Vec3>().swap (m_Normal);
    m_Texture.clear();
    std::vector<Vec3>().swap (m_Texture);
    m_displayList.clear();
    std::vector<GLuint>().swap (m_displayList);
    m_Index.clear();
    std::vector<int>().swap (m_Index);
    m_GhostPos.clear();
    std::vector<Vec2>().swap (m_GhostPos);
  }


private:
  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// ghostX - this is the position of the ghost on the X axis which is used for the AI
  /// @brief
  /// ghostZ - this is the position of the ghost on the Z axis which is used for the AI
  //------------------------------------------------------------------------------------------------------------------
  float m_ghostX, m_ghostZ;

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// North - This is used for the AI to determine which direction the AI is currently going through the maze
  /// @brief
  /// South - This is used for the AI to determine which direction the AI is currently going through the maze
  /// @brief
  /// East - This is used for the AI to determine which direction the AI is currently going through the maze
  /// @brief
  /// West - This is used for the AI to determine which direction the AI is currently going through the maze
  //------------------------------------------------------------------------------------------------------------------
  bool m_North, m_South, m_East, m_West;

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// ghoAi - This function is where the ghost AI is located
  /// @param
  /// m_matrix - This it the map matrix which is passed in so that the ghost is able to find out where it currently is
  //------------------------------------------------------------------------------------------------------------------
  void ghoAi(const std::vector<std::vector<int> > &m_matrix);

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// buildGhost - This is the function that is used to build the obj file so that it is able to be drawn
  /// This function also textures the object
  /// Once the obj had been build and assained correctly from the obj file, it is passed into the displayList to
  /// be drawn
  /// @param
  /// m_matrix - This it the map matrix which is passed in so that the ghost is able to find out where it needs to be
  /// placed
  //------------------------------------------------------------------------------------------------------------------
  void buildGhost(const std::vector<std::vector<int> > &m_matrix);

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// setGhost - This function is used set the ghost position on the map depending on where they are defined in the
  /// map matrix. It also scales the ghost down and sets the Ghost x and z values to there positions
  /// @param
  /// _a - This is the value of 'i' in the buildGhost function so save having to have another two for loops
  /// @param
  /// _b - This is the value of 'j' in the buildGhost function so save having to have another two for loops
  /// @param
  /// m_matrix - This it the map matrix which is passed in so that the ghosts can be placed in the correct location
  //------------------------------------------------------------------------------------------------------------------
  void setGhost(const int _a, const int _b,const std::vector<std::vector<int> > &m_matrix);

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// dirValSetter - This function is a simple function that is used to set the direction of the ghost depending on
  /// the navigation type true.
  //------------------------------------------------------------------------------------------------------------------
  void dirValSetter();








};





#endif
