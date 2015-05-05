//------------------------------------------------------------------------------------------------------------------
/// INCLUDE GUARD CHANGE TO NAME OF FILE BELOW
//------------------------------------------------------------------------------------------------------------------
#ifndef WALLS_H__
#define WALLS_H__

//------------------------------------------------------------------------------------------------------------------
///Here are all the includes that are needed
//------------------------------------------------------------------------------------------------------------------
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <boost/tokenizer.hpp>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <GL/gl.h>
#include "scene.h"


//------------------------------------------------------------------------------------------------------------------
/// Louis Barker
/// Version 1.0
/// 04/05/2015
//------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------
/// @brief
/// The Walls class
/// This class is where all the walls or the maze are built and drawn depending on where they are defined in the map
/// matrix
//------------------------------------------------------------------------------------------------------------------
class Walls
{
public:
  Walls();
  ~Walls()
  {
    //------------------------------------------------------------------------------------------------------------------
    /// \Here are all the functions to clean and clear all the Vectors used through the .clear function
    //------------------------------------------------------------------------------------------------------------------
    m_Vertex.clear();
    std::vector<Vec3>().swap (m_Vertex);
    m_Normal.clear();
    std::vector<Vec3>().swap (m_Normal);
    m_Texture.clear();
    std::vector<Vec3>().swap (m_Texture);
    m_dList.clear();
    std::vector<GLuint>().swap (m_dList);
    m_Index.clear();
    std::vector<int>().swap (m_Index);
  }

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// initMaze - This function textures the object
  /// Once the obj had been built and assained correctly from the obj file, it is passed into the displayList to
  /// be drawn.
  /// @param
  /// m_matrix - This it the map matrix which is passed in so that the barn can be placed in the correct location
  //------------------------------------------------------------------------------------------------------------------
  void initMaze(std::vector<std::vector<int> > &m_matrix);

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// draw - This function is a simple function that just has the call to the display list to display everything in
  /// the walls display list
  //------------------------------------------------------------------------------------------------------------------
  void draw();

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// m_matrix - This is the matrix that all the the map data is stored into
  //------------------------------------------------------------------------------------------------------------------
  std::vector< std::vector<int> > m_matrix;








private:

  //------------------------------------------------------------------------------------------------------------------
  /// \These are used to store the coordinate information of the objects that will be drawn in the game
  /// \These are before the constuctor and destructor as they are used in both.
  /// @m_Vertex is used to store the vertex coordinates of the Object file.
  /// @m_Normal is used to store the normal values from the object file.
  /// @m_Texture is used to store the texture coordinates of the object.
  /// @m_Index is used to store the list in which to join the vertex, normals and textures coordinates together.
  /// @m_dList is the list which is used to actually draw the object onto the screen
  //------------------------------------------------------------------------------------------------------------------
  std::vector<Vec3> m_Vertex;
  std::vector<Vec3> m_Normal;
  std::vector<Vec3> m_Texture;
  std::vector<int> m_Index;
  std::vector <GLuint> m_dList;

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// letsDraw - This function is used to move the walls around the map to the allocated places in the matrix
  /// @param
  /// _x - This is the value of 'i' in the buildGhost function so save having to have another two for loops
  /// @param
  /// _y - This is the value of 'j' in the buildGhost function so save having to have another two for loops
  /// @param
  /// m_matrix - This is passed in to allow for the location of the walls to be found and then moved.
  //------------------------------------------------------------------------------------------------------------------
  void letsDraw(const int _x, const int _y, const std::vector<std::vector<int> > &m_matrix);

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// drawCube - This is the function that is used to build the obj file so that it is able to be drawn
  /// @param
  /// m_matrix - This is passed in to allow for value to be found in the matrix so it is drawn in the relevent
  /// location
  //------------------------------------------------------------------------------------------------------------------
  void drawCube();

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// This is the texture id that is used for the texturing of the object
  //------------------------------------------------------------------------------------------------------------------
  GLuint m_WallTextID;
};



#endif
